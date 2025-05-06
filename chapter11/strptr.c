#include <stdio.h>

/* strptr.c 把字符串看作指针 */
int main(void)
{
    /*
        字符串的内容被视为指向该字符串储存位置的指针，类似于把数组名作为指向该数组起始位置的指针。
    */
    printf("%s, %p, %c\n", "We", "are", *"space farers"); // We, 0x557f0fe5b004, s
    return 0;
}