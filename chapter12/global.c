/* global.c -- 使用外部变量 */
#include <stdio.h>

int Errupt;       // 外部定义的变量
double Up[100];   // 外部定义的数组
extern char Coal; // 如果Coal被定义在另一个文件，要在这个文件内使用的话则必须这样声明
int units = 0;    // 外部变量（全局变量），units具有文件作用域、外部链接和静态存储期。

void critic(void);

int main(void)
{
    extern int units; // 可选的重复声明，不写这行，也可以直接使用 units 这个全局变量
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
    {
        critic();
    }

    puts("You must have looked it up!");
    return 0;
}

void critic(void)
{
    // 这里不使用 external 重复全局变量，直接使用 units
    puts("No luck, my friend. Try again.");
    scanf("%d", &units);
}