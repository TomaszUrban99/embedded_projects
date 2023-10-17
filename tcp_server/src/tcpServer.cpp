#include "../inc/tcpServer.hh"
#include <cerrno>
#include <cstring>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

tcpServer::tcpServer(uint16_t portNumber)
{
    _socket_id = socket(AF_INET, SOCK_DGRAM, 0);

    /* Checke whether socket has been created correctly */
    if (_socket_id == -1)
        throw std::runtime_error(strerror(errno));

    /* Server address parameters */
    /* IP version */
    _server_address.sin_family = AF_INET;
    /* Port number */
    _server_address.sin_port = htons(portNumber);
    /* Incoming IP Adress*/
    _server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    /* Bind socket to address */
    if ( bind(_socket_id, (struct sockaddr*) &_server_address, sizeof(_server_address)) == -1 )
        throw std::runtime_error(strerror(errno));
}

int tcpServer::init_tcp_server()
{
    
}