#include "saddle_points.h"

saddle_points_t* saddle_points(int rows, int cols, unsigned char grid[rows][cols])
{
    if(grid == NULL ) return NULL;
    saddle_points_t* result = malloc(sizeof(saddle_points_t*));
    for(int r = 0; r < rows;++r)
    {
        for(int c = 0; c < cols;++c)
        {
            
        }
    }
    
    return NULL;
}

void free_saddle_points(saddle_points_t *points)
{
    if(points == NULL) return;
    free(points);
}
