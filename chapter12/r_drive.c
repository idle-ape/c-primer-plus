/* r_drive.c -- 测试rand函数，与 rand.c 一起编译 */
#include <stdio.h>

extern unsigned int rand(void);

int main(void)
{
    int count;
    for (count = 0; count < 5; count++)
        printf("%d\n", rand());

    return 0;
}