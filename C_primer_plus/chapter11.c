#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG "I am a symbolic string constant."
#define NUM 50
#define MAX_LENGTH 81
#define STLEN 81

/*

two write ways:
    char x[xxxx]
    char *x


puts only for char[], and add newline for end

*/

void string_ptr_and_more();

void string_started() {
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


void string_ptr_and_more() {
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

    const char *pt1 = "Something is pointing at me.";
    const char *pt2 = MSG;

    char ar1[] = "Something is pointing at me.";
    const char ar2[] = "Something is pointing at me. ar2";

    char *ar2_ptr = ar2;

    printf("pt1 addr: %p \n", pt1);
    printf("MSG addr: %p \n", MSG);
    printf("pt2 addr: %p \n", pt2);

    printf("ar1 addr: %p \n", ar1);
    printf("ar2 addr: %p \n", ar2);

    ar1[0] = 'X';
    puts(ar1);

    while (*ar2_ptr != '\0') {
        putchar(*ar2_ptr++);
    }
    puts("");

    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
}

void use_string_with_malloc() {
    const int len = 27;
    char *str = malloc(len * sizeof(char));
    if (NULL == str) {
        exit(1);
    }

    // str[0] = 0xe4;
    // str[1] = 0xbd;
    // str[2] = 0xa0;
    // str[3] = 0xe5;
    // str[4] = 0xa5;
    // str[5] = 0xbd;
    // str[6] = 0x20;
    // str[7] = 0x20;
    // str[8] = 0x20;
    // str[9] = 0x0;

    str[0] = 0xc4;
    str[1] = 0xe3;
    str[2] = 0xba;
    str[3] = 0xc3;
    str[4] = 0x0;

    // int idx = 0;
    // for (int i = 65; i < 91; i++)
    // {
    //     printf("%d\n", i);
    //     str[idx++] = i;
    // }
    // printf("\n\n%d \n", idx);

    puts(str);
    free(str);
}


void puts_usage() {
    // char words[STLEN];
    //
    // puts("Enter a string, please.");
    // gets(words); // 典型用法
    // printf("Your string twice:\n");
    // printf("%s\n", words);
    // puts(words);
    // puts("Done.");

    char words[STLEN];

    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
}

void fit(char *string, unsigned int size) {
    if (strlen(string) > size) string[size] = '\0';
}


char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void string_function_usage() {
    // strlen
    char mesg[] = "Things should be as simple as possible, but not simpler.";
    puts(mesg);
    fit(mesg, 38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);

    // strcat
}
