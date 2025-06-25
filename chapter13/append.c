/* append.c -- 把文件附加到另一个文件末尾 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../chapter11/s_gets.h"

#define SLEN 81
#define BUFSIZE 4096

void append(FILE *src, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    int files = 0;       // 附加文件的数量
    char file_dst[SLEN]; // 目标文件名
    char file_src[SLEN]; // 源文件名
    int ch;

    printf("Enter name of destination file: ");
    s_gets(file_dst, SLEN);
    if ((dst = fopen(file_dst, "a+")) == NULL)
    {
        fprintf(stderr, "Can't not open %s\n", file_dst);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(dst, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fprintf(stderr, "Can't create output buffer\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file(empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_dst) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((src = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(src, NULL, _IOFBF, BUFSIZ) != 0)
            {
                fprintf(stderr, "Can't create input buffer\n");
                continue;
            }

            append(src, dst);
            if (ferror(src) != 0)
                fprintf(stderr, "Error in reading file %s\n", file_src);

            if (ferror(dst) != 0)
                fprintf(stderr, "Error in writing file %s\n", file_dst);

            fclose(src);
            files++;

            printf("File %s appended.\n", file_src);
            puts("Next file(empty line to quit):");
        }
    }

    printf("Done appending. %d files appended.\n", files);
    rewind(dst);

    printf("%s contents:\n", file_dst);
    while ((ch = getc(dst)) != EOF)
        putchar(ch);

    printf("Done displaying.\n");
    fclose(dst);

    return 0;
}

void append(FILE *src, FILE *dst)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, dst);
    }
}