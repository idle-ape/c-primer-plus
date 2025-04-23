#include <stdio.h>

long get_long(void);

int main(void)
{
    long input_integer;
    input_integer = get_long();
    printf("You input a valid integer is %ld\n", input_integer);

    return 0;
}

long get_long(void)
{
    long input;
    char ch;

    // 如果成功读取项的个数不是1，说明输入了无效的整数，scanf会跳过输入的内容，将其留在输入队列中，这时候需要通过讲无效的内容从队列中读取出来
    while ((scanf("%ld", &input) != 1))
    {
        while ((ch = getchar()) != '\n')
        {
            printf("%c is not an integer.\nPlease enter an integer value, such as 25, -178 or 3.\n", ch);
        }
    }

    return input;
}