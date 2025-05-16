#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char *read_a_word();
char *my_strchr(char *str, char c);
char *string_in(char *str, char *substr);
void str_revert(char *str);
int my_atoi(char *str);

int main(void)
{
    // char input[MAX];
    // int n = 0;
    // while (n < MAX)
    // {
    //     char c = getchar();
    //     if (isspace(c))
    //     {
    //         break;
    //     }
    //     input[n++] = c;
    // }
    // printf("Below is what you entered:\n%s\n", input);

    // char *word = read_a_word();
    // printf("word read: %s, addr: %p\n", word, word);
    // free(word);

    // char *str = "this is a text.";
    // char *addr = my_strchr(str, 'a');
    // printf("str addr: %p, find addr: %p, text: %s\n", str, addr, addr);
    char *str = "Hello, world!";
    char *substr = "or";
    printf("str: %s, str addr: %p, substr: %s, find addr: %p\n", str, str, substr, string_in(str, substr));

    // 这里不以 char *string = "Hello, World";的方式定义字符串，因为这种方式定义的字符串指向的是一个字符串常量
    // 而字符串常量存储在只读内存区域（.rodata 段），不能修改。
    // 或者用动态内存分配的方式：char *str2 = strdup("Hello, world!"); 这样就会把内存分配在堆上，切记要  free(str2);
    char string[] = "Hello, World";
    printf("str: %s, str addr: %p\n", string, string);
    str_revert(string);
    printf("str after revert: %s, revert str addr: %p\n", string, string);

    printf("my_atoi(\"129\") returns: %d\n", my_atoi("129"));

    return 0;
}

/*
设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并丢弃输入行中的其余字符。
该函数应该跳过第1个非空白字符前面的所有空白。
将一个单词定义为没有空白、制表符或换行符的字符序列。
*/
char *read_a_word()
{
    int c;
    int i = 0;
    char *word = (char *)malloc(sizeof(char[MAX]));
    // 跳过前导空白字符
    while ((c = getchar()) != EOF && isspace(c))
    {
        continue;
    }

    // 检查是否到达文件末尾
    if (c == EOF)
    {
        return 0;
    }

    // 读取单词字符
    while (c != EOF && !isspace(c))
    {
        if (i < MAX - 1)
        { // 保留一个位置给'\0'
            word[i++] = c;
        }
        c = getchar();
    }

    word[i] = '\0'; // 添加字符串结束符

    // 丢弃行中剩余字符
    while (c != EOF && c != '\n')
    {
        c = getchar();
    }
    printf("word addr: %p\n", word);
    return word;
}

/*
设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查 找第2个函数形参指定的字符首次出现的位置。
如果成功，该函数返指向该 字符的指针，如果在字符串中未找到指定字符，则返回空指针(该函数的功 能与 strchr()函数相同)。
*/
char *my_strchr(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

/*
如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始的地址。
例如，string_in("hats", "at")将返回hats中a的地址。否则，该函数返回空指针。
Linux 内核的实现：https://github.com/torvalds/linux/blob/fee3e843b309444f48157e2188efa6818bae85cf/arch/x86/boot/string.c#L163
*/
char *string_in(char *str, char *substr)
{
    char *start = str;
    char *search;
    while (*str)
    {
        start = str;
        search = substr;

        // 检查从当前位置开始的子串是否匹配
        while (*str && *search && *str == *search)
        {
            str++;
            search++;
        }

        // 如果search指向了结束符，说明找到了完整子串
        if (!*search)
            return start;

        // 否则回到start的下一个位置继续查找
        str = start + 1;
    }
    return NULL;
}

/*
编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
*/
void str_revert(char *str)
{
    int l = strlen(str);
    for (size_t i = 0; i < l / 2; i++)
    {

        // printf("str[%ld]: %c, str[l-%ld-1]: %c\n", i, str[i], i, str[l - i - 1]);
        char tmp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = tmp;
        // printf("str[%ld]: %c, str[l-%ld-1]: %c\n", i, str[i], i, str[l - i - 1]);
    }
}

/*
使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，该函数返回0。
*/
int my_atoi(char *str)
{
    if (str == NULL) // 处理空指针
        return 0;

    int sign = 1; // 符号，默认为正
    int num = 0;  // 存储转换后的数字
    int i = 0;

    // 跳过前导空白字符（可选）
    while (isspace(str[i]))
        i++;

    // 检查正负号
    if (str[i] == '+' || str[i] == '-')
    {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // 检查剩余字符是否全是数字
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;

        // 这个地方很巧妙
        num = num * 10 + (str[i] - '0');
    }

    return sign * num;
}