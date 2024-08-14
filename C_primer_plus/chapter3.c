#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


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


int show_diff_numbers_and_format()
{
    long int estine;
    long johns;
    short int erns;
    short ribs;
    unsigned int s_count;
    unsigned players;
    unsigned long headcount;
    unsigned short yesvotes;
    long long ago;


    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig= %lld and not %ld\n", verybig, verybig);

    return 0;
}

void show_int_overflow()
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j + 1, j + 2);
}


void char_usage()
{
    char a, b, c;
    a = 'A';
    b = 66;
    c = '\n';

    printf("a: %c, b: %c, c: %c", a, b, c);
}


int use_stdint_and_inttype(void)
{
    int32_t me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);

    return 0;
}

void use_float_double()
{
    // float noah, jonah;
    // double trouble;
    // float planck = 6.63e-34;
    // long double gnp;
    printf("long double: %lu byte\n", sizeof(long double));
    printf("     double: %lu byte\n", sizeof(double));

    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

    double num1 = 0.30 - 0.29;

    printf("%f can be written %e\n", aboat, aboat);
    printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
    printf("%f can be written %e\n", abet, abet);
    printf("%Lf can be written %Le\n", dip, dip);

    printf("num1 is %f \n", num1);

    float toobig = 3.4E38 * 100.0f;
    printf("%e\n", toobig); //  inf

    // print_float_bits(toobig);
    // print_float_bits(3.14F);
    // print_double_bits(3.14);


    float b = 2.0e20 + 1.0;
    float a = b - 2.0e20;
    printf("%f \n", a);
}
