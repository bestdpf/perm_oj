#ifndef _DYNAMIC_JUDGER
#define _DYNAMIC_JUDGER
#include<string>
#include<cstring>
#include<iostream>
#include<cstdio>
#include"NewJudger.hpp"
#define _M 15
using namespace std;
namespace Daemon{
	struct node{
		int n;
		node **chd;
		//bool vis;
		//node(int _n=0,node** _chd=NULL,bool _vis=false):n(_n),chd(_chd),vis(_vis){}
	};
	node *vis[1];
	class DynamicJudger{
		private:
			int len;
			int sz;
			struct node* root;
			bool mask[_M];
			unsigned long long int factorial[_M];
			string data;
			struct JudgeInfo ji;
		public:
			int idx(char c){return c-'a';}
			DynamicJudger(int l,string outdata){
				len=l;
				data=outdata;
				ji.correct=0;
				ji.err_type=0;
				factorial[0]=1;
				int i;
				for(i=1;i<=len;i++)factorial[i]=factorial[i-1]*i;
				buildTrie();
			}
			~DynamicJudger(){
				delTrie(root);
				delete root;
			}
		 	void delTrie(node* r){
				int i;
				for(i=0;i<r->n;i++)if(r->chd[i]!=NULL){
					delTrie(r->chd[i]);
					delete r->chd[i];
					r->chd[i]=NULL;
				}
			}
			void buildTrie(){
				memset(mask,0,sizeof(mask));
				root=new node(/*len+1,NULL*/);
				root->n=len+1;
				root->chd=NULL;
				sz=1;
				buildTrie(root);
			}
			void buildTrie(node* r){
				#if _DEBUG
				//cout<<"build Trie "<<r->n<<endl;
				#endif
				sz++;
				//if(sz%1000==0)cout<<"sz "<<sz<<endl;
				if(r->n>0)r->chd=new node*[r->n];
				//if(r->chd==NULL)cerr<<"error alloc"<<endl;
				int i,j;
				for(i=0,j=0;i<len;i++)if(!mask[i]){
					mask[i]=true;
					//r->chd[j]=new node(/*r->n-1,NULL*/);
					r->chd[j]=new node();
					r->chd[j]->n=r->n-1;
					r->chd[j]->chd=NULL;
					if(r->chd[j]==NULL)cerr<<"error alloc"<<endl;
					buildTrie(r->chd[j]);
					mask[i]=false;
					j++;
				}
			}
			JudgeInfo getRet(){
				return ji;
			}
			void run(){
				#if _DEBUG
				cout<<"Running Judge now"<<endl;
				clock_t begin,end;
				double time_spent;
				#endif
				char str[_M+5];
				FILE* fr=fopen(data.c_str(),"r");
				#if _DEBUG
				begin=clock();
				#endif
				unsigned long long int line=0;
				while(fscanf(fr,"%s",str)!=EOF){
					line++;
					if((int)strlen(str)!=len){
						ji.correct=1;
						ji.err_type=3;
						#if _DEBUG
						cout<<"err type 3"<<endl;
						#endif
						return ;
					}
					memset(mask,0,sizeof(mask));
					int i/*,j*/;
					node* r=root;
					for(i=0/*,j=0*/;i<len;i++){
						int nid=idx(str[i]);
						if(nid<0||nid>len-1){
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<"err type 3"<<endl;
							#endif
							return ;
						}
						int v=nid;
						int m;
						for(m=0;m<=nid;m++)if(mask[m])v--;
						if(v<0||mask[nid]){//or if mask[nid]=true;
							ji.correct=1;
							ji.err_type=3;
							#if _DEBUG
							cout<<"err type 3"<<endl;
							#endif
							return;
						}
						mask[nid]=true;
						r=r->chd[v];
						//j++;
					}
					if(r->chd==vis/*r->vis*/){
						ji.correct=1;
						ji.err_type=2;
						#if _DEBUG
						cout<<"err type 2"<<endl;
						cout<<"line is "<<line<<endl;
						cout<<"r->n is "<<r->n<<endl;
						cout<<"size is "<<sz<<endl;
						#endif
						return;
					}
					else r->chd=vis;
					//else r->vis=true;
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
				#if _DEBUG
				end=clock();
				time_spent=(end-begin)*1000/CLOCKS_PER_SEC;
				cout<<"Judger time spent "<<time_spent<<endl;
				#endif
			}//end of class Judger
	};
}//end of Daemon namespace
#endif
