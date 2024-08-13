cmake_minimum_required(VERSION 3.28)
project(Simple1 C)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_CXX_CHARSET "UTF-8")

add_executable(Simple1
        main.c
        C_primer_plus/head.h
        C_primer_plus/print_float_bits.c
        C_primer_plus/chapter3.c
        C_primer_plus/chapter4.c
        C_primer_plus/crc64.c
        C_primer_plus/utils.c
        C_primer_plus/chapter5.c

)
