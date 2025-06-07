#include "spiral_matrix.h"
#include <stdlib.h>
#include <stddef.h>

spiral_matrix_t *spiral_matrix_create(int num)
{
    spiral_matrix_t* new_spiral = malloc(sizeof(spiral_matrix_t));
    if(new_spiral == NULL) return NULL;
    
    if(num < 1) 
    {
        new_spiral->size = 0;
        new_spiral->matrix = NULL;
        return new_spiral;
    }
    // allocate num of row pointers and zeroes them
    int** new_matrix = (int**)calloc(num,sizeof(int*));
    if(new_matrix == NULL)
    {
        free(new_spiral);
        return NULL;
    }
    // checking not returning NULL
    for(int i = 0; i < num;i++)
    {
        new_matrix[i] = (int*)calloc(num,sizeof(int));
        if(new_matrix[i] == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(new_matrix[j]);
            }
            free(new_matrix);
            free(new_spiral);
            return NULL;
        }
    }
    // init
    int left = 0;
    int right = num -1;
    int top = 0;
    int Bottom = num -1;
    int count = 1;
    /* Process :
       1) move left : top row : fill from left to right
       2) move down : second row : fill right most to bottom
       3) Move Right : Fill bottom row from right to left
       4) Move Up : Fill left column from bottom to top
       -- repeat
    */
   while(left <= right && top <= Bottom)
   {
        // top row
        for(int i = left; i <= right;++i)
        {
            new_matrix[top][i] = count++;
        }
        top++;
        // fill right col
        for(int i = top; i <= Bottom; ++i)
        {
            new_matrix[i][right] = count++;
        }
        right--;
        // fill bottom row Right To left
        if(top <= Bottom)
        {
            for(int i = right; i >= left;--i)
            {
                new_matrix[Bottom][i] = count++;
            }
            Bottom--;
        }
        // fill left column from bottom to up
        if(left <= right)
        {
            for(int i = Bottom; i >= top; --i)
            {
                new_matrix[i][left] = count++;
            }
            left++;
        }
   }

    new_spiral->matrix = new_matrix;
    new_spiral->size = num;
    return new_spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix)
{
    if(matrix == NULL) return;
    if(matrix->matrix != NULL)
    {
        for(int i = 0; i < matrix->size ; ++i)
        {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
    free(matrix);
}
