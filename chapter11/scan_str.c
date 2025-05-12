#include <stdio.h>

int main(void)
{
    char name1[11], name2[11];
    int count;
    printf("Please enter 2 names:\n");
    /*
        scanf() 从第1个非空白字符作为字符串的开始。
        如果使用%s转换说明，以下一个空白字符(空行、 空格、制表符或换行符)作为字符串的结束(字符串不包括空白字符)。
        如果指定了字段宽度，如%10s，那么scanf()将读取10个字符或读到第1个空白字符停止(先满足的条件即是结束输入的条件)
    */
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s and %s.\n", count, name1, name2);
    return 0;
}