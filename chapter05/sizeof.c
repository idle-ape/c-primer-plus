#include <stdio.h>

int main(void)
{
    int n = 0;
    size_t intsize;

    /*
        运算对象可以是具体的数据对象(如，变量名)或类型。如果运算对象是类型(如，float)，则必须用圆括号将其括起来
    */
    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);

    return 0;
}