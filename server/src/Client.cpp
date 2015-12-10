#include "Client.hh"

Client::Client(const int _fd, const char *_ip)
{
  std::string		nameFile("../logs/");

  nameFile.append(_ip);
  nameFile.append(".log");
  this->ip.assign(_ip);
  this->fd = _fd;
  this->fileClient = new std::ofstream(nameFile.c_str(), std::ios::out | std::ios::app);
  this->pad = 20;
  this->currentPad = 0;
}

Client::~Client()
{
  if (*(this->fileClient))
    this->fileClient->close();
  delete (this->fileClient);
}

#include <string.h>

bool				Client::readFrom()
{
  char				str[50];
  std::string			text;
  int				i = 0;

  bzero(str, 49);
  if (read(this->fd, &str[0], 49) < 0)
    {
      std::cout << "SERVER: " << this->ip << " has left !" << std::endl;
      return false;
    }
  while (str[i] >= 32 && str[i] <= 126 && i < 49)
    i++;
  str[i] = '\0';
  text.assign(str);
  this->writeInFile(text);
  return true;
}

void				Client::writeInFile(const std::string &text)
{
  if (*(this->fileClient))
    {
      if (text.size() > 1)
	*(this->fileClient) << std::endl;
      *(this->fileClient) << text;
      if (text.size() > 1)
	*(this->fileClient) << std::endl;
    }
}

int				Client::getFD() const
{
  return (this->fd);
}
