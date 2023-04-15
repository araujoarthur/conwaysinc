#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conways.h"

#define MAX_OPTION_STRING 14

int main(int argc, char* argv[])
{

  char internal_opt[MAX_OPTION_STRING] = "help";
  char* usr_opt = malloc(MAX_OPTION_STRING * sizeof(char));
  char* POSSIBLE_OPTIONS[] = {"exit", "help", "run", "view", "setIterations", "setActive", "setInactive"};

  while (strcasecmp(internal_opt, POSSIBLE_OPTIONS[0]) != 0)
  {
    scanf("%s", usr_opt);
    strcpy(internal_opt, usr_opt);

  }

  free(usr_opt);

}

