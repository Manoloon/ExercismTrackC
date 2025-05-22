#include "pythagorean_triplet.h"
#include <stdlib.h>

triplets_t *triplets_with_sum(int sum)
{
    if(sum < 12) return NULL;
    triplets_t* triplets = malloc(sizeof(triplets_t));
    if(triplets == NULL) return NULL;
    triplet_t* triplet = malloc(sizeof(triplet_t));
    if(triplet == NULL) return NULL;

        int c = (sum / 2) - 1;
        int b = (sum - c)/2 + 1;
        int a = (sum -c -b) -1;
        if((a < b && b < c) && (a + b + c == sum))
        {
            triplet->a = a;
            triplet->b = b;
            triplet->c = c;
            triplets->count = 1;
            triplets->triplets = triplet;
        }
    return triplets;
}

void free_triplets(triplets_t *triplets)
{
    if(triplets == NULL) return;
    free(triplets->triplets);
    free(triplets);
}
