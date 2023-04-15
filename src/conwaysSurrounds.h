#ifndef CONWAYS_SURROUNDS
#define CONWAYS_SURROUNDS

#include "conwaysCore.h"
#include <stdbool.h>

bool is_neighboor_populated(C_TABLE ctable, int x, int y);
int populated_surrounds(C_TABLE ctable, int x, int y);

#endif