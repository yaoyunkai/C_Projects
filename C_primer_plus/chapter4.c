#include <stdio.h>
#include <string.h>

#define DENSITY 62.4     // 人体密度（单位：磅/立方英尺）
#define PRAISE "You are an extraordinary being."

void talkback()
{
    float weight, volume;
    int size, letters;
    char name[40]; // name是一个可容纳40个字符的数组

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
