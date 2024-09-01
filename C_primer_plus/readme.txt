ctrl + F9  build for clion

-----------------------------------------------

中文乱码 utf8 编译为 utf8的编码 然后输出为gbk导致乱码

将文件格式改为gbk, 或者console改为utf8 但是无效

    // printf("你好 世界\n"); // output to utf8 encoded data


------------------------------------

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

------------------------------------------------------------------------

2. 运算符

赋值运算符左侧必须引用一个存储位置。最简单的方法就是使用变量名。

数据对象 左值 右值 运算符


类型转换

promotion 升级

parameter 形参
argument  实参


--------------------------------------------------------------------------

#include <conio.h>

无缓冲输入 getche()  /  getch()


stdarg.h

尾递归(tail recursion) 相当于循环


---------------------------------------------------------------------------

创建一个指针时，系统只分配了存储指针本身的内存，并未分配存储数据的内存。

    int * pt;      // 未初始化的指针
    *pt = 5;       // 严重的错误


const int *  : 不能修改值
int const*   : 不能修改指针本身


-----------------------------------------------------------------------------

字符串

字符串常量
char 数组
指向插入的指针


字符串常量属于静态存储类别（static storage class）

注意最后的空字符。没有这个空字符，这就不是一个字符串，而是一个字符数组。