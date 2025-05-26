#include <stdio.h>

int main(void)
{
    int ch;
    puts("before character \";\":");
    while ((ch = getchar()) != ';')
    {
        putchar(ch);
    }
    puts("\n");
    ungetc(';', stdin);
    puts("after character \";\":");
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }

    return 0;
}