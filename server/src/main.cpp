/*main*/

#include "Connexion.hh"

int		main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  Connexion	*network = new Connexion(65432);
  

  delete (network);
  return (0);
}
