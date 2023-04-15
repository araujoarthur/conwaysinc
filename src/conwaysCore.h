#ifndef CONWAYS_CORE
#define CONWAYS_CORE

#include <stdbool.h>

typedef struct CONWAY_CELL 
{
    int status; // 0 (false) inactive, 1 active (true).
} CELL;

typedef struct CONWAY_TABLE 
{
    int max_x;
    int max_y;
    CELL** table; // is a [x][y] table after initiated.
} C_TABLE;

typedef struct TABLE_POINT
{
    int x;
    int y;
} POINT;

void init_conway_table(C_TABLE* ctable);
void free_conway_table(C_TABLE* ctable);
bool is_cell_active(CELL cell);

#endif