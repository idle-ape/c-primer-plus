#include <stdio.h>

#define MONTHS 12

int main(void)
{
    // 声明并初始化数组，显式的指定数组大小
    int months[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < MONTHS; i++)
    {
        printf("Month %2d has %2d days.\n", i + 1, months[i]);
    }

    // 声明并初始化数组，但不显式的指定数组大小，让编译器自己计算
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
    for (int i = 0; i < (sizeof(days) / sizeof(days[0])); i++)
    {
        printf("Month %2d has %d days.\n", i + 1, days[i]);
    }

    return 0;
}