#include <stdio.h>

#include "C_primer_plus/head.h"

int main(int argc, char *argv[])
{
    // #if defined(WIN32)
    //     printf("*** running from win32 platform ***\n");
    //     system("chcp 65001");
    //     // system("chcp");
    //     printf("\n");
    // #endif

    float num = 3.1415926f;
    print_float_bits(num);
}
