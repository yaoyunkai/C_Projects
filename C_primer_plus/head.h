#pragma once

#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#define MAX_LEN 50

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

void type_convert();

int echo(void);

void run_recursion(void);

int use_factor(void);

void to_binary(unsigned long n);

int run_swap(void);

void start_use_array();

void use_array_and_point();

void point_add_usage();

void run_with_sum_array();

void option_of_opint();

void const_usage();

void multi_array();

void string_started();

void string_ptr_and_more();

void use_string_with_malloc();

void string_function_usage();

void use_self_external_num();

void use_external_from_chp12();

void use_rand0();


extern int roll_count;

int roll_n_dice(int dice, int sides);

void manydice();

void dyn_array();

void count_file_chars(int, char *[]);

void start_use_struct();

void start_use_struct_array();

void use_struct_getinfo();

float findSQRT(int number);

void use_bit_option();

void use_bitfield();

void use_union_with_bitfield();
