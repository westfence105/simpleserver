#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "simpleserver.hpp"


SimpleTCPServer::SimpleTCPServer(){
	
	sock = socket( AF_INET, SOCK_STREAM, 0 );
	
	if( sock < 0 ){
		std::cerr << "[SimpleTCPServer] Error creating socket." << std::endl;
	}
	
	
	else{
			
		own.sin_family	= AF_INET;
		own.sin_port	= htons(1234);
		own.sin_addr.s_addr	= INADDR_ANY;
		
		if(  bind( sock, (sockaddr*)&own, sizeof(own) )  != 0  ){
			std::cerr << "[SimpleTCPServer] Error binding socket." << std::endl;
		}
		
	}
}

SimpleTCPServer::~SimpleTCPServer(){
	
}


void SimpleTCPServer::send( const std::string& str ){
	
	if(  listen( sock, str.length() )  != 0  ){
		std::cerr << "[SimpleTCPServer] Error starting to listen." << std::endl;
	}
	
	
	socklen_t len = sizeof( client );
	
	connection = accept( sock, (sockaddr*)&client, &len );
	
	if( connection < 0 ){
		std::cerr << "[SimpleTCPServer] Error while accept." << std::endl;
	}

	
	int wrote = write( connection, str.c_str(), str.length() );
	
	if( wrote < 1 ){
		std::cerr << "[SimpleTCPServer] Error sending message." << std::endl;
	}
	
	
	close( connection );
	
	
	close( sock );
	
}
