// 转换说明修饰符
#include <stdio.h>

#define PAGES 959
#define BLURB "Authentic imitation!"

int main(void)
{
    const double RENT = 3852.99;
    char name[40] = "Bourne";
    float cash = 123.456;
    printf("*%f*\n", RENT);     // *3852.990000*
    printf("*%e*\n", RENT);     // *3.852990e+03* 科学记数法
    printf("*%4.2f*\n", RENT);  // *3852.99*
    printf("*%3.1f*\n", RENT);  // *3853.0*
    printf("*%10.3f*\n", RENT); // *  3852.990*
    printf("*%10.3E*\n", RENT); // * 3.853E+03*
    printf("*%+4.2E*\n", RENT); // *+3.85E+03*

    printf("*%d*\n", PAGES);    // *959*
    printf("*%2d*\n", PAGES);   // *959*，对应的输出结果应该是 2 字段宽度。因为待打印的整数有 3 位数字，所以字段宽度自动扩大以符 合整数的长度。
    printf("*%10d*\n", PAGES);  // *       959*
    printf("*%010d*\n", PAGES); // *0000000959*，不够的以宽度值左边的字符补齐
    printf("*%-10d*\n", PAGES); // *959       *

    printf("%x %X %#x\n", 31, 31, 31);                    // 1f 1F 0x1f
    printf("**%d**% d**% d**\n", 42, 42, -42);            // **42** 42**-42**
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6); // **    6**  006**00006**  006**

    printf("[%2s]\n", BLURB);     // [Authentic imitation!]
    printf("[%24s]\n", BLURB);    // [  Authentic imitation!]，宽度为24，不足的以空格补齐
    printf("[%24.5s]\n", BLURB);  // [          Authe]，宽度为24，但只打印5个字符
    printf("[%-24.5s]\n", BLURB); // [Authe          ]，宽度为24，但只打印5个字符，-标记使得文本左对齐输出

    printf("The %s family just may be $%.2f richer!\n", name, cash); // The Bourne family just may be $123.46 richer!

    return 0;
}