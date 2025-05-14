/* sort_str.c -- 读入字符串，并排序字符串 */
#include <stdio.h>
#include <string.h>
#include "s_gets.h"

#define SIZE 81 // 限制字符串长度，包括\0
#define LIM 20  // 可读入的行数
#define HALT "" // 空字符串停止输入

void strsort(char *strings[], int num); // 字符串排序函数

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");

    while (ct < LIM && s_gets(input[ct], SIZE) && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    strsort(ptstr, ct);

    printf("Here's the sorted list.\n");

    for (int i = 0; i < ct; i++)
    {
        puts(ptstr[i]);
    }

    return 0;
}

void strsort(char *strings[], int n)
{
    char *tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }
}