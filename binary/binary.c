#include "binary.h"
#include <stdlib.h>
#include <string.h>

int convert(const char *input) 
{ 
    if(input == 0) return 0;
    size_t length = strlen(input);
    
    // with this line you have almost all the exercise resolve.
    //int num = strtol(input,NULL,2);
    ////////////////////////////////

    int num = atoi(input);
    int result = 0;
    for(size_t i = 0; i < length; i++ )
    {   
        result +=;
    }
    return result; 
}
