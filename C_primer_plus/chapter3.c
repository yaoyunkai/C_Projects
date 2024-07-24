#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#include "head.h"

int platinum(void) {
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

void show_int_range() {
    printf("int size: %lu byte\n", sizeof(int));
    printf("short size: %lu byte\n", sizeof(short int));
    printf("long size: %lu byte\n", sizeof(long int));
    printf("long long size: %lu byte\n", sizeof(long long int));
}


/* bases.c--以十进制、八进制、十六进制打印十进制数100 */
int show_diff_numbers_and_format() {
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

    unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig= %lld and not %ld\n", verybig, verybig);

    return 0;
}

void show_int_overflow() {
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j + 1, j + 2);
}


void char_usage() {
    char a, b, c;
    a = 'A';
    b = 66;
    c = '\n';

    printf("a: %c, b: %c, c: %c", a, b, c);
}


int use_stdint_and_inttype(void) {
    // me32是一个32位有符号整型变量
    int32_t me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);

    return 0;
}
