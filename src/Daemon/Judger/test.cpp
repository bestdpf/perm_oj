#include<iostream>
#include"NewJudger.hpp"
#include<cstring>
#include<boost/shared_ptr.hpp>
using namespace std;
using namespace boost;
using namespace Daemon;

int main(){
	shared_ptr<NewJudger> njer(new NewJudger(3,"test.in"));
	njer->run();
	return 0;
}
