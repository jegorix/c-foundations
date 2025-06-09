//
// Created by jegorix on 26.04.25.
//

#include "animations.h"
void clearScreen()
{
    printf("\033c");
    fflush(stdout);
}

void loadingAnimation(int dots, int delay_ms)
{
    for(int i = 0; i < dots; i++)
    {

        printf(".");
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
    printf("\n");
}

