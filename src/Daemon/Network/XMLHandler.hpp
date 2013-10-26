#ifndef _XML_HANDLER
#define _XML_HANDLER
#include<iostream>
#include<pugixml.hpp>
#include<string>

using namespace std;
using namespace pugi;

namespace Daemon{
	class XMLHandler{
		private:
			xml_document doc;
		public:
			XMLHandler(){}
			void loadFile(char * path){
				xml_parse_result ret=doc.load_file(path);
				if(ret){
#if _DEBUG
					cout<<"Load XML File Succefully!"<<endl;		
#endif
				}
				else{
					cerr<<"Error Loading XML File"<<endl;
				}
			}
			void saveFile(char* path){
#if _DEBUG
				cout<<"Saving XML File"<<endl;
#endif
				doc.save_file(path);
			}
			void dump(xml_node xmln,int level){
				int i;
				for(i=0;i<level;i++)cout<<"\t";
				cout<<xmln.name()<<"\t"<<xmln.value()<<endl;
				xml_attribute_iterator ait;
				for(ait=xmln.attributes_begin();ait!=xmln.attributes_end();ait++){
					int i;
					for(i=0;i<level;i++)cout<<"\t";
					cout<<ait->name()<<"\t"<<ait->value()<<endl;
				}
				xml_node_iterator it;
				for(it=xmln.begin();it!=xmln.end();it++){
						dump(*it,level+1);
				}
			}
			void addChild(char * name,char* value){	
				xml_node ch=doc.append_child(name);
				ch.append_child(node_pcdata).set_value(value);
			}
			void dump(){
#if _DEBUG
				cout<<"dump XML now"<<endl;
#endif
				dump(doc,0);
			}
	};//end of XMLHandler class
}//end of namespace Daemon

#endif
