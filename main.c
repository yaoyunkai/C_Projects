#include  <stdio.h>
#include <stdlib.h>

#include "C_primer_plus/head.h"

int main(void) {
#if defined(WIN32)
    printf("*** running from win32 platform ***\n");
    system("chcp 65001");
    printf("\n");
#endif

    // platinum();

    show_int_range();
}
