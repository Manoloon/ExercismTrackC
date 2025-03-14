#include "darts.h"

uint8_t score(coordinate_t position) 
{
    const int RADIUS = 10;
    if(position.x == RADIUS && position.y <= RADIUS)
    {
        return 1;
    }
    return 0; 
}
