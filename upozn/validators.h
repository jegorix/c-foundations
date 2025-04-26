//
// Created by jegorix on 26.04.25.
//

#ifndef UPOZN_VALIDATORS_H
#define UPOZN_VALIDATORS_H
#include <stdio.h>

enum
{
    max_limit = 2147483647,
    min_limit = -2147483647,
    rand_max_limit = 1000000,
    rand_min_limit = -1000000,
};

int execute_verification(int min_limit, int max_limit);
#endif //UPOZN_VALIDATORS_H
