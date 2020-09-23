#include<iostream>
#include<sys/socket.h>
#include<cstdlib>
#include<netinet/in.h>
#include<unistd.h>


using namespace std;

int main(int argc, char** argv) {
  constexpr int defaultPort = 8080;

  int port;

  if(argc == 1) {
    port = defaultPort;
  }
  else if(argc == 2) {

    try {
      port = stoi(argv[1]);
    } catch(exception const& e) {
      cerr << "Port number must be a positive integer. Input: " << argv[1] << endl;
      exit(EXIT_FAILURE);
    }

  } else {
    cerr << "Wrong argument number: " << argc << endl;
    exit(EXIT_FAILURE);
  }

  cout << "Basic HTTP server starting on port: " << port << endl;

  // create socket file descriptor
  int sockFd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockFd == -1) {
    cout << "Failed to create socket: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // bind socket to an address
  sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  sockaddr.sin_port = htons(port);

  struct sockaddr* sockaddrPtr = (struct sockaddr*)&sockaddr;
  unsigned long addrLen = sizeof(sockaddr);

  if(bind(sockFd, sockaddrPtr, addrLen) < 0) {
    cerr << "Failed to bind socket to port " << port << " errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // start listening
  if (listen(sockFd, 1) < 0) {
    cerr << "Failed to listen. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // accept connection
  int connection = accept(sockFd, sockaddrPtr, (socklen_t*)&addrLen);
  if(connection < 0) {
    cerr << "Failed to accept connection. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // read incomming message and send the response
  char message[100];
  auto bytesRead = read(connection, message, 100);
  cout << "Received: " << endl;
  cout << message << "\n" << endl;

  string response = "Got it\n";
  if(send(connection, response.c_str(), response.size(), 0) < 0 ) {
    cerr << "Failed to send the response" << endl;
  }

  // close the connection - need to dig in
  shutdown(connection, SHUT_WR);
  while (read(connection, message, 100) > 0) {}
  close(sockFd);

  exit(EXIT_SUCCESS);
}