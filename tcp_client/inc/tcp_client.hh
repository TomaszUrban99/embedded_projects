#ifndef TCP_CLIENT_HH
#define TCP_CLIENT_HH

#include <cstdint>
#include <cstring>
#include <string>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>

class tcp_client{

    int _socket_id;
    struct sockaddr_in _server_address;

    public:

    tcp_client(uint16_t portNumber, char *ipAdress);

    int connect();

    int send(std::string &buffer);

    int read(std::string &buffer);
};

#endif