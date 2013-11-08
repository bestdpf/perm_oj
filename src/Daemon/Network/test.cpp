#include<iostream>
#include"ResponseHandler.hpp"

using namespace std;
using namespace Daemon;
class R{
	private:
		ResponseHandler *rh;
	public:
		R(){
			rh=new ResponseHandler();
		}
		~R(){
			free(rh);
		}
		void  start(){
			rh->startUp();
		}
};

int main(){
	cout<<"Test ResponseHandler"<<endl;
	R r;
	r.start();
	return 0;	
}
