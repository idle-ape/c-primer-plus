/* mod_str.c -- 修改字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 81

void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT];
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    char *find = strchr(line, '\n');
    if (find)
        *find = '\0';

    ToUpper(line);

    puts("Convert line to upper:");
    puts(line);

    printf("The line has %d punct.\n", PunctCount(line));

    return 0;
}

void ToUpper(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

int PunctCount(const char *str)
{
    int cnt = 0, i = 0;
    while (str[i] != '\0')
    {
        if (ispunct(str[i]))
            cnt++;
        i++;
    }
    return cnt;
}