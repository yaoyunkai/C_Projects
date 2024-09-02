#include <stdio.h>

void use_external_from_chp12()
{
    extern int external_num;
    // extern int abc=0;
    // printf("abc is %d\n", abc);

    printf("the external_num is %d \n", external_num);
    external_num += 12;
    printf("the external_num is %d \n", external_num);
}

extern unsigned int rand0();

extern void srand0(int);

void use_rand0()
{
    srand0(78);
    for (int cnt = 0; cnt < 5; cnt++)
    {
        printf("%d\n", rand0());
    }
}
