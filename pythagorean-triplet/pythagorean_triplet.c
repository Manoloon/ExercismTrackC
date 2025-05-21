#include "pythagorean_triplet.h"
#include <stdlib.h>

triplets_t *triplets_with_sum(int sum)
{
    triplets_t* triplets = malloc(sizeof(triplets_t));
    if(triplets == NULL) return NULL;
    triplet_t* triplet = malloc(sizeof(triplet_t));
    if(triplet == NULL) return NULL;
    // sum = 1000 = 200 + 375 + 425 = a < b < c
    // a^2 + b^2 = c^2
    return triplets;
}
