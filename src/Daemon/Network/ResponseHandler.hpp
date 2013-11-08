#ifndef _RESPONSE_HANDLER
#define _RESPONSE_HANDLER
#include<sys/types.h>
#include<sys/select.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<microhttpd.h>
#include<string>
#include<unistd.h>
#include<iostream>
#include"XMLHandler.hpp"
#include<queue>
#include<algorithm>
#define PORT            8888
#define POSTBUFFERSIZE  512
#define MAXCLIENTS      2

#define GET             0
#define POST            1
using namespace std;
namespace Daemon{
	struct connection_info_struct
	{
	  int connectiontype;
	  struct MHD_PostProcessor *postprocessor;
	  //FILE *fp;
	  char *bf;
      size_t bf_sz;
	  const char *answerstring;
	  int answercode;
	  connection_info_struct(){
		bf=NULL;
		bf_sz=0;
		answercode=0;
		connectiontype=0;
		postprocessor=NULL;
		answerstring=NULL;
	}
		~connection_info_struct(){
			if(bf!=NULL){
				delete[]bf;
			}
			bf_sz=0;
		}
	};
	class ResponseHandler{
		private:
			static queue<XMLHandler> xmlq;
			const static unsigned int _port=8888;
			const static int _max_clients=10;
			const static int _GET=0;
			const static int _POST=1;
			static unsigned int nr_of_uploading_clients;
			static struct MHD_Daemon *daemon;
			const static char* askpage,*busypage,*completepage,*errorpage,*servererrorpage,*fileexistspage; 
		public:
			ResponseHandler(){
				nr_of_uploading_clients =0;
				askpage = "<html><body>\n\
				  Upload a file, please!<br>\n\
				  There are %u clients uploading at the moment.<br>\n\
				  <form action=\"/filepost\" method=\"post\" enctype=\"multipart/form-data\">\n\
				  <input name=\"file\" type=\"file\">\n\
				  <input type=\"submit\" value=\" Send \"></form>\n\
				  </body></html>";

				busypage =
				  "<html><body>This server is busy, please try again later.</body></html>";

				completepage =
				  "<html><body>The upload has been completed.</body></html>";

				errorpage =
				  "<html><body>This doesn't seem to be right.</body></html>";
				servererrorpage =
				  "<html><body>An internal server error has occured.</body></html>";
				fileexistspage =
				  "<html><body>This file already exists.</body></html>";
				
			}
			~ResponseHandler(){
				MHD_stop_daemon(daemon);
				free(daemon);
				daemon=NULL;
			}
			static bool getNextXML(XMLHandler& xmlh){
				if(xmlq.empty()){
					return false;
				}
				else{
					xmlh=xmlq.front();
					xmlq.pop();
					return true;
				}
			}
			static void startUp(){
				daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                             &answer_to_connection, NULL,
                             MHD_OPTION_NOTIFY_COMPLETED, request_completed,
                             NULL, MHD_OPTION_END);
				  if (NULL == daemon){
						cerr<<"error launching  requesthandler"<<endl;
					}
				while(true){
					sleep(100);
				}
			}
			static int
			send_page (struct MHD_Connection *connection, const char *page,
				  int status_code)
			{
			  int ret;
			  struct MHD_Response *response;

			  response =
			    MHD_create_response_from_buffer (strlen (page), (void *) page,
							    MHD_RESPMEM_MUST_COPY);
			  if (!response)
			    return MHD_NO;
			  MHD_add_response_header (response, MHD_HTTP_HEADER_CONTENT_TYPE, "text/html");
			  ret = MHD_queue_response (connection, status_code, response);
			  MHD_destroy_response (response);

			  return ret;
			}


			static int
			iterate_post (void *coninfo_cls, enum MHD_ValueKind kind, const char *key,
				      const char *filename, const char *content_type,
				      const char *transfer_encoding, const char *data, uint64_t off,
				      size_t size)
			{
			  struct connection_info_struct *con_info = (connection_info_struct*)coninfo_cls;
			  //FILE *fp;

			  con_info->answerstring = servererrorpage;
			  con_info->answercode = MHD_HTTP_INTERNAL_SERVER_ERROR;

			  if (0 != strcmp (key, "file"))
			    return MHD_NO;

			  if (!con_info->bf)
			    {
				/*
			      if (NULL != (fp = fopen (filename, "rb")))
				{
				  fclose (fp);
				  con_info->answerstring = fileexistspage;
				  con_info->answercode = MHD_HTTP_FORBIDDEN;
				  return MHD_NO;
				}
			      con_info->fp = fopen (filename, "ab");
			      if (!con_info->fp)
				return MHD_NO;
				*/
			    }
			  if (size > 0)
			    {
				char* old_bf=con_info->bf;
				size_t old_bf_sz=con_info->bf_sz;
				con_info->bf_sz+=size;
				con_info->bf=new char[con_info->bf_sz];
				if(old_bf!=NULL){
					cout<<"Copy old data"<<endl;
					memcpy(con_info->bf,old_bf,old_bf_sz);
					delete[] old_bf;
				}
				cout<<"copy new data"<<endl;
				memcpy(con_info->bf+old_bf_sz,data,size);
			      //if (!fwrite (data, size, sizeof (char), con_info->fp))
				//return MHD_NO;
			    }

			  con_info->answerstring = completepage;
			  con_info->answercode = MHD_HTTP_OK;
				  if (con_info->bf){
						XMLHandler xmlh=XMLHandler();
						xmlh.loadFromBuffer(con_info->bf,con_info->bf_sz);
						xmlq.push(xmlh);
					}
					/*
					XMLHandler testxml;
					if(getNextXML(testxml)){
						cout<<"succ getting xml"<<endl;
						testxml.dump();
					}
					else{
						cout<<"fail getting xml"<<endl;
					}
					*/
			  return MHD_YES;
			}


			static void
			request_completed (void *cls, struct MHD_Connection *connection,
					  void **con_cls, enum MHD_RequestTerminationCode toe)
			{
			  struct connection_info_struct *con_info = (connection_info_struct*)*con_cls;

			  if (NULL == con_info)
			    return;

			  if (con_info->connectiontype == POST)
			    {
			      if (NULL != con_info->postprocessor)
				{
				  MHD_destroy_post_processor (con_info->postprocessor);
				  nr_of_uploading_clients--;
				}
/*
			      if (con_info->bf){
						XMLHandler xmlh=XMLHandler();
						xmlh.loadFromBuffer(con_info->bf,con_info->bf_sz);
						xmlq.push(xmlh);
					}
					XMLHandler testxml;
					if(getNextXML(testxml)){
						cout<<"succ getting xml"<<endl;
						testxml.dump();
					}
					else{
						cout<<"fail getting xml"<<endl;
					}
*/
			    }
			
			  free (con_info);
			  *con_cls = NULL;
			}


			static int
			answer_to_connection (void *cls, struct MHD_Connection *connection,
					      const char *url, const char *method,
					      const char *version, const char *upload_data,
					      size_t *upload_data_size, void **con_cls)
			{
				#if _DEBUG
				cout<<"daemon get file"<<endl;
				#endif
			  if (NULL == *con_cls)
			    {
			      struct connection_info_struct *con_info;

			      if (nr_of_uploading_clients >= MAXCLIENTS)
				return send_page (connection, busypage, MHD_HTTP_SERVICE_UNAVAILABLE);

			      con_info = (connection_info_struct*)malloc (sizeof (struct connection_info_struct));
			      if (NULL == con_info)
				return MHD_NO;

			      con_info->bf = NULL;
				  con_info->bf_sz=0;

			      if (0 == strcmp (method, "POST"))
				{
				  con_info->postprocessor =
				    MHD_create_post_processor (connection, POSTBUFFERSIZE,
							      iterate_post, (void *) con_info);

				  if (NULL == con_info->postprocessor)
				    {
				      free (con_info);
				      return MHD_NO;
				    }

				  nr_of_uploading_clients++;

				  con_info->connectiontype = POST;
				  con_info->answercode = MHD_HTTP_OK;
				  con_info->answerstring = completepage;
				}
			      else
				con_info->connectiontype = GET;

			      *con_cls = (void *) con_info;

			      return MHD_YES;
			    }

			  if (0 == strcmp (method, "GET"))
			    {
			      char buffer[1024];

			      snprintf (buffer, sizeof (buffer), askpage, nr_of_uploading_clients);
			      return send_page (connection, buffer, MHD_HTTP_OK);
			    }

			  if (0 == strcmp (method, "POST"))
			    {
			      struct connection_info_struct *con_info = (connection_info_struct*)*con_cls;

			      if (0 != *upload_data_size)
				{
				  MHD_post_process (con_info->postprocessor, upload_data,
						    *upload_data_size);
				  *upload_data_size = 0;

				  return MHD_YES;
				}
			      else
				{
				  if (NULL != con_info->bf)
				  {
				    //fclose (con_info->fp);
				    con_info->bf = NULL;
				  }
				  /* Now it is safe to open and inspect the file before calling send_page with a response */
				  return send_page (connection, con_info->answerstring,
						    con_info->answercode);
				}

			    }

			  return send_page (connection, errorpage, MHD_HTTP_BAD_REQUEST);
			}
			
	};//end of class ResponseHandler
	const unsigned int ResponseHandler::_port;
	const int ResponseHandler::_max_clients;
	const int ResponseHandler::_GET;
	const int ResponseHandler::_POST;
	queue<XMLHandler> ResponseHandler::xmlq;
	unsigned int ResponseHandler::nr_of_uploading_clients;
	struct MHD_Daemon *ResponseHandler::daemon;
	const char* ResponseHandler::askpage,*ResponseHandler::busypage,*ResponseHandler::completepage,*ResponseHandler::errorpage,*ResponseHandler::servererrorpage,*ResponseHandler::fileexistspage; 
}//end of Daemon namespace
#endif
