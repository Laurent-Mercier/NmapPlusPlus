#include <iostream>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./nmappp <ip> <port>" << std::endl;
        return -1;
    }

    std::string ip   = argv[1];
    int port;
    try {
        port = std::stoi(argv[2]);
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid port" << e.what() << std::endl;
        return -1;
    }
    

    std::cout << "Scanning " << ip << " on port " << port << std::endl;

    int createSocket = 0,n = 0;
    char buffer[1024];
    sockaddr_in serverAddr;

    memset(buffer, 0 ,sizeof(buffer));

    if((createSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        std::cout << "Socket not created"<< std::endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    if(connect(createSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
    {
        std::cout << "Connection failed due to port and ip problems" << std::endl;
        return -1;
    }

    while((n = read(createSocket, buffer, sizeof(buffer)-1)) > 0)
    {
        buffer[n] = 0;
        if(fputs(buffer, stdout) == EOF)
        {
            std::cout << std::endl << "Standard output error";
        }

        std::cout << std::endl;
    }

    if( n < 0)
    {
        std::cout << "Standard input error" << std::endl;
    }

    return 0;
}
