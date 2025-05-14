#include <stdio.h>
#include <string.h>
#include "s_gets.h"

#define SIZE 40
#define LIM 5

int main(void)
{
    char qwords[LIM][SIZE];
    int i = 0;
    char tmp[SIZE];

    printf("Enter %d words that beginning with q:\n", LIM);
    while (i < LIM && s_gets(tmp, SIZE))
    {
        if (tmp[0] != 'q')
        {
            printf("%s doesn't begin with q!\n", tmp);
        }
        else
        {
            /*
                strcpy()和 strcat()都有同样的问题，它们都不能检查目标空间是否能容 纳源字符串的副本。
                拷贝字符串用 strncpy()更安全，该函数的第 3 个参数指 明可拷贝的最大字符数。
                    1、如果source中的字符数小 于n，则拷贝整个字符串，包括空字符。
                    2、如果拷贝到第n个字符时还未拷贝完整个源字符串，就不会拷贝空字符。
                所以，拷贝的副本中不一定有空字符。鉴于此，该程序把 n 设置为比 目标数组大小少1(TARGSIZE-1)，然后把数组最后一个元素设置为空字 符:
                strncpy(qwords[i], temp, TARGSIZE - 1);
                qwords[i][TARGSIZE - 1] = '\0';

            */
            strcpy(qwords[i], tmp);
            i++;
        }
    }

    printf("Here are the words accepted:\n");
    for (int i = 0; i < LIM; i++)
    {
        printf("%s\n", qwords[i]); // equal to puts(qwords[i])
    }

    return 0;
}
