#include<optional>

class Server {

  public:
    static std::optional<Server> createServer(int port);

  private:
    Server(int p): port(p) {}
    int init();
    int awaitConnection(struct sockaddr* sockaddrPtr, unsigned long& addrLen) const;
    int port;
    int socketFd;
};