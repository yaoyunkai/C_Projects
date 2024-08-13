#include <stdio.h>
#define SQUARES 64

void print_squares()
{
    int num = 1;

    while (num < 21)
    {
        printf("%4d %6d\n", num, num * num);
        num = num + 1;
    }
}


int wheat(void)
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;

    printf("square     grains       total     ");
    printf("fraction of \n");
    printf("           added        grains    ");
    printf("world total\n");
    total = current = 1.0;
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");

    return 0;
}


void sizet_usage()
{
    int n = 0;
    size_t intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);
}
