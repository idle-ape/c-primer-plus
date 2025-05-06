#include <stdio.h>

#define MSG "I'm special"

int main(void)
{
    char ar[] = MSG; // 使用数组方式定义字符串时，和声明数组一样，数组长度可以省略，让编译器决定数组的长度
    const char *pt = MSG;

    /*
        address of "I'm special": 0x5580f6594004
        address ar: 0x7ffd02db393c
        address pt: 0x5580f6594004
        address of MSG: 0x5580f6594004
        address of "I'm special": 0x5580f6594004

        字符串常量属于静态存储类别(static storage class)，
        这说明如果在函数中使用字符串常量，相同的字符串只会被储存一次，在整个程序的生命期内存在，即使函数被调用多次。
        虽然字符串字面量"I'm special"在程序的两个 printf() 函数中出现了两次，但是编译器只使用了一个存储位置，而且与MSG的地址相同。

        使用数组定义字符串时，字符串有两份，一个是在静态内存中的字符串字面量，一个是存储在数组中的副本；
            数组名是常量，可以进行加法操作，但是不能进行递增操作
        使用指针形式定义字符串，指针变量存储的值是一个地址，指向的是字符串的地址，字符串只有一份。
            指针名是变量，可以进行加法操作，指针表示法可以进行递增操作
    */
    printf("address of \"I'm special\": %p\n", "I'm special");
    printf("address ar: %p\n", ar);
    printf("address pt: %p\n", pt);
    printf("address of MSG: %p\n", MSG);
    printf("address of \"I'm special\": %p\n", "I'm special");

    return 0;
}