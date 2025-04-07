#include "armstrong_numbers.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

bool is_armstrong_number(int candidate)
{
    if(candidate <10) return true;
    int result = 0;
    char str[20] ;
    sprintf(str,"%d",candidate);
    int digits = log10(candidate);
    for(int i = 0; i < digits;++i)
    {
        result += pow(str[i],digits);
    }
    return result == candidate;
}
