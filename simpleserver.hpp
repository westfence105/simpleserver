
#pragma once

#ifndef __SB_simpleserver_hpp_
#define __SB_simpleserver_hpp_

#include <sys/types.h>
#include <netinet/in.h>

class SimpleTCPServer {
	
	private:
	
		int sock;
		int connection;
		
		sockaddr_in own;
		sockaddr_in client;
	
	
	public:
	
		SimpleTCPServer();
		~SimpleTCPServer();
		
		void send( const std::string& str );
	
};

#endif
