#include <stdio.h>
#include <stdlib.h>


void count_file_chars(int argc, char *argv[]) {
    int ch;
    FILE *fp = NULL;

    unsigned long count = 0;
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // fp = fopen(argv[1], "r");
    errno_t err = fopen_s(&fp, argv[1], "r");
    if (err) {
        printf("Can't open %s, %d", argv[1], err);
        exit(EXIT_FAILURE);
    }

    // if (NULL == fp)
    // {
    //     printf("Can't open %s\n", argv[1]);
    //     exit(EXIT_FAILURE);
    // }

    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", argv[1], count);
}
