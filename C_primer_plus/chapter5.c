#include <stdio.h>
#include "head.h"

#define SQUARES 64

void print_squares()
{
    int num = 1;

    while (num < 21)
    {
        printf("%4d %6d\n", num, num * num);
        num = num + 1;
    }
}


int wheat(void)
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;

    printf("square     grains       total     ");
    printf("fraction of \n");
    printf("           added        grains    ");
    printf("world total\n");
    total = current = 1.0;
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");

    return 0;
}


void sizet_usage()
{
    int n = 0;
    size_t intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);
}


void type_convert()
{
    char ch;
    int i;
    float fl;

    fl = i = ch = 'C';
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = ch + 1;
    i = fl + 2 * ch;
    fl = 2.0 * ch + i;
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = 1107;
    printf("Now ch = %c\n", ch);
    ch = 80.89;
    printf("Now ch = %c\n", ch);
}


/* echo.c -- 重复输入 */
#include <stdio.h>

int echo(void)
{
    char ch;

    while ((ch = getchar()) != '#')
        putchar(ch);

    return 0;
}

/*

递归


*/

/* recur.c -- 递归演示 */
void up_and_down(int n)
{
    printf("Level %d: n location %p\n", n, &n); // #1
    if (n < 4)
        up_and_down(n + 1);
    printf("LEVEL %d: n location %p\n", n, &n); // #2
}

void run_recursion(void)
{
    up_and_down(1);
}


long fact(int num)
{
    long ans;
    for (ans = 1; num > 1; num--)
    {
        ans *= num;
    }
    return ans;
}


long R_fact(int num)
{
    if (num > 0)
    {
        return num * R_fact(num - 1);
    }
    return 1;
}


// factor.c -- 使用循环和递归计算阶乘
int use_factor(void)
{
    int num;

    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf_s("%d", &num) == 1)
    {
        if (num < 0)
            printf("No negative numbers, please.\n");
        else if (num > 12)
            printf("Keep input under 13.\n");
        else
        {
            printf("loop: %d factorial = %ld\n",
                   num, fact(num));
            printf("recursion: %d factorial = %ld\n",
                   num, R_fact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");

    return 0;
}


void to_binary(unsigned long n)
{
    // printf("max len is %d", MAX_LEN);

    // 当前数的末尾 0 or 1
    unsigned short r = n % 2;
    if (n >= 2)
    {
        to_binary(n / 2);
    }
    putchar(r == 0 ? '0' : '1');
}


/* swap1.c -- 第1个版本的交换函数 */
void interchange(int u, int v)
{
    int temp;

    temp = u;
    u = v;
    v = temp;
}

void swap_int(int *a, int *b)
{
    const int num_a = *a;
    const int num_b = *b;

    *a = num_b;
    *b = num_a;
}

void run_inner_point(void *p)
{
    printf("point of *p is %p \n", p);
    printf("ponit of p self is %p \n", &p);
}

// 指针的用法
int run_swap(void)
{
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(x, y);
    printf("Now x = %d and y = %d.\n", x, y);

    printf("Originally x = %d and y = %d.\n", x, y);
    swap_int(&x, &y);
    printf("Now x = %d and y = %d.\n", x, y);

    int num = 67;
    printf("ponit for num is %p \n", &num);

    void *p = &num;
    printf("point of *p is %p \n", p);
    printf("ponit of p self is %p \n", &p);

    int num2 = *(int *) p;
    printf("num2 is %d \n", num2);

    run_inner_point(p);
    return 0;
}
