#include<iostream>
#include"XMLHandler.hpp"

using namespace std;
using namespace pugi;
using namespace Daemon;

int main(){
	cout<<"Testing XMLHandler now"<<endl;
	XMLHandler* xmlh;
	xmlh=new XMLHandler();
	xmlh->loadFile("test.xml");
	xmlh->dump();
	xmlh->addChild("duan","is a good personal");
	xmlh->dump();
	xmlh->saveFile("out.xml");
	return 0;
}
