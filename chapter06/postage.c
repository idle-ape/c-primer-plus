#include <stdio.h>

int main(void)
{
    const int FIRST_OZ = 46;
    const int NEXT_OZ = 20;

    int ounces, cost;
    /*
    初始化表达 式中的逗号使ounces和cost都进行了初始化，更新表达式中的逗号使每次迭 代ounces递增1、cost递增20
    */
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
    {
        printf("%5d $%4.2f\n", ounces, cost / 100.0);
    }

    return 0;
}