#include <stdio.h>

int sum(const int ar[], int n); /* 函数原型 */

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("sum of arr is %d.\n", sum(arr, sizeof(arr) / sizeof(arr[0])));
}

// 使用 const 修饰函数形参，表明该函数不能修改数组中的数据内容
int sum(const int ar[], int n) /* 函数定义 */
{
    int i;
    int total = 0;
    for (i = 0; i < n; i++)
        total += ar[i];
    return total;
}
