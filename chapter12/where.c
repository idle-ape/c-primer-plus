/* where.c -- 数据被存储在哪里 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";

/*
    可以认为程序把它可用的内存分为3部分:
    一部分供具有外部链接、内部链接和无链接的静态变量使用（静态内存）
        静态存储类别所用的内存数量在编译时确定，只要程序还在运行，就可访问储存在该部分的数据。该类别的变量在程序开始执行时被创建，在程序结束时被销毁。
    一部分供自动变量使用（栈内存）
        自动存储类别的变量在程序进入变量定义所在块时存在，在程序离开块时消失。因此，随着程序调用函数和函数结束，自动变量所用的内存数量也相应地增加和减少。
        这部分的内存通常作为栈来处理，这意味着新创建的变量按顺序加入内存，然后以相反的顺序销毁。
    一部分供动态内存分配（堆内存）
        动态分配的内存在调用 malloc()或相关函数时存在，在调用 free()后释 放。这部分的内存由程序员管理，而不是一套规则。所以内存块可以在一个函数中创建，在另一个函数中销毁。
*/

int main(void)
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int *pi;
    char *pcl;

    pi = (int *)malloc(sizeof(int));
    *pi = 35;

    pcl = (char *)malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");

    printf("static_store: %d at %p\n", static_store, &static_store);
    printf("auto_store: %d at %p\n", auto_store, &auto_store);
    printf("*pi: %d at %p\n", *pi, pi);
    printf("%s at %p\n", pcg, pcg);
    printf("%s at %p\n", auto_string, auto_string);
    printf("%s at %p\n", pcl, pcl);
    printf("%s at %p\n", "Quoted String", "Quoted String");

    free(pi);
    free(pcl);

    return 0;
}