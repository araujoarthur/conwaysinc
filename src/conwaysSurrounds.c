#include "conwaysSurrounds.h"
#include "conwaysCore.h"
#include <stdbool.h>

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