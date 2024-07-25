#include <stdint.h>
#include <stdio.h>

typedef union v32_union {
    float f;
    uint32_t u;
} v32;

typedef union v64_union {
    double f;
    uint64_t u;
} v64;

void print_float_bits(float f)
{
    printf("float %f bits: ", f);
    v32 v;
    v.f = f;
    uint32_t mask = 1 << 31;
    do {
        if (mask == 0x40000000 || mask == 0x400000) putchar(' ');
        putchar(v.u & mask ? '1' : '0');
    } while (mask >>= 1);
    putchar('\n');
}

void print_double_bits(double d)
{
    printf("double %.12f bits: ", d);
    v64 v;
    v.f = d;
    uint64_t mask = 1ULL << 63;
    int count = 63;
    do {
        if (mask == 0x4000000000000000 || mask == 0x8000000000000) putchar(' ');
        putchar(v.u & mask ? '1' : '0');
        count--;
    } while (mask >>= 1);
    putchar('\n');
}
