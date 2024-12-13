#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXTITL  41
#define MAXAUTL  31
#define MAXBKS  100

static char *s_gets(char *st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct Demo {
    int a;
    double b;
    char c;
};

// typedef struct Demo s_demo;


void start_use_struct() {
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

void start_use_struct_array() {
    struct book library[MAXBKS];

    struct book *ptr = library;
    struct book *pt1 = &library[0];

    printf("ptr addr: %p\n", ptr);
    printf("ptr+1 addr: %p\n", ptr + 1);
    printf("pt1 addr: %p\n", pt1);
    printf("pt1+1 addr: %p\n", pt1 + 1);

    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf_s("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
    } else
        printf("No books? Too bad.\n");
}


static char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}


struct namect {
    char *fname;
    char *lname;
    int letters;
};

void getinfo(struct namect *ptr) {
    char temp[50];
    printf("Please enter your first name.\n");
    s_gets(temp, 50);

    ptr->fname = malloc(strlen(temp) + 1);
    strcpy_s(ptr->fname, strlen(temp) + 1, temp);

    printf("Please enter your last name.\n");
    s_gets(temp, 50);
    ptr->lname = malloc(strlen(temp) + 1);
    strcpy_s(ptr->lname, strlen(temp) + 1, temp);
}

void showinfo(const struct namect *ptr) {
    printf("%s, %s, your name contains %d letters.\n",
           ptr->fname, ptr->lname, ptr->letters);
}

void cleanup(struct namect *ptr) {
    free(ptr->fname);
    free(ptr->lname);
}

void use_struct_getinfo() {
    struct namect person;

    getinfo(&person);
    person.letters = strlen(person.fname) + strlen(person.lname);
    showinfo(&person);
}

/*
========================================================================
 */

void use_enum() {
    enum spectrum { red, orange, yellow, green, blue };
    enum spectrum color;
    color = red;

    enum levels { low = 100, medium = 500, high = 2000 };

    printf("red = %d, orange = %d\n", red, orange);

    if (color == yellow) {
        printf("color is not yellow");
    } else {
        printf("color is yellow");
    }
}

void ToUpper(char *);

inline void ToUpper(char *val) {
    printf("call toUpper for %s\n", val);
}

void ToLower(char *);

int round(double);

void use_function_point() {
    void (*pf)(char *);
    // pf = ToLower;
    pf = ToUpper;
    // pf = round;
    pf("xxxxx");
}

char *itobs(int, char *);

void show_bstr(const char *);

void run_show_bstr() {
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number = 655;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    // while (scanf_s("%d", &number) == 1)
    // {
    itobs(number, bin_str);
    printf("%d is ", number);
    show_bstr(bin_str);
    putchar('\n');
    // }
    // puts("Bye!");
}

char *itobs(int n, char *ps) {
    const static int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char *str) {
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
    putchar('\n');
}
