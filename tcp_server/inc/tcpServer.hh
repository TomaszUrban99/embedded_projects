#ifndef TCP_SERVER_HH
#define TCP_SERVER_HH

#include <chrono>
#include <cstdint>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <cerrno>
#include <cstring>
#include <stdexcept>

class tcpServer{

    /* Socket descriptor */
    int _socket_id;

    int _socket_client_id;

    /* Structure containing server parameters */
    struct sockaddr_in _server_address;

    public:

    tcpServer( uint16_t portNumber);

    int init_tcp_server ();

    int receive(std::string &buffer);
};

#endif