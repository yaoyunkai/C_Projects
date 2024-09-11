/*

bit

&=
|=

*/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 100

extern char *itobs(int, char *);

extern void show_bstr(const char *);

void itobs_char(char n, char *ps)
{
    const static int size = CHAR_BIT * sizeof(char);

    for (int i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // Oct
    ps[size] = '\0';
}


void use_bit_option()
{
    char bin_str[LEN];

    printf("byte size of short is %lld\n", sizeof(short));

    char num = 0b11011100;
    itobs_char(num, bin_str);
    printf("num result = ");
    show_bstr(bin_str);

    char num_neg = ~num;
    itobs_char(num_neg, bin_str);
    printf("~num result = ");
    show_bstr(bin_str);

    char num_and = num & 0b00001111;
    itobs_char(num_and, bin_str);
    printf("num & 00001111 result = ");
    show_bstr(bin_str);

    char num_or = num | 0b00001111;
    itobs_char(num_or, bin_str);
    printf("num | 00001111 result = ");
    show_bstr(bin_str);

    char num_xor = num ^ 0b00001111;
    itobs_char(num_xor, bin_str);
    printf("num ^ 00001111 result = ");
    show_bstr(bin_str);

    char num_left = num << 2;
    itobs_char(num_left, bin_str);
    printf("num left  << result is %s \n", bin_str);

    char num_right = num >> 2;
    itobs_char(num_right, bin_str);
    printf("num right >> result is %s \n", bin_str);

    char num1 = 0b00111010;
    num1 = num1 >> 2;
    itobs_char(num1, bin_str);
    printf("num1 right >> result is %s \n", bin_str);
}

void use_bit_field()
{
    struct
    {
        unsigned int autfd: 1;
        unsigned int bldfc: 1;
        unsigned int undln: 1;
        unsigned int itals: 1;
    } prnt;

    struct
    {
        unsigned int code1: 2;
        unsigned int code2: 2;
        unsigned int code3: 8;
    } prcode;

    prnt.itals = 0;
    prnt.undln = 1;
}

// style of line
#define SOLID      0
#define DOTTED     1
#define DASHED     2

#define BULE       4
#define GREEN      2
#define RED        1

#define BLACK      0
#define YELLOW     (RED   | GREEN)
#define MAGENTA    (RED   | BULE)
#define CYAN       (GREEN | BULE)
#define WHITE      (RED   | GREEN |BULE)

#define OPAQUE        0x1
#define FILL_BLUE     0x8
#define FILL_GREEN    0x4
#define FILL_RED      0x2
#define FILL_MASK     0xE
#define BORDER        0x100
#define BORDER_BLUE   0x800
#define BORDER_GREEN  0x400
#define BORDER_RED    0x200
#define BORDER_MASK   0xE00
#define B_SOLID       0
#define B_DOTTED      0x1000
#define B_DASHED      0x2000
#define STYLE_MASK    0x3000


struct box_props
{
    bool opaque: 1;
    unsigned int fill_color: 3;
    unsigned int : 4;
    bool show_border: 1;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
    unsigned int : 2;
};


const char *colors[8] = {
    "black", "red", "green", "yellow",
    "blue", "magenta", "cyan", "white"
};

void show_settings(const struct box_props *pb)
{
    printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style)
    {
        case SOLID: printf("solid.\n");
            break;
        case DOTTED: printf("dotted.\n");
            break;
        case DASHED: printf("dashed.\n");
            break;
        default: printf("unknown type.\n");
    }
}

void show_settings1(unsigned short us)
{
    printf("box is %s.\n",
           (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    printf("The fill color is %s.\n",
           colors[(us >> 1) & 07]);
    printf("Border %s.\n",
           (us & BORDER) == BORDER ? "shown" : "not shown");
    printf("The border style is ");
    switch (us & STYLE_MASK)
    {
        case B_SOLID: printf("solid.\n");
            break;
        case B_DOTTED: printf("dotted.\n");
            break;
        case B_DASHED: printf("dashed.\n");
            break;
        default: printf("unknown type.\n");
    }
    printf("The border color is %s.\n",
           colors[(us >> 9) & 07]);
}


void use_bitfield()
{
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);
}


union Views
{
    struct box_props st_view;
    unsigned short us_view;
};

void use_union_with_bitfield()
{
    union Views box = {
        {true, YELLOW, true, GREEN, DASHED}
    };
    char bin_str[100];

    printf("Original box settings: \n");
    show_settings(&box.st_view);

    printf("Box Settings with integer \n");
    show_settings1(box.us_view);
}
