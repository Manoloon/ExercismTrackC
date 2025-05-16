#include "matching_brackets.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool is_paired(const char *input)
{
    if(input == NULL) return false;
    size_t size = strlen(input);
    printf("size %lld\n",size);
    int openBracket = 0;
    int openParenthesis = 0;
    int openCoso = 0;
    for(size_t i= 0; i < size; ++i)
    {
        switch (input[i])
        {
        case '[':
            openBracket++;
            break;
        case '(':
            openParenthesis++;
            break;
        case '{':
            openCoso++;
            break;
        case ']':
            if(openBracket > 0)
            {
                openBracket--;
                break;
            }
            else
                return false;
        case ')':
            if(openParenthesis > 0)
            {
                openParenthesis--;
                break;
            }
            else
                return false;
        case '}':
            if(openCoso > 0)
            {
                openCoso--;
                break;
            }
            else
                return false;
        default:
            break;
        }
    }
    printf("brakets %d, Cosos %d, parenthesis %d",openBracket,openCoso,openParenthesis);
    return openBracket + openCoso + openParenthesis == 0;
}
