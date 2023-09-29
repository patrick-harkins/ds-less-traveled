#ifndef RANDOMNESS_H
#define RANDOMNESS_H
#include <stdlib.h>
#include <time.h>

#define RAND_SEED() srand(time(NULL))

int randint(int, int);


#endif
