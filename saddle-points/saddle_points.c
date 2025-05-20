#include "saddle_points.h"
#include <stdio.h>

saddle_points_t* saddle_points(int rows, int cols, unsigned char grid[rows][cols])
{
    saddle_points_t* result = malloc(sizeof(saddle_points_t));
    if(result == NULL) return NULL;
    result->points = malloc(rows * cols * sizeof(saddle_point_t));
    if(result->points == NULL)
    {
        free(result);
        return NULL;
    }

    int count = 0;
    for(int r = 0; r < rows;r++)
    {
        int MaxCol = 0;
        // largest in its row,
        for(int c =0; c < cols;c++)
        {
            if(grid[r][c] > grid[r][MaxCol])
            {
                MaxCol = c;
            }
        }
        int isSaddle = 1;
        unsigned char best = grid[r][MaxCol];
        //  while being the smallest in its column
        for(int m = 0; m < rows;m++)
        {
            if(grid[m][MaxCol] < best)
            {
                isSaddle = 0;
                break;
            }
        }
        if(isSaddle)
        {
            result->points[count].row = r+1;
            result->points[count].column = MaxCol+1;
            count++;
        }        
    }
    result->count = count;
    printf("Saddle Count [%d]\n",count);
    return result;
}

void free_saddle_points(saddle_points_t *points)
{
    if(points == NULL) return;
    free(points->points);
    free(points);
}
