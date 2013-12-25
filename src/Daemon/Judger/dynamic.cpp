#include<iostream>
#include"DynamicJudger.hpp"
#include<cstring>
#include<boost/shared_ptr.hpp>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
using namespace boost;
using namespace Daemon;

int main(){
	int a;
	scanf("%d",&a);
	char str[32];
	sprintf(str,"%d",a);
	shared_ptr<DynamicJudger> njer(new DynamicJudger(a,string(str)+".out"));
	njer->run();
	return 0;
}
