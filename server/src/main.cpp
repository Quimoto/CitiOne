//main for projects
//signal for server

#include <csignal>
#include <stdlib.h>

#include "Connexion.hh"

typedef struct	Proper
{
  Connexion	*connexion;
}		Proper;

void			endFunction(bool mode, Proper *_proper)
{
  static Proper		*proper;

  if (mode == false)
    proper = _proper;
  else
    delete (proper->connexion);
}

void			sig_handler(int signal)
{
  endFunction(true, NULL);
  exit(signal);
}

void			mySignal()
{
  std::signal(SIGINT, sig_handler);
  std::signal(SIGSEGV, sig_handler);
  std::signal(SIGTERM, sig_handler);
}

int			main(int argc, char **argv)
{
  Proper		proper;
  Connexion		*connexion = new Connexion(65432);

  (void)argc;
  (void)argv;
  proper.connexion = connexion;
  mySignal();
  endFunction(false, &proper);
  connexion->waitConnexion();
  return (-1);
}
