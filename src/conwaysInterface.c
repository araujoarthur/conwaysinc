#include <stdio.h>

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
