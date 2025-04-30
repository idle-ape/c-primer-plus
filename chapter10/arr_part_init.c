#include <stdio.h>

#define SIZE 4

int main(void)
{

    // 未初始化数组
    int no_data[SIZE];
    printf("%2s%14s\n", "i", "no_data[i]");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n", i, no_data[i]);
    }
    /*
    i    no_data[i]
    0             0
    1             0
    2   -1075053569
    3             0
    如果不初始化数据，数组中的元素和未初始化的普通变量一样，其中存储的都是垃圾值
    */

    // 部分初始化
    int some_data[SIZE] = {1492, 1066};
    printf("%2s%14s\n", "i", "some_data[i]");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n", i, some_data[i]);
    }

    /*
        i  some_data[i]
        0          1492
        1          1066
        2             0
        3             0
        如果部分初始化数组，剩余的元素就会被初始化为0
    */

    return 0;
}