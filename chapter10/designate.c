#include <stdio.h>

#define MONTHS 12

int main(void)
{
    // 使用初始化器初始化指定的数组元素（C99增加的新特性）
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%2d  %d\n", i + 1, days[i]);
    }
    /*
    1   31
    2   29 // 下表为1的元素的值本来是28，有面又被初始化器初始化为29
    3   0
    4   0
    5   31
    6   30
    7   31
    8   0
    9   0
    10   0
    11   0
    12   0
    */

    int stuff[] = {1, [6] = 23};       // 数组长度为7
    int staff[] = {1, [6] = 4, 9, 10}; // 数组长度为9
    return 0;
}