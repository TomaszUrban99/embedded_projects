#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>

#include <string>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../inc/tcpServer.hh"

int main (int argc, char** argv){

    if ( argc < 1 ){
        throw std::runtime_error(strerror(errno));
        exit(1);
    }
    
    tcpServer server(atoi(argv[1]));
    std::string buffer;

    server.init_tcp_server();

    server.receive(buffer);

    std::cout << buffer << std::endl;
    
    return 0;
}