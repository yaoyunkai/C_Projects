#include <stdio.h>
#include <stdlib.h>

#include "C_primer_plus/head.h"


int main(void)
{
#if defined(WIN32)
    printf("*** running from win32 platform ***\n");
    system("chcp 65001");
    // system("chcp");
    printf("\n");
#endif

    // start_use_array();
    use_array_and_point();
}
