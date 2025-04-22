#include <stdio.h>
#include <ctype.h>

#define STOP '#'

int main(void)
{
    // 1
    char ch;
    // int n_space = 0, n_lines = 0, n_chars = 0; // 切记变量要初始化
    // printf("Please enter something here:\n");
    // while ((ch = getchar()) != STOP)
    // {
    //     if (ch == '\n')
    //     {
    //         n_lines++;
    //     }
    //     else if (isspace(ch))
    //     {
    //         n_space++;
    //     }
    //     else
    //     {
    //         n_chars++;
    //     }
    // }
    // printf("total space: %d, total lines: %d, total characters: %d\n", n_space, n_lines, n_chars);
    // printf("\n");

    // 2
    char c[8];
    int i = 0, e = 8;
    while ((ch = getchar()) != STOP)
    {
        c[i] = ch;
        if ((i + 1) % 8 == 0)
        {
            for (int j = 0; j < e; j++)
            {
                printf("%c", c[j]);
            }
            printf("\n");
            i = 0;
        }
        else
        {
            i++;
        }
    }
    if (i > 0)
    {
        for (int n = 0; n < i; n++)
        {
            printf("%c", c[n]);
        }
    }
}