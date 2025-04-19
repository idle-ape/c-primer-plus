#include <stdio.h>
#include <string.h>

#define CHARACTER_NUM 26
#define MSG_LEN 255

int main(void)
{
    // 1
    char arr[CHARACTER_NUM];
    int index;
    for (index = 0; index < CHARACTER_NUM; index++)
    {
        arr[index] = index + 'a';
    }
    for (int i = 0; i < CHARACTER_NUM; i++)
    {
        printf("%c\n", arr[i]);
    }

    // 2
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%s", "$");
        }
        printf("\n");
    }

    // 3
    printf("\n");
    int line_num = 'F' - 'A';
    char start_char = 'F';
    for (int i = 0; i <= line_num; i++)
    {
        char stop_char = start_char - i;
        for (char j = start_char; j >= stop_char; j--)
        {
            printf("%c", j);
        }
        printf("\n");
    }

    // 4
    printf("\n");
    char s;
    int n;
    for (s = 'A', n = 1; s < 'U'; s += n, n++)
    {
        int m = n;
        for (char e = s; m > 0; m--, e++)
        {
            printf("%c", e);
        }
        printf("\n");
    }

    // 6
    int up_limit, low_limit;
    printf("Please enter two number to print the sheet:\n");
    int q = scanf("%d %d", &low_limit, &up_limit);
    if (q < 2)
    {
        perror("Please enter two valid number.\n");
        return -1;
    }
    for (int s = low_limit; s < up_limit; s++)
    {
        printf("%-10d %-10d %-10d\n", s, s * s, s * s * s);
    }

    // 15
    printf("Please enter something in one line, it will be printed ascdently.\n");
    char msg[MSG_LEN];
    memset(msg, 0, sizeof(msg));
    for (int i = 0; i < MSG_LEN; i++)
    {
        int p = scanf("%c", &msg[i]);
        if (p == 0)
        {
            printf("Please enter something valid.\n");
            return -1;
        }
        // i != 0: avoid to read the \n of last
        if (i != 0 && msg[i] == '\n')
        {
            break;
        }
    }
    printf("Here is what you entered: %s", msg);

    printf("Let's print it ascdently:\n");
    for (int j = MSG_LEN; j >= 0; j--)
    {
        printf("%c", msg[j]);
    }
    printf("\n");

    return 0;
}