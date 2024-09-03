#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int external_num = 10;

// internal link, static storage
static unsigned long int next = 1;


void use_self_external_num()
{
    printf("the external_num is %d from self\n", external_num);
}

unsigned int rand0()
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void srand0(int value)
{
    next = value;
}

int roll_count = 0;

static int rollem(int sides)
{
    int roll = rand() % sides + 1;
    ++roll_count;
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (int d = 0; d < dice; d++)
    {
        total += rollem(sides);
    }

    return total;
}


void manydice()
{
    int dice, roll;
    int sides;
    int status;

    srand((unsigned int) time(0));
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf_s("%d", &sides) == 1 && sides > 0)
    {
        printf("How many dice?\n");
        if ((status = scanf_s("%d", &dice)) != 1)
        {
            if (status == EOF)
                break;
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                printf("How many sides? Enter 0 to stop.\n");
                continue;
            }
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
}

void dyn_array()
{
    double *ptd;
    int max;
    int number;
    int i = 0;

    puts("What is the maximum number of type double entries?");
    if (scanf_s("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }

    puts("Enter the values (q to quit):");
    while (i < max && scanf_s("%lf", &ptd[i]) == 1) ++i;

    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; i++)
    {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6) putchar('\n');
    }
    if (i % 7 != 0) putchar('\n');
    puts("Done.");
    free(ptd);
}
