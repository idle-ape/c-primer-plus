#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Minimum int value on this system = %d\n", INT_MIN);
    printf("Maximum int value on this system = %d\n", INT_MAX);

    printf("CHAR_BIT: %d\n", CHAR_BIT);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %d\n", UCHAR_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);

    printf("smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);

    return 0;
}
