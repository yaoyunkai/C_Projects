#pragma once

#include <stddef.h>
#include <stdint.h>
#include <limits.h>

int platinum(void);

void show_int_range();

int show_diff_numbers_and_format();

void show_int_overflow();

void char_usage();

int use_stdint_and_inttype(void);

void use_float_double();

void print_float_bits(float f);

void print_double_bits(double d);

// chapter4

void talkback();

int praise2(void);

void pizza();

void show_limits();

void printf_usage();


uint64_t crc64(uint64_t crc, const unsigned char *s, uint64_t l);

int string2ll(const char *s, size_t slen, int64_t *value);

void printf_float_usage();

void show_printf_return_value();

void use_scanf();

void print_squares();

int wheat(void);

void sizet_usage();
