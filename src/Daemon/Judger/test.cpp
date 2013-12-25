#include<iostream>
#include"PlainJudger.hpp"
#include<cstring>
#include<boost/shared_ptr.hpp>
using namespace std;
using namespace boost;
using namespace Daemon;

int main(){
	shared_ptr<PlainJudger> njer(new PlainJudger(5,"5.out"));
	njer->run();
	return 0;
}
