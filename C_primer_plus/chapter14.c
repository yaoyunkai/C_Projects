#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL  41
#define MAXAUTL  31

static char *s_gets(char *st, int n);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct Demo
{
    int a;
    double b;
    char c;
};

// typedef struct Demo s_demo;


void start_use_struct()
{
    // s_demo *data = NULL;
    // data = malloc(sizeof(s_demo));
    // if (NULL == data)
    // {
    //     printf("error");
    //     exit(EXIT_FAILURE);
    // }
    // data->a = 1234;
    // data->b = 12.34;
    // data->c = 'a';
    // printf("data addr: %p\n", data);
    // free(data);

    struct book library;
    // library num = NULL;
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf_s("%f", &library.value);

    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");


    struct book gift = {
        .value = 25.99,
        .author = "James Broadfool",
        .title = "Rue for the Toad"
    };

}

static char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
