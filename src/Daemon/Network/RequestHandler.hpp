#ifndef _REQUEST_HANDLER
#define _REQUEST_HANDLER
#include<iostream>
#include<curl/curl.h>

using namespace std;

namespace Daemon{
	class RequestHandler{
		private:
			CURL *curl;
			CURLcode res;
			struct curl_httppost *formpost;
			struct curl_httppost *lastptr;
			struct curl_slist *headerlist;
		public:
			RequestHandler(){
				curl=NULL;
				formpost=NULL;
				lastptr=NULL;
				headerlist=NULL;
				curl_global_init(CURL_GLOBAL_ALL);
				curl=curl_easy_init();
				headerlist=curl_slist_append(headerlist, "Expect:");
			}	
			void addFile(char* filepath){
				curl_formadd(&formpost,
							&lastptr,
							CURLFORM_COPYNAME,"sendfile",
							CURLFORM_FILE,filepath,
							CURLFORM_END);
				curl_formadd(&formpost,
							&lastptr,
							CURLFORM_COPYNAME,"filename",
							CURLFORM_COPYCONTENTS,filepath,
							CURLFORM_END);
				curl_formadd(&formpost,
							&lastptr,
							CURLFORM_COPYNAME,"submit",
							CURLFORM_COPYCONTENTS,"send",
							CURLFORM_END);
			}
			void sendFile(char* filepath,char* url){
				if(curl==NULL){
					cerr<<"error RequestHandler"<<endl;
				}
				else{
					curl_easy_setopt(curl,CURLOPT_URL,url);
					addFile(filepath);
					curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headerlist);
					curl_easy_setopt(curl,CURLOPT_HTTPPOST,formpost);
					res=curl_easy_perform(curl);
					if(res!=CURLE_OK){
						cerr<<"send file errror!"<<endl;
					}
					curl_easy_cleanup(curl);
					curl_formfree(formpost);
					curl_slist_free_all(headerlist);
				}
			}
	};//end of class RequestHandler
}//end of Daemon namespace
#endif
