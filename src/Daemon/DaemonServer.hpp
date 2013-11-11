#ifndef _DAEMON_SERVER
#define _DAEMON_SERVER
#include<iostream>
#include"DaemonManager/DaemonManager.hpp"
#include"Network/ResponseHandler.hpp"
#include"Network/RequestHandler.hpp"
#include"Network/XMLHandler.hpp"
#include"Judger/NewJudger.hpp"
#include"boost/thread.hpp"
#include"boost/shared_ptr.hpp"
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<string>

using namespace std;
using namespace pugi;
using namespace boost;

namespace Daemon{
	struct JudgeRet{
		Usage usg;
		int compilecode;
		int runid;
		int inputtype;
		string outputpath;
		string sendxmlpath;
	};
	class DaemonServer{
		private:
			shared_ptr<DaemonManager>dm;
			shared_ptr<ResponseHandler> rh;
			shared_ptr<RequestHandler>rqh;
			shared_ptr<NewJudger>jer;
			struct timespec t100m,tres;
			int runid;
			string storepath;
			string fileprepath;
			string srcname;
			string runnablepath;
			string inputpath;
			string posturl;
			JudgeRet jr;
		public:
			DaemonServer(){
				dm=shared_ptr<DaemonManager>(new DaemonManager());
				rh=shared_ptr<ResponseHandler>(new ResponseHandler());
				//rqh=shared_ptr<RequestHandler>(new RequestHandler());
				t100m.tv_sec=0;
				t100m.tv_nsec=100000000;
				runnablepath=string("/home/duan/workplace/judge_runnable/");
				inputpath=string("/home/duan/workplace/judge_input/");
				//posturl=string("http://127.0.0.1/test/recv.php");
				posturl=string("http://127.0.0.1/Application/Home/Controller/recv.php");
			}
			void run(){
				thread_group tg;
				thread* th1,*th2;
				th1=new thread(bind(&DaemonServer::listenThread,this));
				th2=new thread(bind(&DaemonServer::judgeThread,this));
				tg.add_thread(th1);
				tg.add_thread(th2);
				tg.join_all();
			}
			void listenThread(){
				rh->startUp();
			}
			/*
			 **From  JudgeRet jr
			*/
			XMLHandler getSendXML(){
				XMLHandler xmlh;
				xml_node nd=xmlh.addChild("result",NULL);
				nd.append_child("runid").append_child(node_pcdata).set_value(to_string(jr.runid).c_str());
				nd.append_child("compilecode").append_child(node_pcdata).set_value(to_string(jr.compilecode).c_str());
				nd.append_child("inputtype").append_child(node_pcdata).set_value(to_string(jr.inputtype).c_str());
				nd.append_child("time").append_child(node_pcdata).set_value(to_string(jr.usg._timeUsage).c_str());
				nd.append_child("mem").append_child(node_pcdata).set_value(to_string(jr.usg._memUsage).c_str());
				nd.append_child("RE").append_child(node_pcdata).set_value(to_string(jr.usg._re).c_str());
				nd.append_child("TLE").append_child(node_pcdata).set_value(to_string(jr.usg._tle).c_str());
				nd.append_child("MLE").append_child(node_pcdata).set_value(to_string(jr.usg._mle).c_str());
				nd.append_child("outpath").append_child(node_pcdata).set_value((runnablepath+"1.out").c_str());
				JudgeInfo ji;
				if(jer!=NULL){
					ji=jer->getRet();
				}
				nd.append_child("judgercorrect").append_child(node_pcdata).set_value(to_string(ji.correct).c_str());
				nd.append_child("judgererrtype").append_child(node_pcdata).set_value(to_string(ji.err_type).c_str());
				#if _DEBUG
				cout<<"getSendXML ret"<<endl;
				xmlh.dump();
				#endif
				return xmlh;
			} 
			void judgeThread(){
				while(true){
					XMLHandler xmlh;
					if(rh->getNextXML(xmlh)){
						xml_node xmlnd=xmlh.child("judge");
						runid=atoi(xmlnd.child_value("runid"));
						jr.runid=runid;
						storepath=string(xmlnd.child_value("storepath"));
						fileprepath=string(xmlnd.child_value("fileprepath"));
						srcname=string(xmlnd.child_value("srcname"));
						string fullpath=storepath+fileprepath+srcname;
						#ifdef _DEBUG
						cout<<"dump the xml recved by judge thread"<<endl;
						xmlh.dump();
						cout<<"compile src file parameters:"<<endl;
						cout<<"fullpath "<<fullpath<<endl;
						cout<<"runnablepath"<<runnablepath+"a.out"<<endl;
						#endif
						jr.compilecode=dm->compile("g++","-lm -DONLINE_JUDGE",fullpath,runnablepath+"a.out");
						if(jr.compilecode==0){//succ
							dm->addRunnableLanucher(runnablepath+"a.out",inputpath+"1.in",runnablepath+"1.out");
							jr.outputpath=runnablepath+"1.out";
							dm->run();
							jr.usg=dm->getRet();
							jr.inputtype=1;
							//run NewJudger below
							if(jr.usg._re==0&&jr.usg._tle==0&&jr.usg._mle==0){
								jer=shared_ptr<NewJudger>(new NewJudger(3,runnablepath+"1.out"));
								jer->run();
							}
						}
						else jr.inputtype=0;
							
						XMLHandler xmlsend(getSendXML());
						#if _DEBUG
						cout<<"but final got send xml is "<<endl;
						xmlsend.dump();
						#endif
						jr.sendxmlpath=runnablepath+"ret"+to_string(runid)+".xml";
						xmlsend.saveFile(jr.sendxmlpath.c_str());
						rqh=shared_ptr<RequestHandler>(new RequestHandler());
						rqh->sendFile(jr.sendxmlpath.c_str(),posturl.c_str());
					}
					else{
						nanosleep(&t100m,&tres);
					}
				}
			}
	};//end of class DaemonServer
}//end of namespace Daemon
#endif
