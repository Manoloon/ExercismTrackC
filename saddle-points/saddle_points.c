#include "saddle_points.h"
#include <stdio.h>

saddle_points_t* saddle_points(int rows, int cols, unsigned char grid[rows][cols])
{
    if(grid == NULL ) return NULL;
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
        int minC = 0;
        // find max in current row
        for(int c =0; c < cols;c++)
        {
            printf("min grid[%d][%d] : ",r,c);
            printf("data : %d\n",grid[r][c]);
            if(grid[r][c] > grid[r][minC])
            {
                minC = c;
                printf("minC = %d\n",minC);
            }
        }
        int isSaddle = 1;
        unsigned char best = grid[r][minC];
        printf("best : %d in grid[%d][%d]\n",best,r,minC);
        // check if this max is min in its column
        for(int m = 0; m < rows;m++)
        {

            printf("Max grid[%d][%d] : ",m,minC);
            printf("data : %d\n",grid[m][minC]);
            if(grid[m][minC] < best)
            {
                isSaddle = 0;
                printf("bad grid[%d][%d]\n",m,minC);
                break;
            }
        }
        if(isSaddle)
        {
            result->points[count].row = r;
            printf("Saddle: point[%d][%d]\n",r,minC);
            result->points[count].column = minC;
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
