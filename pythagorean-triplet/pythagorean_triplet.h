#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H
#include <stdint.h>
#include <stdbool.h>
typedef struct triplet_t
{
    int a,b,c;
}triplet_t;
typedef struct triplets_t
{
    triplet_t* triplets;
    uint16_t count;
}triplets_t;

triplets_t* triplets_with_sum(int sum);
void free_triplets(triplets_t* triplets);
uint16_t gcd(uint16_t a, uint16_t b);
bool is_duplicate(triplet_t *results, uint16_t count, uint16_t a, uint16_t b, uint16_t c);
#endif
