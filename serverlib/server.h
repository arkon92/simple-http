#include<optional>

class Server {

  public:
    static std::optional<Server> createServer(int port);

  private:
    Server(int p): port(p) {}
    int init();
    int port;
    int socketFd;
};