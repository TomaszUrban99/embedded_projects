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

    /*!
        \brief Method for starting tcp_server
    */
    int start_tcp_server ();

    int receive(std::string &buffer);

    /*!
        \brief Method for sending string message
        \par &buffer, std::string reference to string with
        message to send

        
        \retval Number of send bytes
    */
    int send(std::string &buffer);
};

#endif