#include <stdio.h>

int main(void)
{
    long sum = 0L;
    long num;
    int status;

    printf("Please enter an integer to be summed (q to quit): ");
    status = scanf("%ld", &num); // scanf的返回值表示成功读取项的数量，%ld表示应该输入数字，如果输入非数字则读取失败

    while (status == 1)
    {
        sum += num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}