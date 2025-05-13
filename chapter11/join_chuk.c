/*jion_chul=k.c -- 拼接两个字符串，检查第1个数组的大小*/
#include <stdio.h>
#include <string.h>

#define SIZE 30
#define BUGSIZE 13

char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;
    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
    {
        strcat(flower, addon);
    }
    puts(flower);

    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    /*
    fgets()读取指定长度（n-1）的文本并写入到指定的地址，有可能有两种情况：
        1、提前读到了换行符
        2、读了n-1个字符之后还没读完（第n个设置为\0）
    */
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            // 这里属于还没读完的情况，清空输入缓冲区
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}