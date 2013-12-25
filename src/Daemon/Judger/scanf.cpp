#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(){
	char str[25];
	clock_t begin,end;
	double time_spent;
	begin=clock();
	while(scanf("%s",str)!=EOF){
		//printf("%s\n",str);
	}
	end=clock();
	time_spent=(end-begin)*1000/CLOCKS_PER_SEC;
	printf("time %lf\n",time_spent);	
	return 0;
}
