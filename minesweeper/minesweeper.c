#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows)
{
    if(rows == 0) return NULL;
    int cols = (int)strlen(minefield[0]);
    char **result = malloc(rows * sizeof(char*));
    if(!result) return NULL;
    for(int r = 0; r < (int)rows;++r)
    {
        result[r] = malloc(cols+1);
        if(!result[r])
        {
            // handle alloc failure
            for(int k = 0;k < r;++k)
                free(result[k]);
            free(result);
            return NULL;
        }
        for(int c = 0; c < cols;++c)
        {
            if(minefield[r][c]== '.')
            {
                int count = 0;
                if(r-1 >= 0)
                {
                    if(c-1 >= 0)
                    {
                        if(minefield[r-1][c-1]=='*')
                        {
                            count++;
                        }
                        if(minefield[r-1][c]=='*')
                        {
                            count++;
                        }
                        if(minefield[r][c-1]=='*')
                        {
                            count++;
                        }
                    }
                    if(c+1 < cols)
                    {
                        if(minefield[r-1][c+1]=='*')
                        {
                            count++;
                        }
                        if(minefield[r][c+1]=='*')
                        {
                            count++;
                        }
                    }
                }
                if(r+1 < (int)rows)
                {
                    if(c-1 >=0)
                    {
                        if(minefield[r+1][c-1]=='*')
                        {
                            count++;
                        } 
                        if(minefield[r+1][c]=='*')
                        {
                            count++;
                        }
                    }
                    if(c+1 <= cols)
                    {
                        if(minefield[r+1][c+1]=='*')
                        {
                           count++;
                        } 
                    }
                }
                result[r][c] = '0' + count++;
            }
            else
            {
                result[r][c] = '*';
            }
        }
        // null-terminate each string
        result[r][cols] = '\0';
    }  
    return result;
}

void free_annotation(char **annotation)
{
    if(annotation == NULL) return;
    for(size_t i = 0;i < 3;++i)
    {
        free(annotation[i]);
    }
    free(annotation);
}
