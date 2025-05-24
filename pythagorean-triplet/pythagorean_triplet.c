#include "pythagorean_triplet.h"
#include <stdlib.h>
#include <stdio.h>

triplets_t *triplets_with_sum(int sum)
{
    if(sum < 12) return NULL;
    triplets_t* triplets = malloc(sizeof(triplets_t));
    if(triplets == NULL) return NULL;
    uint16_t capacity = 64;
    triplet_t* results = malloc(sizeof(triplet_t) * capacity);
    if(results == NULL) return NULL;

    uint16_t halfSum = sum * 0.5;
    uint16_t count = 0;
    for(uint16_t m = 2; m < halfSum; m++)
    {
        for(uint16_t n = 1; n < m;n++)
        {
            if((m - n) % 2 == 1 && gcd(m,n) == 1)
            {
                uint16_t a = m * m - n * n;
                uint16_t b = 2 * m * n;
                uint16_t c = m * m + n * n;   
               
                uint16_t base_sum = a+b+c;
                // check that A+B+C == sum
                if (sum % base_sum != 0) continue;
                // generate scaled non primitive triplets
                uint16_t k = sum / base_sum;
                    a *= k;
                    b *= k;
                    c *= k;

                // sort a and b 
                if(a > b)
                {
                    uint16_t temp = a;
                    a = b;
                    b = temp;
                }
                // check if results of triplets goes up than the capacity . Reallocate
                if(count >= capacity)
                {
                    capacity *=2;
                    results = realloc(results,sizeof(triplet_t)*capacity);
                    if(results == NULL)
                    {
                        free(triplets);
                        return NULL;
                    }
                }
                if(!is_duplicate(results,count,a,b,c))
                {
                    printf("a = %d, b = %d, c = %d\n",a,b,c);
                    results[count].a = a;
                    results[count].b = b;
                    results[count].c = c;
                    count++;
                }
            }
        }
    }
    printf("count = %d\n",count);
    if(count == 0)
    {
        free(results);
        triplets->triplets = NULL;
    }
    else
    {
        triplets->triplets = results;
    }
    triplets->count = count;
    return triplets;
}

void free_triplets(triplets_t *triplets)
{
    if(triplets == NULL) return;
    free(triplets->triplets);
    free(triplets);
}

uint16_t gcd(uint16_t a, uint16_t b)
{
    while (b != 0)
    {
        uint16_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;    
}

bool is_duplicate(triplet_t *results, uint16_t count, uint16_t a, uint16_t b, uint16_t c) {
    for (uint16_t i = 0; i < count; i++) {
        if (results[i].a == a && results[i].b == b && results[i].c == c)
            return true;
    }
    return false;
}