#ifndef _PLAIN_JUDGER
#define _PLAIN_JUDGER
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>
#include"NewJudger.hpp"
#ifdef _N
#undef _N
#endif

#define _N 100000000
#define _M 15
using namespace std;
namespace Daemon{
	class PlainJudger{
		private:
			int len;
			bool mask[_M];
			bool vis [_N];
			int reverse[_M];
			unsigned long long int factorial[_M];
			string data;
			struct JudgeInfo ji;
		public:
			int idx(char c){return c-'a';}
			PlainJudger(int l,string outdata){
				len=l;
				data=outdata;
				ji.correct=0;
				ji.err_type=0;
				factorial[0]=1;
				int i;
				for(i=1;i<=len;i++)factorial[i]=factorial[i-1]*i;
			}
			JudgeInfo getRet(){
				return ji;
			}
			unsigned int getHash(char* str){
				int ret=0;
				memset(reverse,0,sizeof(reverse));
				int i;
				for(i=0;i<len-1;i++){
					int j;
					for(j=i+1;j<len;j++)if(str[i]>str[j])reverse[i]++;
					ret+=factorial[len-1-i]*reverse[i];
				}
				return ret;
			}
			void run(){
				#if _DEBUG
				cout<<"Running Judge now"<<endl;
				clock_t begin,end;
				double time_spent;
				begin=clock();
				#endif
				memset(vis,0,sizeof(vis));
				char str[_M+5];
				FILE* fr=fopen(data.c_str(),"r");
				unsigned long long int line=0;
				while(fscanf(fr,"%s",str)!=EOF){
					line++;
					int slen=strlen(str);
					if(slen!=len){
						ji.correct=1;
						ji.err_type=3;
						#if _DEBUG
						cout<<line<<" :err type 3"<<endl;
						#endif 
						return;
					}
					memset(mask,0,sizeof(mask));
					int i;
					for(i=0;i<len;i++){
						int v=idx(str[i]);
						if(v<0||v>=len){
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<line<<" :err type 3"<<endl;
							#endif
							return;
						}
						else if(mask[v]){
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<line<<" :err type 3"<<endl;
							#endif
							return;
						}
						else mask[v]=true;
					}
					unsigned int hs=getHash(str);
					if(vis[hs]){
						ji.correct=1;
						ji.err_type=2;
						#if _DEBUG
						cout<<line<<" :err type 2"<<endl;
						#endif
						return;
					}
					else vis[hs]=true;
				}
				if(line==factorial[len]){
						ji.correct=0;
						ji.err_type=0;
						#if _DEBUG
						cout<<"no err"<<endl;
						#endif
				}
				else{
					ji.correct=1;
					ji.err_type=1;
					#if _DEBUG
					cout<<line<<" :err type 1"<<endl;
					#endif	
				}
				#if _DEBUG
				end=clock();
				time_spent=(end-begin)*1000/CLOCKS_PER_SEC;
				cout<<"Juger time is "<<time_spent<<endl;
				#endif
				return;
			}
	};//end of class PlainJudger
}//end of Daemon namespace
#endif
