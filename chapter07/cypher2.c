#include <stdio.h>
#include <ctype.h> // 专门处理字符的函数，ctype.h头文件包含了这些 函数的原型

#define SPACE ' '

int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            putchar(++ch);
        }
        else
        {
            putchar(ch);
        }
    }
    putchar(ch);

    return 0;
}