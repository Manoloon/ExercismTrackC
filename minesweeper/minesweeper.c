#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows)
{
    int count = 0;
    while (minefield[count] != NULL) count++;
    char **result = malloc((count+1)* sizeof(char*));
    if(!result) return NULL;
    
    for(size_t r = 0; r < rows;++r)
    {
            if(minefield[r] == '.')
            {
                result[r] = strdup(minefield[r]);
            }
    }
    // null-terminate the array
    result[count] = NULL;

    return result;
}

void free_annotation(char **annotation)
{
    free(annotation);
}
