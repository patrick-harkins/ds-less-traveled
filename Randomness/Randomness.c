#include "./Randomness.h"

int randint(int lower, int upper) {
    return rand() % (upper - lower) + lower;
}