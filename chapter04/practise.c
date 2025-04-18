#include <stdio.h>
#include <string.h>

int main(void)
{
    // 1
    char first_name[30], last_name[30];
    printf("Please enter your first name and last name: \n");
    scanf("%s %s", first_name, last_name);
    printf("%s,%s\n", last_name, first_name);

    // 2
    printf("\"%20s %20s\"\n", last_name, first_name);
    printf("\"%-20s %-20s\"\n", last_name, first_name);

    int width = strlen(first_name) + strlen(last_name) + 3;
    printf("\"%*s %*s\"\n", width, last_name, width, first_name);
    return 0;
}