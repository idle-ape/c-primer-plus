// binary.c -- 以二进制形式打印十进制整数
#include <stdio.h>

void to_binary(unsigned long int n);

int main(void)
{
    unsigned long int number;
    printf("Please enter an integer(q to quit):\n");
    scanf("%ld", &number);

    to_binary(number);
    printf("\n");
    return 0;
}

void to_binary(unsigned long int n)
{
    unsigned long int m = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    printf("%ld", m);
}
