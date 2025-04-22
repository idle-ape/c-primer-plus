#include <stdio.h>

#define SPACE ' '

int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch == SPACE)
        {
            putchar(ch);
        }
        else
        {
            putchar(++ch);
        }
    }
    putchar(ch);

    return 0;
}