#include <stdio.h>
#include <string.h>

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


/* pizza.c -- 在比萨饼程序中使用已定义的常量 */
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
