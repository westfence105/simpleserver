#include <iostream>
#include <memory>

#include "simpleserver.hpp"


int main( int argc, char** argv ){

	std::shared_ptr<SimpleTCPServer> server = std::make_shared<SimpleTCPServer>();
	
	
	for( int i = 1;  argc < i;  ++i  ){
		server->send( argv[i] );
	}
	
	
	return 0;
}
