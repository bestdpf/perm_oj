#include<iostream>
#include"ResponseHandler.hpp"

using namespace std;
using namespace Daemon;

int main(){
	cout<<"Test ResponseHandler"<<endl;
	ResponseHandler *rh;
	rh=new ResponseHandler();
	rh->startUp();
	return 0;	
}
