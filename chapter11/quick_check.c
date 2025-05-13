#include <stdio.h>
#include <string.h>
#include "s_gets.h"

#define SIZE 80
#define LIMIT 10
#define STOP "quit"

int main(void)
{
    char input[LIMIT][SIZE];
    int ct = 0;
    printf("Enter up to %d lines(type quit to quit):\n", LIMIT);
    while (ct < LIMIT && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP))
        ct++;

    printf("%d strings entered.\n", ct);

    return 0;
}