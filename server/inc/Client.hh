#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>

class Client
{
public:
  Client(const int, const char *);
  ~Client();
  bool				readFrom();
  //void				writeTo(const std::string &);
  int				getFD() const;
private:
  void				writeInFile(const std::string &);
  std::string			ip;
  std::ofstream			*fileClient;
  int				fd;
  int				pad;
  int				currentPad;
};
