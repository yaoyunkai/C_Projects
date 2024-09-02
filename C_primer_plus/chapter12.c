#include <stdio.h>
#include <stdlib.h>

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
