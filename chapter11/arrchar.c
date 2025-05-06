// arrchar.c -- 指针数组，字符串数组
#include <stdio.h>

#define SLEN 40
#define LIM 5

int main(void)
{
    // []的优先级高于 *，mytalents是一个内含5个指针的数组，被称为指针数组
    //
    // char (*mytalents)[LIM] 这样的方式声明则mytalents指向一个内涵LIM个char类型值的数组
    // 这是一个指向数组的指针，指向一个包含LIM个const char元素的数组。这种声明方式通常用于指向二维数组的行，而不是用来存储字符串列表。
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language",
    };

    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping",
        "Watching television",
        "Mailing letters",
        "Reading email",
    };

    puts("Let's compare talents.");
    printf("%-36s   %-25s\n", "My talents", "Your talents");
    for (int i = 0; i < LIM; i++)
    {
        printf("%-36s   %-25s\n", mytalents[i], yourtalents[i]);
    }
    printf("\nsizeof mytalents: %zd, size of youtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

    return 0;
}