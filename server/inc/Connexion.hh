#include <iostream>
#include <string>
#include <list>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "Client.hh"

class		Connexion
{
public:
  Connexion(const int);
  ~Connexion();
  void							waitConnexion();
 
private:
  int							checkMaxFd(fd_set *);
  bool							newConnexion();
  
  std::string						ip;
  std::list<Client*>					listClient;
  int							port;
  int							socket_fd;
  struct protoent					*pe;
  struct sockaddr_in					sin;
  struct sockaddr_in					sin_client;
  int							client_len;
};
