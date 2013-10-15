#include<iostream>
#include"DaemonManager/DaemonManager.hpp"
using namespace Daemon;
int main(){
	cout<<"Test Daemon!!!"<<endl;
	boost::shared_ptr<DaemonManager> dm(new DaemonManager());
	dm->compile("g++","-lm -DONLINE_JUDGE","test.cpp");
	dm->addRunnableLanucher("./a.out","1.in","1.out");		
	dm->run();	
	//cout<<"End of Test!!"<<endl;
	return 0;
}
