/*
    strconvert.c -- 使用 strtol() 转换字符串

    #include <stdlib.h>
    long strtol(const char *restrict nptr,
            char **_Nullable restrict endptr, int base);
    long long strtoll(const char *restrict nptr,
            char **_Nullable restrict endptr, int base);


    If endptr is not NULL, and the base is supported, strtol() stores
    the address of the first invalid character in *endptr.  If there
    were no digits at all, strtol() stores the original value of nptr
    in *endptr (and returns 0).  In particular, if *nptr is not '\0'
    but **endptr is '\0' on return, the entire string is valid.
*/
#include <stdio.h>
#include <stdlib.h>
#include "s_gets.h"

#define LIM 30

int main(int argc, char *argv[])
{
    char number[LIM];
    char *end;
    long value;

    puts("Enter a number(empty line to quit):");
    while (s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10);
        printf("base 10 input, base 10 output: %ld, stop at: %s[%d]\n", value, end, *end);

        value = strtol(number, &end, 16);
        printf("base 16 input, base 16 output: %ld, stop at: %s[%d]\n", value, end, *end);

        puts("Next number:");
    }

    puts("Bye!");

    return 0;
}
