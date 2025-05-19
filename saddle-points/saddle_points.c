#include "saddle_points.h"
#include <stdio.h>

saddle_points_t* saddle_points(int rows, int cols, unsigned char grid[rows][cols])
{
    if(grid == NULL ) return NULL;
    saddle_points_t* result = malloc(sizeof(saddle_points_t));
    if(result == NULL) return NULL;
    result->points = malloc(rows * sizeof(saddle_point_t));
    if(result->points == NULL)
    {
        free(result);
        return NULL;
    }

    int count = 0;
    for(int r = 0; r < rows;++r)
    {
        int minC = 0;
        // find min in current row
        for(int c = 1; c < cols; ++c)
        {
            if(grid[r][c] < grid[r][minC])
            {
                minC = c;
            }
        }
        int isSaddle = 1;
        unsigned char best = grid[r][minC];
        // check if this Min is max in its column
        for(int m = 0; m < rows;++m)
        {
            if(grid[m][minC] > best)
            {
                isSaddle = 0;
                break;
            }
        }
        if(isSaddle)
        {
            result->points[count].row = r;
            result->points[count].column = minC;
            count++;
        }        
    }
    result->count = count;
    return result;
}

void free_saddle_points(saddle_points_t *points)
{
    if(points == NULL) return;
    free(points->points);
    free(points);
}
