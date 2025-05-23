#include <stdio.h>
char color = 'B';
void first(void);
void second(void);

int main(void)
{
    extern char color;
    printf("color in main() is %c\n", color); // color in main() is B
    first();                                  // color in first() is R
    printf("color in main() is %c\n", color); // color in main() is B
    second();                                 // color in second() is G
    printf("color in main() is %c\n", color); // color in second() is G
    return 0;
}
void first(void)
{
    char color;
    color = 'R';
    printf("color in first() is %c\n", color);
}
void second(void)
{
    color = 'G';
    printf("color in second() is %c\n", color);
}