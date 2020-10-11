#include<iostream>

#include "serverlib/server.h"

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


  optional<Server> s = Server::createServer(8080);
}