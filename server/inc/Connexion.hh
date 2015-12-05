#include <String>
#include <list>

class		Connexion
{
public:
  Connexion();
  ~Connexion();
  void							newConnexion();

private:
  std::string						ip;
  int							port;
  	
};
