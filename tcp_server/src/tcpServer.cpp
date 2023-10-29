#include "../inc/tcpServer.hh"
#include <algorithm>
#include <iterator>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

tcpServer::tcpServer(uint16_t portNumber)
{
    _socket_id = socket(AF_INET, SOCK_STREAM, 0);

    /* Checke whether socket has been created correctly */
    if (_socket_id == -1)
        throw std::runtime_error(strerror(errno));

    /* Server address parameters */
    /* IP version */
    _server_address.sin_family = AF_INET;
    /* Port number */
    _server_address.sin_port = htons(portNumber);
    /* Incoming IP Adress*/
    _server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Bind socket to address */
    if ( bind(_socket_id, (struct sockaddr*) &_server_address, sizeof(_server_address)) == -1 )
        throw std::runtime_error(strerror(errno));

    
}

int tcpServer::init_tcp_server()
{
    if(listen(_socket_id,0) == -1){
        throw std::runtime_error(strerror(errno));
    };

    _socket_client_id = accept(_socket_id, nullptr, nullptr);

    if ( _socket_client_id < 0)
        throw std::runtime_error(strerror(errno));

    std::cout << "Succesfully connected" << std::endl;
    return 0;
}

int tcpServer::receive(std::string &buffer){

    char *buff;
    buff = new char[1024];

    int received_bytes = recv(_socket_client_id, buff, sizeof(buff), 0);
    int all = 0;
    
    while( received_bytes > 0){
        
        buff = buff + received_bytes;
        all += received_bytes;
        std::cout << buff << std::endl;
        received_bytes = recv(_socket_client_id, buff, sizeof(buff), 0);
        std::cout << received_bytes << std::endl;
    }

    buff = buff - all;
    std::string buffer2 (buff);
    buffer = buffer2;

    delete []  buff;

    return 0;
}