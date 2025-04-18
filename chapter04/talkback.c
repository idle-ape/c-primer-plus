// talkback.c -- demenstrate how interact with user.
#include <stdio.h>
#include <string.h>

#define DENSITY 62.4

int main(void)
{
    float weight, volumn;
    int size, letters;
    char name[40]; // a array that can store 40 char

    printf("Hi! What's your first name?\n");
    scanf("%s", name); // no need to use &name, because the name of array is actually a pointer.
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);

    size = sizeof name;
    letters = strlen(name);

    volumn = weight / DENSITY;
    printf("Well, %s, your volumn is %2.2f cubic feet.\n", name, volumn);
    printf("Also, your first name has %d letters.\n", letters);
    printf("and we have %d bytes to store it.\n", size);
}