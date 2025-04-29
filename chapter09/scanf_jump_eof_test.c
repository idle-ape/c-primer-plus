#include <stdio.h>

int main()
{
    /*
        1. %*s 的作用
            %*s 会尝试读取并丢弃一个非空白字符串（遇到空格、制表符、换行符或 EOF 停止）。
            * 表示赋值抑制（读取但不存储），所以不会修改任何变量。

        2. 遇到 EOF 时的行为
            如果输入流未结束（未遇到 EOF）：
                scanf("%*s"); 会跳过下一个字符串（直到空白字符或 EOF）。
                返回 0（因为 %*s 不增加成功赋值的计数）。
            如果输入流已结束（遇到 EOF）：
                scanf("%*s"); 不会跳过 EOF，而是直接返回 EOF（通常是 -1）。
    */
    int ret;
    printf("Enter input (or press Ctrl+D/Ctrl+Z to send EOF):\n");
    ret = scanf("%*s"); // 尝试跳过字符串
    printf("scanf returned: %d\n", ret);

    if (ret == EOF)
    {
        printf("EOF encountered.\n");
    }
    return 0;
}