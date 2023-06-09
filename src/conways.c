#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "conways.h"

int inited_table = 0; // 0 not inited, 1 inited;

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

/* Receive x and y, the surrounding points. It can handle cases where it overflow the
Conway table.*/
bool is_neighboor_populated(C_TABLE ctable, int x, int y)
{
    int max_x = ctable.max_x;
    int max_y = ctable.max_y;

    if (x >= 0 && x < max_x && y >= 0 && y < max_y)
    {
        return true;
    }

    // Only run if not returned yet, obviously. 
    return false;
}

//        x-1,y-1 | x,y-1 |  x+1,y-1     
//        x-1,y   |  x,y  |  x+1,y
//        x-1,y+1 | x,y+1 |  x+1,y+1

/* Receives a CONWAY TABLE and a x,y point, returning the number of populated surrounds.*/
int populated_surrounds(C_TABLE ctable, int x, int y)
{
    int populated = 0, _X = 0, _Y = 0;

    for (_X = -1; _X <= 1; _X++)
    {
        for (_Y = -1; _Y <= 1; _Y++)
        {
            if (_X == 0 && _Y == 0)
            {
                continue;
            }

            if(is_neighboor_populated(ctable, x+_X, y+_Y))
            {
                populated++;
            }
        }
    }

    return populated;
}

// Receive a pointer to a CONWAY TABLE. Prints the current state of the table.
void show_table(C_TABLE* ctable)
{
    printf("\n");
    for (int y = 0; y < ctable->max_y; y++)
    {
        for (int x = 0; x < ctable->max_x; x++)
        {
            printf("%c ", is_cell_active(ctable->table[x][y]) ? 'X' : 'O');
        }
        printf("\n");
    }   
}


bool is_cell_active(CELL cell)
{
    return cell.status ? false : true;
}

void set_active(CELL* cell)