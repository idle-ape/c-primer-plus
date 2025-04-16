#include <stdio.h>

#define UNIT 2.54

int main()
{
    int inch;
    printf("This is a tool that convert inch to centimeter.\nPlease input a number you want to convert: \n");
    scanf("%d", &inch);
    printf("%d inchs is equal to %.2f centimeters\n", inch, inch * UNIT);
    return 0;
}