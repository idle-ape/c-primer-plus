#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int times;
    /*
        atoi("42regular")将返回整数42。如果在命令行输入hello what会怎样?在我们所用的C实现中，如果命令行参数不是数字，atoi()函数 返回0。
        然而C标准规定，这种情况下的行为是未定义的。因此，使用有错误检测功能的 strtol()[https://man7.org/linux/man-pages/man3/strtol.3.html] 函数(马上介绍)会更安全。
    */
    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s <positive-number>\n", argv[0]);
    else
    {
        printf("print times: %d\n", times);
        for (int i = 0; i < times; i++)
            printf("Hello, good looking!\n");
    }

    return 0;
}