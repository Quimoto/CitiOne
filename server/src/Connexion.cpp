#include "Connexion.hh"

Connexion::Connexion(const int _port)
{
  this->port = _port;
  this->client_len = sizeof(sin_client);
  this->pe = getprotobyname("TCP");
  if (this->socket_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto) == -1)
    {
      std::cerr << "Socket failed" << std::endl;
      std::exit(-1);
    }
  this->sin.sin_family = AF_INET;
  this->sin.sin_port = htons(this->port);
  this->sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(this->socket_fd, (const struct sockaddr*)&(this->sin), sizeof(this->sin)) == -1)
    {
      std::cerr << "Bind failed" << std::endl;
      std::exit(-1);
    }
  if (listen(this->socket_fd, 2) == -1)
    {
      std::cerr << "Listen failed" << std::endl;
      std::exit(-1);
    }
}

Connexion::~Connexion()
{}

bool		Connexion::newConnexion()
{
  int		fd;
  char		*ip;
  
  if ((fd = accept(this->socket_fd, (struct sockaddr*)&this->sin_client, (socklenn_t*)&this->client_len)) == -1)
    {
      std::cerr << "Accept failed" << std::endl;
      return (false);
    }
  ip = inet_ntoa(this->sin_client.sin_addr);
  this->listClient.push_back(new Client(fd, ip));
  return (true);
}
