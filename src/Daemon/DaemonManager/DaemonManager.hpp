#ifndef _DAEMON_MANAGER
#define _DAEMON_MANAGER

#include<iostream>
#include<../RunnableLanucher.hpp>
#include<boost/shared_ptr>
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
			const string gcc_compiler="g++";
			const string gcc_options="-lm -DONLINE_JUDGE"
		public:
			DaemonManager(){
				_runLanu=NULL;
				_res=Usage(0,0);
				retVal=0;
			}
			int compile(string compiler,string compilerOptions){
				int compileStatus=system((compiler+" "+compilerOptions).c_str());	
				if(compileStatus==0){
					cerr<<"Compile error!"<<endl;
				}
				return compileStatus;
			}
			void addRunnbleLanucher(string run,string inData,string outData){
				_runLanu=new RunnableLanucher(run,inData,outData);
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
