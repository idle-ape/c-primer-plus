#include <stdio.h>

// 安全版本的 gets()
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