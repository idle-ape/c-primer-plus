// wordcnt.c -- 统计字符数、单词数和行数
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '|'

int main(void)
{
    char c;              // 读入字符
    char prev;           // 读入的前一个字符数
    long n_chars = 0L;   // 字符数
    int n_lines;         // 行数
    int n_words;         // 单词数
    int p_lines;         // 不完整的行数
    bool inword = false; // 如果c在单词中，inword为true

    printf("Enter text to be analyzed(| to terminate):\n");
    prev = '\n';
    while ((c = getchar()) != STOP)
    {
        n_chars++;
        if (c == '\n')
        {
            n_lines++;
        }
        if (!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }

        if (isspace(c) && inword)
        {
            inword = false;
        }
        prev = c;
    }
    if (prev != '\n')
    {
        p_lines = 1;
    }

    printf("characters = %ld, words = %d, lines = %d\n", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
    return 0;
}
