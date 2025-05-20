#include <stdio.h>

int main()
{
    /*
        自动变量不会初始化，除非显式初始化它。
        tents变量被初始化为5，但是repid变量的值是之前占用分配给repid的空间中的任意值(如果有的话)，别指望这个值是0。
    */
    int repid;
    int tents = 5;

    int n = 8;
    printf("Initially, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n++)
        printf("loop 1: n = %d at %p\n", n, &n);

    printf("After loop 1, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n++) // for循环头也属于一个块
    {
        // 循环体中属于一个块
        printf("loop 2 index n = %d at %p\n", n, &n);
        // 循环体中的n把循环头的n隐藏掉了，之后在循环体内，只能见这个n，一个循环结束，循环体内新声明的n消失，循环头里的n又可见
        int n = 6;
        printf("loop 2: n = %d at %p\n", n, &n);
        n++;
    }
    printf("After loop 2, n = %d at %p\n", n, &n);
    return 0;
}
/*
Initially, n = 8 at 0x7ffea5587e9c
loop 1: n = 1 at 0x7ffea5587ea4
loop 1: n = 2 at 0x7ffea5587ea4
After loop 1, n = 8 at 0x7ffea5587e9c
loop 2 index n = 1 at 0x7ffea5587ea0
loop 2: n = 6 at 0x7ffea5587ea4
loop 2 index n = 2 at 0x7ffea5587ea0
loop 2: n = 6 at 0x7ffea5587ea4
After loop 2, n = 8 at 0x7ffea5587e9c
*/