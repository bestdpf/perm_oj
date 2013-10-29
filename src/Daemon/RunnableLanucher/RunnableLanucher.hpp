#ifndef _RUNNABLE_LANUCHER
#define _RUNNABLE_LANUCHER

#include<string>
//#include<algorithm>
#include<boost/thread.hpp>
#include<ctime>
#include<cstdlib>
#include"GetInfo.hpp"
#include<unistd.h>
using namespace std;
using namespace boost;
namespace Daemon{
	struct Usage{
		int _timeUsage;//ms
		int _memUsage;//KB
		int _re;//RE, 0 is succ, 1 is RE
		int _tle;//TLE, 0 is succ ,1 is TLE
		int _mle;//MLE, 0 is succ ,1 is TLE
		Usage(int timeUse=8000,int memUse=32*1024,int re=0,int tle=0,int mle=0):_timeUsage(timeUse),_memUsage(memUse),_re(re),_tle(tle),_mle(mle){};
	};
	class RunnableLanucher{
		private:
			string _runPath;
			string _inPath;
			string _outPath;
			struct Usage _resrc;
			struct timespec t16m,tres;
			int timeLimit;//8sec
			int memLimit;//32MB;
			bool isExecDone;
		public:
			RunnableLanucher(string runnablePath,string inputPath,string outputPath){
				_runPath=runnablePath;
				_inPath=inputPath;
				_outPath=outputPath;
				_resrc=Usage(0,0);
				t16m.tv_sec=0;
				t16m.tv_nsec=16000000;
				isExecDone=false;
				timeLimit=8000;
				memLimit=32*1024;
	}
			
			Usage run(){
				thread_group tg;
				thread *th1,*th2;
				th1=new thread(bind(&RunnableLanucher::execThread,this));
				th2=new thread(bind(&RunnableLanucher::resrcThread,this));
				tg.add_thread(th1);
				tg.add_thread(th2);
				tg.join_all();
				return _resrc;
			}
			void execThread(){
				isExecDone=false;
				string cmd=_runPath+" <"+_inPath+" >"+_outPath;
			//	FILE* fin=popen(cmd.c_str(),"r");
				int sysret=std::system(cmd.c_str());
				if(sysret!=0){
					_resrc._re=1;
					cerr<<"RE!!!"<<endl;
				}
				isExecDone=true;
			}
			void resrcThread(){
				int tCnt=0;
				int vmSize=0;
				int tmpSize=0;
				while(!isExecDone){
					if(tCnt>500){
						_resrc._tle=1;
						cout<<"TLE ie. extends 8secs!"<<endl;
						break;
					}
					tmpSize=get_proc_status(getpid(),"VmHWM");
					if(vmSize<tmpSize)vmSize=tmpSize;
					if((tmpSize)>memLimit){
						_resrc._mle=1;
						cout<<"MLE ie. extends 32MB!"<<endl;
						break;
					}
					nanosleep(&t16m,&tres);
					tCnt++;
				}
				cout<<"Time Usage is "<<16*tCnt<<"ms"<<endl;
				cout<<"Mem Usage is "<<vmSize<<"KB"<<endl;
				//_resrc=Usage(16*tCnt,vmSize);
				_resrc._timeUsage=16*tCnt;
				_resrc._memUsage=vmSize;
				isExecDone=false;
			}
			
	};//end of class RunanbleLanucher

}//end of namespace Daemon

#endif
