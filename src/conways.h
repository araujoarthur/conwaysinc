#ifndef CONWAYS_HEADER
#define CONWAYS_HEADER

typedef struct CONWAY_CELL 
{
    int x;
    int y;
} CELL;

typedef struct CONWAY_TABLE 
{
    int max_x;
    int max_y;
    CELL* table; // is a [x][y] table after initiated 
} C_TABLE;

void init_conway_table(C_TABLE* ctable);
void free_conway_table(C_TABLE* ctable);

#endif