#include <string>
#include <fstream>

class Client
{
public:
  Client();
  ~Client();
  const std::string		&readFrom();
  void				writeTo(const std::string &);
private:
  void				writeInFile(const std::string &);
  std::string			ip;
  std::string			namePC;
  std::string			osType;
  ofstream			fileClient;
  int				fd;
};
