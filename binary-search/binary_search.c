#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{   
    if (length == 0) return NULL;
    if(length < 2) return &arr[0];
    size_t middle = (size_t)length * 0.5;
    if (value == arr[middle]) return &arr[middle];
    if(value < arr[middle])
    {
        for(size_t i = 0; i < middle;++i)
        {
            if(value == arr[i]) return &arr[i];
        }
    }
    else
    {
        for(size_t i = middle; i < length;++i)
        {
            if(value == arr[i]) return &arr[i];
        }
    }
    return NULL;
}
