#include "Client.hh"

Client::Client(const int _fd, const char *_ip)
{
  std::string		nameFile(ip);
  
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

void				Client::readFrom()
{
  char				str[50];
  std::string			text;
  
  read(this->fd, &str[0], 50);
  text.assign(str);
  text = text.substr(0, text.find('\n'));
  std::cout << "text = " << str << std::endl;
  this->writeInFile(text);
}

void				Client::writeInFile(const std::string &text)
{
  if (*(this->fileClient))
    {
      std::cout << "Write in file" << std::endl;
      *(this->fileClient) << text;
      this->currentPad++;
      if (this->currentPad >= pad)
	{
	  this->currentPad = 0;
	  *(this->fileClient) << std::endl;
	}
    }
}

int				Client::getFD() const
{
  return (this->fd);
}
