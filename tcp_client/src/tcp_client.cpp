#include "../inc/tcp_client.hh"
#include <cstdint>
#include <iterator>
#include <sys/socket.h>

tcp_client::tcp_client(uint16_t portNumber, char *ipAdress){

        _socket_id = socket(AF_INET, SOCK_STREAM, 0);

        if (_socket_id == -1)
            throw std::runtime_error(strerror(errno));

        _server_address.sin_family = AF_INET;
        _server_address.sin_port = htons(portNumber);
        _server_address.sin_addr.s_addr = inet_addr(ipAdress);

}

int tcp_client::connect(){
    if (::connect(
        _socket_id, 
        reinterpret_cast<struct sockaddr*>(&_server_address), 
        sizeof(_server_address))
        == -1){
            return -1;
        }
    
    return 0;
}

int tcp_client::send(std::string &buffer ){

    int bufferSize = buffer.size();

    std::string::iterator it = buffer.begin();

    int bytes_sent = ::send(_socket_id, it.base(), sizeof(buffer.data()), 0);
    int all = 0;

    while ( bytes_sent > 0) {
        all += bytes_sent;
        it += bytes_sent;
        bytes_sent = ::send(_socket_id, it.base(), bufferSize-all, 0);
        std::cout << *it << std::endl;
    }

    return all;
}

int tcp_client::read(std::string &buffer){
    return 0;
}