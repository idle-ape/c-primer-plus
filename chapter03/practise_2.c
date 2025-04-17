#include <stdio.h>

int main()
{
    char ascii;
    printf("Please enter a ASCCII number:\n");
    scanf("%hhd", &ascii);
    /*
    printf()函数用%c指明待打印的字符。一个字符变量实际 上被储存为1字节的整数值。
    因此，如果用%d转换说明打印 char类型变量的值，打印的是一个整数。
    而%c转换说明告诉printf()打印该整数值对应的字符。
    */
    printf("The ascii number %d is represent %c\n", ascii, ascii);
    return 0;
}