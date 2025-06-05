#include "spiral_matrix.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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
    for(int i = 0;i < num;++i)
    {
        for(int j = 0; j < num;++j)
        {
            new_matrix[i][j] = i+j+1;
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
