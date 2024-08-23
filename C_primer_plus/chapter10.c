#include <stdio.h>

void start_use_array()
{
    int powers[8] = {1, 2, 4, 6, 8, 16, 32, 64};

    int no_data[4];
    int i;

    for (i =0; i < 4; i++)
    {
        printf("%2d%14d\n", i, no_data[i]);
    }
}
