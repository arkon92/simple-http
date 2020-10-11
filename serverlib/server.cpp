#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<optional>

#include "server.h"

std::optional<Server> Server::createServer(int port) {
      Server s(port);
      if(s.init() > 0) {
        return { s };
      } else {
        return {};
      }
    }

int Server::init() {
  // create socket file descriptor
  socketFd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketFd == -1) {
    std::cout << "Failed to create socket: " << errno << std::endl;
    return -1;
  }

  // bind socket to an address
  sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  sockaddr.sin_port = htons(port);

  auto sockaddrPtr = reinterpret_cast<struct sockaddr*>(&sockaddr);
  unsigned long addrLen = sizeof(sockaddr);

  if(bind(socketFd, sockaddrPtr, addrLen) < 0) {
    std::cerr << "Failed to bind socket to port " << port << " errno: " << errno << std::endl;
    return -1;
  }

  // start listening
  if (listen(socketFd, 1) < 0) {
    std::cerr << "Failed to listen. errno: " << errno << std::endl;
    return -1;
  }

  // accept connection
  int connection = accept(socketFd, sockaddrPtr, reinterpret_cast<socklen_t*>(&addrLen));
  if(connection < 0) {
    std::cerr << "Failed to accept connection. errno: " << errno << std::endl;
    return -1;
  }

  // read incoming message and send the response
  char message[100];
  auto bytesRead = read(connection, message, 100);
  std::cout << "Bytes read: " << bytesRead << std::endl;
  std::cout << "Received: " << std::endl;
  std::cout << message << "\n" << std::endl;

  std::string response = "Got it\n";
  if(send(connection, response.c_str(), response.size(), 0) < 0 ) {
    std::cerr << "Failed to send the response" << std::endl;
    return -1;
  }

  // close the connection
  shutdown(connection, SHUT_WR);
  while (read(connection, message, 100) > 0) {}
  close(socketFd);

  return 0;
}