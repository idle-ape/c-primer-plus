// 可变宽度 * 修饰符
#include <stdio.h>

int main(void)
{
    unsigned width, precision;
    int number = 256;

    double weight = 242.5;

    printf("Enter a field width: ");
    scanf("%d", &width);
    printf("The number is: %0*d\n", width, number); // The number is: 000256

    printf("Now enter a width and a precision: ");
    scanf("%d %d", &width, &precision);
    printf("Weight = %0*.*f\n", width, precision, weight); // 0242.500

    /*
    Please enter three integers:
    11 22  33
    The last integers was 33
    */
    int n;
    printf("Please enter three integers: \n");
    scanf("%*d %*d %d", &n); // *在scanf中使用时会跳过相应的输入项
    printf("The last integers was %d\n", n);

    int m;
    printf("Please enter a string and a integer: \n");
    scanf("%*s %d", &m); // 同上
    printf("%d", m);

    return 0;
}