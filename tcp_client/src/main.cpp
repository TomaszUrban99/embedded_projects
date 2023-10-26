#include <iostream>
#include "../inc/tcp_client.hh"

int main (int argc, char** argv){

    tcp_client newClient(8080,argv[1]);

    if(newClient.connect() < 0)
        std::cout << "Failed to connect" << std::endl;
    return 0;
}