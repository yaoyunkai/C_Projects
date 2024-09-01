#include <stdio.h>
#include "head.h"

#define MSG "I am a symbolic string constant."
#define NUM 50
#define MAX_LENGTH 81

/*

two write ways:
    char x[xxxx]
    char *x


puts only for char[], and add newline for end

*/

void string_started()
{
    char words[MAX_LENGTH] = "I am a string in an array.";
    const char *pt1 = "Something is pointing at me.";
    const char *pt2 = "abcd";
    const char *pt3 = "efgh";

    printf("words addr: %p \n", words);
    printf("pt1   addr: %p \n", pt1);
    printf("pt2   addr: %p \n", pt2);
    printf("pt3   addr: %p \n", pt3);

    printf("MSG   addr: %p \n", MSG);
    // printf("NUM   addr: %p \n", NUM);

    puts("Here are some strings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    words[8] = 'p';
    puts(words);

    string_ptr_and_more();
}


void string_ptr_and_more()
{
    // We  addr
    // *"xx"  : the first char of
    printf("%s, %p, %c\n", "We", "are", *"space farers");

    // initialize
    const char m1[40] = "Limit yourself to one line's worth.";
    const char m2[40] = {
        'L', 'i', 'm', 'i', 't', ' ', 'y', 'o', 'u', 'r', 's', 'e', 'l',
        'f', ' ', 't', 'o', ' ', 'o', 'n', 'e', ' ', 'l', 'i', 'n', 'e',
        '\'', 's', ' ', 'w', 'o', 'r', 't', 'h', '.', '\0'
    };

    const char m3[] = "If you can't think of anything, fake it.";

    printf("the first char's int of m2 is %d \n", m2[0]);

    const char * pt1 = "Something is pointing at me.";
    const char ar1[] = "Something is pointing at me.";
}
