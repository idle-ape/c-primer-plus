#include <stdio.h>
#include <ctype.h>
#include <string.h>

double min(double x, double y);               // 返回两个double类型值的较小值
double max(double x, double y);               // 返回两个double类型值的较大值
void chline(char ch, int i, int j);           // 打印指定的字符j行i列
double harmonic_mean(double x, double y);     // 计算两个参数的调和平均数
void large_of(double *x, double *y);          // 把x和y中较大的值重新赋给两个变量
void resign(double *x, double *y, double *z); // 把最小值放入第1个函数，中间值放入第2个变量，最大值放入第3个变量
int letter_pos(char c);                       // 以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1
void to_base_n(int n, int m);                 // 以第2个参数中指定的进制打印第1个参数的数值
int fibonacci(int n);                         // 用循环而非递归实现斐波那契数

int main(void)
{
    printf("min(%.2f, %.2f) is %.2f\n", 3.14, 8.97, min(3.14, 8.97));

    chline('*', 7, 8);

    printf("harmonic_mean(%.2f, %.2f) is %.2f\n", 3.14, 8.97, harmonic_mean(3.14, 8.97));

    double x = 3.14, y = 8.97;
    printf("origin x is %.2f, origin y is %.2f\n", x, y);
    large_of(&x, &y);
    printf("after call large_of(&x, &y), now x is %.2f, y is %.2f\n", x, y);

    x = 3.14, y = 8.97;
    double z = 1.28;
    printf("origin x is %.2f, origin y is %.2f, origin z is %.2f\n", x, y, z);
    resign(&x, &y, &z);
    printf("after call resign(&x, &y, &z), now x is %.2f, y is %.2f, z is %.2f\n", x, y, z);

    int c;
    printf("Please enter a character: ");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            continue;
        }

        printf("The character you enter is %c, and the position is %d\n", c, letter_pos(c));
        printf("Please enter a character: ");
    }

    /*
        上面输入EOF才会退出循环，但 EOF 会使标准输入流 stdin 进入结束状态，后续的 getchar() 或 scanf 等会直接返回 EOF 而不再等待新输入。
        需要清除 EOF 标志，恢复 stdin 可读状态
    */
    if (feof(stdin))
    {
        printf("\nrestore stdin...\n");
        clearerr(stdin);
    }
    printf("Please enter a number you want to calc the fibnacci: ");
    int d, status;
    while ((status = scanf("%d", &d)) != 1)
    {
        printf("Please enter a valid integer.\n");
        // scanf未读取到对应类型有效输入时，会将输入的内容留在缓冲区，所以需要清理缓冲区
        scanf("%*s");
    }

    printf("fibnacci(%d) is %d\n", d, fibonacci(d));

    printf("Please enter a number you want to display with diffrent jinzhi: ");
    int num;
    while ((status = scanf("%d", &num)) != 1)
    {
        printf("Please enter a valid integer.\n");
        scanf("%*s");
    }
    to_base_n(num, 2);
    printf("\n");
    to_base_n(num, 8);
    printf("\n");
    to_base_n(num, 10);
    printf("\n");
    to_base_n(num, 16);
    printf("\n");

    return 0;
}

double min(double x, double y)
{
    if (x < y)
        return x;
    return y;
}

double max(double x, double y)
{
    if (x > y)
        return x;
    return y;
}

void chline(char ch, int i, int j)
{
    for (int n = 0; n < j; n++)
    {
        for (int m = 0; m < i; m++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}

double harmonic_mean(double x, double y)
{
    double d1 = 1 / x, d2 = 1 / y;
    double avg = (d1 + d2) / 2;
    return 1 / avg;
}

void large_of(double *x, double *y)
{
    if (*x > *y)
    {
        *y = *x;
    }
    else
    {
        *x = *y;
    }
}

void resign(double *x, double *y, double *z)
{
    double min_val = min(min(*x, *y), *z);
    double max_val = max(max(*x, *y), *z);
    double mid_val = (*x + *y + *z) - min_val - max_val;
    *x = min_val;
    *y = mid_val;
    *z = max_val;
    return;
}

int letter_pos(char c)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            return c - 'A' + 1;
        }
        else
        {
            return c - 'a' + 1;
        }
    }
    return -1;
}

void to_base_n(int n, int base)
{
    unsigned long int m = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    printf("%ld", m);
}

// 动态规划的思路
int fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int arr[n];
    memset(arr, 0, sizeof(arr));
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    for (int j = 0; j <= n; j++)
    {
        printf("arr[%d] => %d\n", j, arr[j]);
    }

    return arr[n];
}