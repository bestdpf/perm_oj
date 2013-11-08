#include<iostream>
#include"DaemonServer.hpp"
#include"boost/shared_ptr.hpp"

using namespace std;
using namespace boost;
using namespace Daemon;
using namespace pugi;

int main(){
	shared_ptr<DaemonServer>ds(new DaemonServer());
	ds->run();
	return 0;
}
