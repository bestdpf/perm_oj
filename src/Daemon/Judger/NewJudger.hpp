#ifndef _JUDGER
#define _JUDGER
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>

#define _N 10000000
#define _M 15
using namespace std;
namespace Daemon{
	struct JudgeInfo{
		int correct;//0 is correct,1 is not
		int err_type;//0 is no err, 1 is less, 2 is duplicate, 3 is err perm
		JudgeInfo(){
			correct=0;
			err_type=0;
		}
	};
	class NewJudger{
		private:
			int len;
			int sz;
			int ch[_N][_M];
			bool mask[_M];
			bool vis[_N];
			unsigned long long int factorial[_M];
			string data;
			struct JudgeInfo ji;
		public:
			int idx(char c){return c-'a';}
			NewJudger(int l,string outdata){
				len=l;
				data=outdata;
				ji.correct=0;
				ji.err_type=0;
				factorial[0]=1;
				int i;
				for(i=1;i<=len;i++)factorial[i]=factorial[i-1]*i;
				buildTrie();
			}
			void buildTrie(){
				sz=1;
				memset(mask,0,sizeof(mask));
				buildTrie(0);
			}
			void buildTrie(int root){
				memset(ch[root],0,sizeof(ch[root]));
				int i;
				for(i=0;i<len;i++)if(!mask[i]){
					mask[i]=true;
					ch[root][i]=sz++;
					buildTrie(ch[root][i]);
					mask[i]=false;
				}
			}
			JudgeInfo getRet(){
				return ji;
			}
			void run(){
				#if _DEBUG
				cout<<"Running Judge now"<<endl;
				#endif
				memset(vis,0,sizeof(vis));
				char str[_M+5];
				FILE* fr=fopen(data.c_str(),"r");
				unsigned long long int line=0;
				while(fscanf(fr,"%s",str)!=EOF){
					line++;
					int i,r=0;
					for(i=0;i<len;i++){
						if(idx(str[i])<0||idx(str[i])>len-1){
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<"err type 3"<<endl;
							#endif
							return ;
						}
						int v=ch[r][idx(str[i])];
						if(!v){
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<"err type 3"<<endl;
							#endif
							return;
						}
						r=v;
					}
					if(vis[r]){
						ji.correct=1;
						ji.err_type=2;
						#if _DEBUG
						cout<<"err type 2"<<endl;
						#endif
						return;
					}
					else vis[r]=true;
				}
				if(factorial[len]==line){
					ji.correct=0;
					ji.err_type=0;
				}
				else{
					ji.correct=1;
					ji.err_type=1;
					#if _DEBUG
					cout<<"err type 1"<<endl;
					#endif
				}
			}//end of class Judger
	};
}//end of Daemon namespace
#endif
