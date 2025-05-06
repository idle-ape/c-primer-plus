#include <stdio.h>

int main(void)
{
    const char *mesg = "Don't be a fool!";
    const char *copy;
    copy = mesg;
    printf("%s\n", copy);
    /*
        %p 是 printf 的格式说明符，用于打印指针的值（即内存地址）。
        &mesg 打印的是指针变量 mesg 自身的地址

        +------------------+      +-------------------------------+
        | 栈（Stack）             |      | 只读数据段（.rodata）      |
        |                        |     |                           |
        | mesg 变量               | ---> | "Don't be a fool!" 字符串 |
        | (地址: 0x7ffe01e46cf8)  |      | (地址: 0x55c96b520008)    |
        +------------------+      +-------------------------------+

        Don't be a fool!
        mesg = Don't be a fool!; &mesg = 0x7ffe01e46cf8; value = 0x55c96b520008
        copy = Don't be a fool!; &copy = 0x7ffe01e46d00; value = 0x55c96b520008
    */
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);

    return 0;
}