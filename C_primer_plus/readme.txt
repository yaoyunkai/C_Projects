ctrl + F9  build for clion

=========================================================================================

中文乱码 utf8 编译为 utf8的编码 然后输出为gbk导致乱码

将文件格式改为gbk, 或者console改为utf8 但是无效

    // printf("你好 世界\n"); // output to utf8 encoded data


=========================================================================================

1. 声明

const 关键字
    只读变量

printf  %lu 表示:
    %p表示输出这个指针,
    %d表示后面的输出类型为有符号的10进制整形，
    %u表示无符号10进制整型，
    %lu表示输出无符号长整型整数

    size_t 称为 underlying type
    为sizeof运算符的返回类型添加了%zd转换说明  / %zu

int  long short unsigned char float double // signed void

printf 格式化 https://zh.cppreference.com/w/c/io/fprintf


stdint.h和inttypes.h

 limits.h和float.h分别提供了与整数类型和浮点类型大小限制相关的详细信息。

printf的修饰符和标记

    转换不匹配

printf的返回值 表示打印的字节数

=========================================================================================

2. 运算符

赋值运算符左侧必须引用一个存储位置。最简单的方法就是使用变量名。

数据对象 左值 右值 运算符


类型转换

promotion 升级

parameter 形参
argument  实参


=========================================================================================

#include <conio.h>

无缓冲输入 getche()  /  getch()


stdarg.h

尾递归(tail recursion) 相当于循环


=========================================================================================

创建一个指针时，系统只分配了存储指针本身的内存，并未分配存储数据的内存。

    int * pt;      // 未初始化的指针
    *pt = 5;       // 严重的错误


const int *  : 不能修改值
int const*   : 不能修改指针本身


=========================================================================================

字符串

字符串常量
char 数组
指向插入的指针


字符串常量属于静态存储类别（static storage class）

注意最后的空字符。没有这个空字符，这就不是一个字符串，而是一个字符数组。


    const char * pt1 = "Something is pointing at me.";
    const char ar1[] = "Something is pointing at me.";   // 这是常量 ??????
    const char ar2[] = "Something is pointing at me.";

pt1 指向了静态内存区的某个地址
ar1
ar2  由于字符串常量copy了一分到局部内存，所有地址是 局部地址

如果打算修改字符串，就不要用指针指向字符串字面量。

如果要用数组表示一系列待显示的字符串，请使用指针数组，因为它比二维字符数组的效率高。

gets

fgets
fputs

strlen()、strcat()、strcmp()、strncmp()、strcpy()和strncpy()


=========================================================================================

存储器，作用域和链接属性

存储类别、链接和内存管理

auto、extern、static、register、const、volatile、restricted、_Thread_local、_Atomic

可以用存储期（storage duration）描述对象，所谓存储期是指对象在内存中保留了多长时间。
标识符用于访问对象，可以用作用域（scope）和链接（linkage）描述标识符，
标识符的作用域和链接表明了程序的哪些部分可以使用它。


链接属性：外部链接、内部链接或无链接

具有块作用域、函数作用域或函数原型作用域的变量都是无链接变量。

具有文件作用域的变量可以是外部链接或内部链接。
外部链接变量可以在多文件程序中使用，内部链接变量只能在一个翻译单元中使用。

文件作用域变量是内部链接还是外部链接？可以查看外部定义中是否使用了存储类别说明符static

作用域和链接描述了标识符的可见性

存储期描述了通过这些标识符访问的对象的生存期。
C对象有4种存储期：静态存储期、线程存储期、自动存储期、动态分配存储期。

块作用域变量也能具有静态存储期: static


为了表明有意覆盖一个外部变量定义，或者强调不要把该变量改为其他存储类别，
可以显式使用关键字auto

** 除了一个定义式声明外，其他声明都要使用extern关键字。而且，只有定义式声明才能初始化变量。**

const float *pt   创建pt指向不能被改变的值
float* const pt   指针pt本身的值不能更改

const float * const pt;


=========================================================================================

fread
fwrite

=========================================================================================

struct 结构体名 {
    若干数据项；
} 结构体变量名 ；

typedef struct complex {
     float real;
     float imag;
} COMPLEX;

组合后的结构声明和结构变量定义不需要使用结构标记

.比&的优先级高


struct demo demo;
struct demo* ptr;

(*ptr).value;

和数组不同的是，结构变量名并不是结构变量的地址，因此要在结构变量名前面加上&运算符。

union ?????????????

*** 函数指针 和 union ***

位字段


=========================================================================================

预处理

1. 处理换行符

printf("That's wond\
               erful!\n");

printf("That's wonderful\n!");

类对象宏
类函数宏


记号型字符串

重定义宏


宏的参数  #

## 运算符

// glue.c -- 使用##运算符
#include <stdio.h>
#define XNAME(n) x ## n



// predef.c -- 预定义宏和预定义标识符
#include <stdio.h>
void why_me();

int main()
{
　　 printf("The file is %s.\n", _ _FILE_ _);
　　 printf("The date is %s.\n", _ _DATE_ _);
　　 printf("The time is %s.\n", _ _TIME_ _);
　　 printf("The version is %ld.\n", _ _STDC_VERSION_ _);
　　 printf("This is line %d.\n", _ _LINE_ _);
　　 printf("This function is %s\n", _ _func_ _);
　　 why_me();

　　 return 0;
}

void why_me()
{
　　 printf("This function is %s\n", _ _func_ _);
　　 printf("This is line %d.\n", _ _LINE_ _);
}