#include <stdio.h>
#include "head.h"

int platinum(void)
{
    float weight;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");

    scanf_s("%f", &weight);

    float value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;
}

void show_int_range()
{   
    int num = 443;
    printf("the num is %d \n", num);
    printf("the pointer of num is %p \n", &num);

    printf("int size: %lld byte\n", sizeof(int));
    printf("short size: %lld byte\n", sizeof(short int));
    printf("long size: %lld byte\n", sizeof(long int));
    printf("long long size: %lld byte\n", sizeof(long long int));
}
