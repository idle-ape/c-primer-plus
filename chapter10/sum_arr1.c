#include <stdio.h>

#define SIZE 10

int sum(int arr[], int n);
int sum_v2(int *, int *);

int main(void)
{
    int marbles[] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long anwser;
    anwser = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", anwser);
    printf("The size of marbles is %zd bytes.\n", sizeof(marbles));

    printf("The total number of marbles is %d.\n", sum_v2(marbles, marbles + SIZE)); // marbles + SIZE 实际是数组最后一个元素的后面

    return 0;
}

int sum(int ar[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += *(ar + i);
    }
    // The size of ar is 8 bytes. 因为arr并不是数组本身，它是一个指向 marbles 数组首元素的指针，等价于 int *
    printf("The size of ar is %zd bytes.\n", sizeof(ar));
    return total;
}

// 通过传递两个指针来访问数组
int sum_v2(int *start, int *end)
{
    int total = 0;
    while (start < end)
    {
        // total += *start++;
        total += *start;
        start++;
    }
    return total;
}