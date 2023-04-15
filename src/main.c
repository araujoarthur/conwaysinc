#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conways.h"

#define MAX_OPTION_STRING 14

int main(int argc, char* argv[])
{

  char internal_opt[MAX_OPTION_STRING] = "help";
  char* usr_opt = malloc(MAX_OPTION_STRING * sizeof(char));
  char* POSSIBLE_OPTIONS[] = {"exit", "help", "run", "init", "view", "setIterations", "setActive", "setInactive"};

  while (strcasecmp(internal_opt, POSSIBLE_OPTIONS[0]) != 0)
  {
    scanf("%s", usr_opt);
    strcpy(internal_opt, usr_opt);
    if (strcasecmp(usr_opt, "init") == 0)
    {
      C_TABLE sim_table = {50,30,NULL};
      init_conway_table(&sim_table);
      show_table(&sim_table);
    }
  }

  free(usr_opt);

}

