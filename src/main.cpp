#include <iostream>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./nmappp <ip> <port>" << std::endl;
        return 1;
    }

    std::string ip   = argv[1];
    int port;
    try {
        port = std::stoi(argv[2]);
    } catch (std::invalid_argument e) {
        std::cout << "Invalid port" << e.what() << std::endl;
    }
    

    std::cout << "Scanning " << ip << " on port " << port << std::endl;
    return 0;
}
