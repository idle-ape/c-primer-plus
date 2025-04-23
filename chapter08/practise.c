#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n_lower_char = 0, n_upper_char = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
        {
            n_upper_char++;
        }
        else if (islower(ch))
        {
            n_lower_char++;
        }
    }
    printf("What you enter contains %d lower characters and %d upper characters.\n", n_lower_char, n_upper_char);
    return 0;
}