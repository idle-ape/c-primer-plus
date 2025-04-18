#include <stdio.h>

int main(void)
{
    int age;
    float assets;
    char pet[30];

    printf("Please enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);

    /*
        scanf()函数使用空白(换行符、制表符和空格)把输入分成多个字段
        同一行输入可以解析到多个变量，如果是解析到字符串，则输入时不能有空格或者换行符

        如果使用带多个转换说明的scanf()，C规定 在第1个出错处停止读取输入。

        root@ubuntu1:~/c-primer-plus# ./bin/input
        Please enter your age, assets, and favorite pet.
        32 120 dog
        32 $120.00 dog
    */

    int n, m;
    /*
        scanf()函数将其解释成: 用户将输入一个数字、一个逗号，然后再输入一个数字。
        也就是说，用户必须像下面这样进行输入两个整数:
        88,121
    */
    scanf("%d,%d", &n, &m);
    return 0;
}