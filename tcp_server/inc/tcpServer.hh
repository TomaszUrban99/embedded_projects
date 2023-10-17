#ifndef TCP_SERVER_HH
#define TCP_SERVER_HH

#include <chrono>
#include <cstdint>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>

class tcpServer{

    /* Socket descriptor */
    int _socket_id;

    /* Structure containing server parameters */
    struct sockaddr_in _server_address;

    public:

    tcpServer( uint16_t portNumber);

    int init_tcp_server ();
};

#endif