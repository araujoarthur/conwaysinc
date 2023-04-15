#include "conway.h"

void init_conway_table(C_TABLE* ctable)
{
    int max_x = ctable->max_x;
    int max_y = ctable->max_y;

    ctable->table = malloc(max_x * sizeof(CELL*));
    for (int i = 0; i < max_x; i++)
    {
        ctable->table[i] = malloc(max_y * sizeof(CELL));
    }
}

void free_conway_table(C_TABLE* ctable)
{
    for (int i = 0; i < ctable->max_x; i++)
    {
        free(ctable->table[i]);
    }

    free(ctable->table);

    ctable->table = NULL;
}