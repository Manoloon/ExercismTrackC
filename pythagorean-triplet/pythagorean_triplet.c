#include "pythagorean_triplet.h"
#include <stdlib.h>
#include <stdio.h>

triplets_t *triplets_with_sum(int sum)
{
    if(sum < 12) return NULL;
    triplets_t* triplets = malloc(sizeof(triplets_t));
    if(triplets == NULL) return NULL;
    uint16_t halfSum = sum * 0.5;
    uint16_t count = 0;
    for(uint16_t m = 2; m < halfSum;m++)
    {
        for(uint16_t n = 1; n < m;n++)
        {
            uint16_t a = m * m - n * n;
            uint16_t b = 2 * m * n;
            uint16_t c = m * m + n * n;
            if( a+b+c == sum)
            {
                printf("a = %d, b = %d, c = %d\n",a,b,c);
                triplet_t* triplet = malloc(sizeof(triplet_t));
                if(triplet == NULL) return NULL;
                triplet->a = a;
                triplet->b = b;
                triplet->c = c;
                count++;
                triplets->triplets = triplet;
            }
        }
    }
    printf("count = %d\n",count);
    triplets->count = count;
    return triplets;
}

void free_triplets(triplets_t *triplets)
{
    if(triplets == NULL) return;
    free(triplets->triplets);
    free(triplets);
}
