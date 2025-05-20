/* loc_stat.c -- 使用局部静态变量 */
#include <stdio.h>

void trystat(void);

int main(void)
{

    int count;

    for (count = 1; count < 3; count++)
    {
        printf("Here comes interations %d:\n", count);
        trystat();
        /*
            Here comes interations 1:
            fade = 1 and stay = 1
            Here comes interations 2:
            fade = 1 and stay = 2
        */
    }

    return 0;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1;
    printf("fade = %d and stay = %d\n", fade++, stay++);
}