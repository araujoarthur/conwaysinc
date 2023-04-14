#include "conway.h"

void init_conway_table(CONWAY_TABLE* ctable)
{
    int max_x = ctable->max_x;
    int max_y = ctable->max_y;

    ctable->table = malloc(max_x * sizeof(int*));
    for (int i = 0; i < max_x; i++)
    {
        ctable->table[i] = malloc(max_y * sizeof(int));
    }
}

void free_conway_table(CONWAY_TABLE* ctable)
{
    
}