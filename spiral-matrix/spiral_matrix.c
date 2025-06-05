#include "spiral_matrix.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

spiral_matrix_t *spiral_matrix_create(int num)
{
    if(num < 1) return NULL;
    spiral_matrix_t* new_spiral = malloc(sizeof(spiral_matrix_t));
    if(new_spiral == NULL) return NULL;
    int** new_matrix = malloc(sizeof(int)*num);
    if(new_spiral == NULL)
    {
        free(new_spiral);
        return NULL;
    }
    for(int i = 0;i < num;++i)
    {
        new_matrix[i][i] = 0;
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
        free(matrix->matrix);
    }
    free(matrix);
}
