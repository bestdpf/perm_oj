/**
1.排列元素用1、2、3......表示
2.单个全排列的长度不会超过MAX_NUM
3.ROOT所在的树的层数为0，即树是从零层开始
**/

#ifndef _JUDGER
#define _JUDGER
#define MAX_NUM 20
#include<string>
#include<cstring>
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
namespace Daemon{
	        struct JudgeInfo{
	                int correct;//1 is correct,0 is not
	                int err_count;//0 is no err, >0 is the error count
	        };

		struct Node{
			int num;
			union{
				int count;
				struct Node** ppNode;
			};	
		};

        	class Judger{
                	private:
				struct Node* ROOT;
				int N;
				int TOTAL;
				int FLAG[MAX_NUM];
                        	struct JudgeInfo ji;
                	public:
				 		Judger(int perm_num=3){
	        					N=perm_num;
							TOTAL=CalTotal(N);
							memset(FLAG,0,sizeof(int)*MAX_NUM);
							ROOT=(struct Node*)malloc(sizeof(struct Node));
							BuildTree(ROOT,0,0);
							//PrintPermutation(ROOT,0);
							//printf("%d\n",Judge("Test.txt"));
        					}

						int CalTotal(int N)
						{
							int total=1;
							for(int i=1;i<=N;i++)
								total=total*i;
							return total;
						}

						/*创建全排列树，该函数只调用一次*/
						void BuildTree(struct Node* pNode, int num,int layer)
						{	
							int i;
							int k=0;
							pNode->num=num;
							FLAG[num]=1;
							if(layer==N)
							{	
								pNode->count=0;
								return;
							}
							pNode->ppNode=(struct Node**)malloc((N-layer)*sizeof(struct Node*));	
							for(i=0;i<=N;i++)
							{
								if(FLAG[i]==0)
								{//FLAG记录用过的数字
									FLAG[i]=1;
									pNode->ppNode[k]=(struct Node*)malloc(sizeof(struct Node));
									BuildTree(pNode->ppNode[k],i,layer+1);
									k++;
									FLAG[i]=0;
								}
								else
									continue;			
							}	
						}

						/*
						检测某个特定的全排列是否正确，如果正确计数加1
						确保数组permutation[0]=0,真正的排列数字从1号下标开始填充
						*/
						bool  SearchPermutation(int permutation[],struct Node* pNode,int layer)
						{
							int Num=permutation[layer];
							if(Num!=pNode->num)
								return false;
							if(layer==N)
							{
								pNode->count++;
								return true;
							}
							for(int i=Num+1;i<=N;i++)
							{//FLAG记录已经出现的比当前数字小的数字的个数
								FLAG[i]++;
							}
							int nextNum=permutation[layer+1];
							if(nextNum>N||nextNum<0||nextNum-FLAG[nextNum]>N-layer-1)
								return false;
							struct Node* pNext=pNode->ppNode[nextNum-FLAG[nextNum]];
							return SearchPermutation(permutation,pNext,layer+1);

						}

						/*
						该函数用于统计待评测算法生成的全排列的个数
						*/
						int CheckCount(struct Node* pNode,int layer)
						{
							int i;
							int count=0;
							if(layer==N)
							{
								if(pNode->count==1)
									return 1;
								else
									return 0;
							}
							for(i=0;i<N-layer;i++)
							{
								count+=CheckCount(pNode->ppNode[i],layer+1);
							}
							return count;
						}

						/*
						pathName保存了待评测算法生成的全排列文件路径名
						文件内容是每行一个全排列，全排列用数字表示，数字间用空格或tab隔开
						*/
						void Judge(char* pathName)
						{
							int permutation[MAX_NUM];
							int count=0;
							FILE *fp=fopen(pathName,"r");
							if(fp==NULL)
							{
								printf("File Open Error!");
								return ;
							}
							permutation[0]=0;
							while(!feof(fp))
							{
								for(int i=1;i<=N;i++)
									fscanf(fp,"%d",&permutation[i]);
		
								memset(FLAG,0,sizeof(int)*MAX_NUM);
								SearchPermutation(permutation,ROOT,0);
							}
							count=CheckCount(ROOT,0);
							if(TOTAL-count==0)
							{
								ji.correct=1;
								ji.err_count=0;
							}
							else if(TOTAL-count>0)
							{
								ji.correct=0;
								ji.err_count=TOTAL-count;
							}
						}

						/*以字典序输出全排列用于测试所构造的树是否正确*/
						void PrintPermutation(struct Node* pNode,int layer)
						{
							int i;
							FLAG[layer]=pNode->num;
							if(layer==N)
							{
								for(i=1;i<=N;i++)
									printf("%d ",FLAG[i]);
								printf("\n");
								return;
							}
							for(i=0;i<N-layer;i++)
							{		
								PrintPermutation(pNode->ppNode[i],layer+1);
							}
						}

			                        JudgeInfo getRet(){
			                                return ji;
			                        }
        };
}//end of Daemon namespace
#endif
