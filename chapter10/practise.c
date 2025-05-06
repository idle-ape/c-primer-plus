#include <stdio.h>

void copy_arr(double target[], double source[], int n);
void copy_ptr(double *target, double *source, int n);
void copy_ptrs(double target[], double *source, double *end);
void print_arr(double arr[], int n);
void print_2d_arr(int n, int m, double arr[n][m]);
int max_arr(int ar[], int n);
int find_the_index_of_max(double ar[], int n);
void store_user_enter(int n, int m, double arr[n][m]);
double total_avg(int n, int m, double arr[n][m]);
void group_avg(int n, int m, double arr[n][m]);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    print_arr(target1, 5);

    copy_ptr(target2, source, 5);
    print_arr(target2, 5);

    copy_ptrs(target3, source, source + 5);
    print_arr(target3, 5);

    // find the max value
    printf("max of arr is %d.\n", max_arr((int[]){0, 1, 9, 3, 5, 2, 6}, 7));

    // find the index of the max value in arr
    printf("the index of max value is %d.\n", find_the_index_of_max(source, 5));

    // copy 2d arr
    double two_dimension_arr[3][3] = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9},
    };
    double target4[3][3];
    double (*t)[3] = target4;
    double (*s)[3] = two_dimension_arr;
    for (int i = 0; i < 3; i++)
    {
        copy_ptr(t[0], s[0], 3);
        t++;
        s++;
    }
    print_2d_arr(3, 3, target4);

    // copy part of source array to target array
    double src[] = {1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6};
    double target5[3];
    copy_ptr(target5, src + 2, 3);
    print_arr(target5, 3);

    // calc user input data
    double user_enter[3][5] = {};
    printf("Please enter some float number, five number per line:\n");
    store_user_enter(3, 5, user_enter);
    group_avg(3, 5, user_enter);
    printf("avg for user enter: %.2f\n", total_avg(3, 5, user_enter));
    return 0;
}

void group_avg(int n, int m, double arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        double tot = 0.0;
        for (int j = 0; j < m; j++)
        {
            tot += arr[i][j];
        }
        printf("group: %d, avg: %.2f\n", i, tot / m);
    }
    return;
}

double total_avg(int n, int m, double arr[n][m])
{
    double tot = 0.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tot += arr[i][j];
        }
    }
    return tot / (n * m);
}

void store_user_enter(int n, int m, double arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lf", &arr[i][j]);
        }
    }
    return;
}

void copy_arr(double target[], double source[], int n)
{
    for (int i = 0; i < n; i++)
    {
        target[i] = source[i];
    }
    return;
}

void copy_ptr(double *target, double *source, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(target++) = *(source++);
    }
    return;
}

void copy_ptrs(double target[], double *source, double *end)
{
    int i = 0;
    while (source < end)
    {
        target[i++] = *(source++);
    }
    return;
}

void print_arr(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("index %d = %.2f\n", i, arr[i]);
    }
    return;
}

void print_2d_arr(int n, int m, double arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%10.2f", arr[i][j]);
        }
        printf("\n");
    }
}

int max_arr(int ar[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
        {
            max = ar[i];
        }
    }
    return max;
}

int find_the_index_of_max(double ar[], int n)
{
    double max = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
        {
            max = ar[i];
            idx = i;
        }
    }
    return idx;
}