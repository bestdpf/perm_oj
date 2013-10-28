#ifndef _JUDGER
#define _JUDGER
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
namespace Daemon{
	struct JudgeInfo{
		int correct;//0 is correct,1 is not
		int err_type;//0 is no err, 1 is less, 2 is duplicate
	};
	class Judger{
		private:
			string data;
			struct JudgeInfo ji;
		public:
			Judger(string outdata){
				data=outdata;
				ji.correct=0;
				ji.err_type=0;
			}
			JudgeInfo getRet(){
				return ji;
			}
			void run(){
				#if _DEBUG
				cout<<"Running Judge now"<<endl;
				#endif
			}//end of class Judger
	};
}//end of Daemon namespace
#endif
