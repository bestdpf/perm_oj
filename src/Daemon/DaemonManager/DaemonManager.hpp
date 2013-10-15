#ifndef _DAEMON_MANAGER
#define _DAEMON_MANAGER

#include<iostream>
#include"../RunnableLanucher/RunnableLanucher.hpp"
#include<boost/shared_ptr.hpp>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

using namespace std;
using namespace boost;
namespace Daemon{
	class DaemonManager{
		private:
			shared_ptr<RunnableLanucher> _runLanu;
			static Usage _res;
			int retVal;
			string gcc_compiler;
			string gcc_options;
		public:
			DaemonManager(){
				_runLanu=shared_ptr<RunnableLanucher>();
				_res=Usage(0,0);
				retVal=0;
				gcc_compiler="g++";
				gcc_options="-lm -DONLINE_JUDGE";
			}
			int compile(string compiler,string compilerOptions){
				int compileStatus=std::system((compiler+" "+compilerOptions).c_str());	
				if(compileStatus==0){
					cerr<<"Compile error!"<<endl;
				}
				return compileStatus;
			}
			void addRunnbleLanucher(string run,string inData,string outData){
				_runLanu=(shared_ptr<RunnableLanucher>)new RunnableLanucher(run,inData,outData);
			}
			void run(){
				if(_runLanu==NULL){
					cerr<<"Error Runnable Lanucher is not added!"<<endl;
				}
				else{
					_res=_runLanu->run();
					/*
					pid_t pid;
					pid= fork();
					if(pid==-1){
						cerr<<"Fork error!"<<endl;
					}
					else if(pid==0){
						_res=_runLanu->run();
					}
					else while(true){
						pid_t done=wait(&retVal);
						if(done==-1){
							if(errno==ECHILD)break;//no children
						}
						else{
							if(!WIFEXITED(retVal)||WEXITSTATUS(retVal)!=0){
								cerr<<"runnable is exit abnomorly!"
							}
							break;
						}
					}
				*/
				}
			}
		
	};//end of class DaemonManager
}//end of namespace Daemon

#endif
