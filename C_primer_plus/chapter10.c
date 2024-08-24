#include <stdio.h>

void start_use_array()
{
    int powers[8] = {1, 2, 4, 6, 8, 16, 32, 64};

    int no_data[4];
    int i;

    for (i = 0; i < 4; i++)
    {
        printf("%2d%14d\n", i, no_data[i]);
    }
}

#define ARR_LEN 5


void use_array_and_point()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5};
    printf("array name:      arr point is %p \n", arr);
    printf("array first  element point is %p \n", &arr[0]);
    printf("array second element point is %p \n", &arr[1]);
}
