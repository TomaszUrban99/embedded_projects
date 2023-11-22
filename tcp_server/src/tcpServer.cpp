#include "../inc/tcpServer.hh"
#include <algorithm>
#include <iterator>
#include <netinet/in.h>
#include <string>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

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

/* Method with main tcpServer functionalities */
int tcpServer::start_tcp_server()
{
    /* Create a set of sockets */
    fd_set socket_set;
    /* Set to zero the set of sockets*/
    FD_ZERO(&socket_set);
    /* Add server socket to socket_set */
    FD_SET(_socket_id, &socket_set);

    int max_socket = _socket_id;
   
    while(1){
     /* 
        Create copy of socket_set- select(), 
        modifies given socket_set 
    */
        fd_set socket_set_copy;
        socket_set_copy = socket_set;
    
    /* 
        We check for readibility, other fields (3,4) are
        for other modes of operation
    */
        select(max_socket+1, &socket_set_copy,0,0,0);
    
    /*
        Starting from 1. All socket descriptors are positive
        integers.
    */
        for ( int i = 1; i < max_socket; ++i)
        {
            if (i == _socket_id){
                /* 
                    If socket descriptor equals to listening socket
                    then, a new connection should be established 
                */

                /* Create new structure with new client data */
                struct sockaddr_storage new_client_address;
                socklen_t new_client_len = sizeof(new_client_address);

                int socket = accept(_socket_id, 
                    (struct sockaddr*) &new_client_address, &new_client_len);
                
                /* Check validity of newly accepted connection */
                if ( socket < 1){
                    /* Behaviour and structure would be changed in the future */
                    /* Establishing new connections would be in separate method */
                    std::cerr << "Failed to establish new connection" << std::endl;
                    return 1;
                }

                /* Add new socket to socket_set */
                FD_SET(socket, &socket_set);

                /* 
                    Check whether newly created socket is bigger than 
                    the biggest socket in the socket_set 
                */
                if ( socket > max_socket )
                    max_socket = socket;

                /* Print communicate about new client */
                char ip_add_buff[100];
                std::string ip_address(s)
            }
        }

    }

    return 0;
}

int tcpServer::receive(std::string &buffer){

    char buffer_char[1024];

    recv(_socket_client_id, buffer_char, sizeof(buffer_char), 0);

    /* Check whether previous data are removed */
    buffer.assign(buffer_char);
    
    return buffer.size();
}

int tcpServer::send(std::string &buffer){
    
    int bufferSize = buffer.size();

    std::string::iterator it = buffer.begin();

    int send_bytes = ::send(_socket_client_id, it.base(), bufferSize, 0);
    int all = 0;

    while ( send_bytes > 0){
        all += send_bytes;
        it += send_bytes;
        send_bytes = ::send(_socket_client_id, it.base(), bufferSize-all, 0);
    }

    return all;
}