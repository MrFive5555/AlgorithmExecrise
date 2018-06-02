#include "Random.h"

#include <cstdlib>
#include <ctime>

bool Random::initRandom = false;

int Random::rand() {
    if (!initRandom) {
        srand((unsigned)time(NULL));
        initRandom = true;
    }
    return ::rand();
}