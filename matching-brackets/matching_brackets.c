#include "matching_brackets.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool is_paired(const char *input)
{
    if(input == NULL) return false;
    size_t size = strlen(input);
    printf("size %lld\n",size);
    bool openBracket = false;
    for(size_t i= 0; i < size; ++i)
    {
        if(input[i] == '[')
            openBracket = true;
        if(openBracket && input[i] == ']')
            return true;
    }
    return false;
}
