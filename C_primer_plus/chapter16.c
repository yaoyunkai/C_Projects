#include <float.h>
#include <stdio.h>

#define TWO 2
#define LONG_WORD "Consistency is the last refuge of the unimagina \
tive. - Oscar Wilde"

#define FOUR TWO*TWO
#define PX printf("X is %d. \n", x)
#define FMT "X is %d.\n"

#define SQUARE(X) ((X)*(X))
#define SQUARE1(X)  X * X
#define PR(X) printf("The result is %d.\n", X)

#define PSQR(x) printf("The square of "#x" is %d.\n", ((x)*(x)))

void function_marco();

void function_marco_with_sharp();

void pre_defined_marco();

void marco_usage() {
    printf("That's wonde\
rful!\n");
    printf("%s \n", LONG_WORD);

    int x = TWO;
    PX;
    x = FOUR;
    printf(FMT, x);

    printf("\n\n\n\n");
    function_marco();
    printf("\n\n\n\n");
    function_marco_with_sharp();
    printf("\n\n\n\n");
    pre_defined_marco();
}

void function_marco() {
    int x = 5;
    int z;

    printf("x = %d \n", x);
    z = SQUARE(3+1);
    printf("evaluating SQUARE(X): ");
    PR(z);

    z = SQUARE1(3 + 1);
    printf("evaluating SQUARE1(X): ");
    PR(z);

    PSQR(5+6);
}

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);

void function_marco_with_sharp() {
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    int x3 = 30;

    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);
}


void why_me() {
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}

void pre_defined_marco() {
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);

    why_me();
}
