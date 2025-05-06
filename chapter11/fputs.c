#include <stdio.h>

int main(void)
{
    fputs("printf sth use fputs.", stdout);
    /*
        当输出包含换行符 \n 时，缓冲区的内容会立即被刷新到终端。
        在某些情况下，缓冲区也会在程序遇到特定事件时被刷新，例如：
            1、当缓冲区满时。
            2、当程序退出时。
            3、当有其他输出操作（如 getchar()）触发时。（把 while 哪一行改成 while(1)，就不会打印那一行了）
    */
    while (getchar() != EOF)
    {
        
    }
    
    return 0;
}