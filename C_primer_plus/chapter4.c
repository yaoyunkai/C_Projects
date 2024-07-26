#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

#define PAGES 959
#define PI 3.14159
#define DENSITY 62.4
#define PRAISE "You are an extraordinary being."

void talkback()
{
    float weight, volume;
    int size, letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf_s("%s", name, sizeof(name));

    printf("%s, what's your weight in pounds?\n", name);
    scanf_s("%f", &weight);

    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;

    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);
}

/*
 * 中文注释
 *
 */
int praise2(void)
{
    char name[40];

    printf("What's your name? ");
    scanf_s("%s", name, sizeof(name));

    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %zd letters ", strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);

    return 0;
}


void pizza()
{
    float area, circum, radius;

    printf("你的披萨的半径是: \n");
    scanf_s("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("周长 = %1.2f, 面积 = %1.2f\n", circum, area);
}


void show_limits()
{
    printf("Maximum int value on this system = %d\n", INT_MAX);

    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
}


void printf_usage()
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;

    printf("The %d contestants ate %f berry pies.\n", number, pies);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing,\n");
    printf("%c%d\n", '$', 2 * cost);

    // printf("The score was Squids %d, Slugs %d.\n", cost);

    printf("abc---------------\n");
    printf("这是一段中文\n");
    printf("*%d*\n", PAGES);

    printf("*%2d*\n", PAGES);
    printf("*%+10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);
}
