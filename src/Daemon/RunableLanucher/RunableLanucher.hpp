#ifndef _RUNNABLE_LANUCHER
#define _RUNNABLE_LANUCHER

#include<string>
#include<algorithm>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<GetInfo.hpp>
using namespace std;

namespace Daemon{
	typedef struct Usage{
		int _timeUsage;//ms
		int _memUsage;//KB
		Usage(int timeUse,int memUse):_timeUsage(timeUse),_memUsage(memUse){};
	};
	class RunnableLanucher{
		private:
			string _runPath;
			string _inPath;
			string _outPath;
			struct Usage _resrc;
			struct timespec t16m,tres;
			int timeLimit=8000;//8sec
			int memLimit=32*1024;//32MB;
			bool isExecDone;
		public:
			RunnableLanucher(string runnablePath,string inputPath,string outputPath)\
:_runPath(runnablePath),_inPath(inputPath),_outPath(outputPath),_resrc(Usage(0,0)){
				t16m.tv_sec=0;
				t16m.tv_nsec=16000000;
				isExecDone=false;
	}
			
			Usage run(){
				pthread_t th1,th2;
				pthread_create(&th1,NULL,execThread,NULL);
				pthread_create(&th2,NULL,resrcThrad,NULL);
				pthread_join(th1,NULL);
				pthread_join(th2,NULL);
			}
			void* execThread(){
				isExecDone=false;
				system(_runPath+" <"_inPath+" >"+_outPath);
				isExecDone=true;
			}
			void* resrcThread(){
				int tCnt=0;
				int vmSize=0;
				int tmpSize=0;
				while(!isExecDone){
					if(tCnt>200){
						cout<<"TLE ie. extends 8secs!"<<endl;
					}
					if((tmpSize=get_proc_status(getpid(),"VmSize"))>memLimit){
						cout<<"MLE ie. extends 32MB!"<<endl;
					}
					if(vmSize<tmpSize)vmSize=tmpSize;
					nanosleep(&t16m,&tres);
				}
				cout<<"Time Usage is "<<16*tCnt<<"ms"<<endl;
				cout<<"Mem Usage is "<<vmSize<<"KB"<<endl;
			}
			
	};//end of class RunanbleLanucher

}//end of namespace Daemon

#endif
