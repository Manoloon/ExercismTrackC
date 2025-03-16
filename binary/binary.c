#include "binary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int convert(const char *input) 
{ 
    if(input == 0) return 0;
    size_t length = strlen(input);
    int num = strtol(input,NULL,10);
    int result = 0;
    for(size_t i = 0; i < length; i++ )
    {
        
    }
    return num; 
}
