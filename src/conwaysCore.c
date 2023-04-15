#include "conwaysCore.h"
#include <stdlib.h>
#include <stdbool.h>

// Init the CONWAY TABLE
void init_conway_table(C_TABLE* ctable)
{
    // If table is inited, can't re-init it before freeing.
    if (inited_table)
    {
        return;
    }

    int max_x = ctable->max_x;
    int max_y = ctable->max_y;

    ctable->table = malloc(max_x * sizeof(CELL*));
    for (int x = 0; x < max_x; x++)
    {
        ctable->table[x] = malloc(max_y * sizeof(CELL));
        for (int y = 0; y < max_y; y++)
        {
            ctable->table[x][y].status = 0; 
        }
    }

    inited_table = 1;
}

// Receive a pointer to a CONWAY TABLE and free the entire memory.
void free_conway_table(C_TABLE* ctable)
{
    // If table is not inited, can't free it.
    if (!inited_table)
    {
        return;
    }

    for (int x = 0; x < ctable->max_x; x++)
    {
        free(ctable->table[x]);
    }

    free(ctable->table);

    ctable->table = NULL;
}

bool is_cell_active(CELL cell)
{
    return cell.status ? false : true;
}

void set_active(CELL* cell)
{
    
}