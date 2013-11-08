default:
	make release
debug: 
	g++ -Wall -g main.cpp -lboost_thread -lpugixml -lmicrohttpd -lcurl -D_DEBUG -o debug
release:
	g++ main.cpp -lboost_thread -lpugixml -lmicrohttpd -lcurl -o release
daemon:
	rm -f ./daemon
	g++ daemon.cpp -lboost_thread -o daemon
