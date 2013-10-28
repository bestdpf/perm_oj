#ifndef _XML_HANDLER
#define _XML_HANDLER
#include<iostream>
#include<pugixml.hpp>
#include<string>
#include<cstring>
using namespace std;
using namespace pugi;

namespace Daemon{
	class XMLHandler{
		private:
			xml_document doc;
			char buffer[256];
			char backup[256];
			size_t bf_sz;
		public:
			XMLHandler(){
				bf_sz=0;
			}
			XMLHandler(const XMLHandler& xmlb){
				bf_sz=xmlb.bf_sz;
				memcpy(buffer,xmlb.backup,bf_sz);
				memcpy(backup,xmlb.backup,bf_sz);
				loadFromBuffer(buffer,bf_sz);
			}
			XMLHandler operator=(const XMLHandler& xmlb){
				bf_sz=xmlb.bf_sz;
				memcpy(buffer,xmlb.backup,bf_sz);
				memcpy(backup,xmlb.backup,bf_sz);
				loadFromBuffer(buffer,bf_sz);
				return *this;
			}
			void loadFromBuffer(char* src,size_t sz){
				memcpy(buffer,src,sz);
				memcpy(backup,src,sz);
				bf_sz=sz;
				xml_parse_result ret=doc.load_buffer_inplace(buffer,sz);
				if(ret){
#if _DEBUG
					cout<<"Load XML from buffer Succefully!"<<endl;
#endif
				}
				else{
					cerr<<"Error Loading XML buffer"<<endl;
				}
			}
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
