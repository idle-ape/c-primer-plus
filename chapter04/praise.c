#include <stdio.h>
#include <string.h>

#define PRAISE "You are an extraordinany being."

int main(void)
{
    char name[40];
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %ld letters occupies %ld memory cells.\n", strlen(name), sizeof(name));
    printf("The phrase of praise has %ld letters ", strlen(PRAISE));
    printf("and occupies %ld memory cells.\n", sizeof(PRAISE));

    return 0;
}