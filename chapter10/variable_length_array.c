#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);

int main(void)
{
    /*
        变长数组的意思不是指可以修改已创建数组的大小。这里的变是指在创建数组时，可以使用变量指定数组的维度
    */
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6},
    }; // 一个变长数组（VLA）

    printf("total elements is %d\n.", sum2d(ROWS, COLS, junk));

    return 0;
}

int sum2d(int rows, int cols, int ar[rows][cols])
{
    int tot = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            tot += ar[r][c];
        }
    }
    return tot;
}