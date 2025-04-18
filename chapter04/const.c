#include <stdio.h>

int main(void)
{
    const int months = 12; // const means that the months cannot be overwrited.
    // months = 8; // if do that, it will compile failed: const.c:6:12: error: assignment of read-only variable 'months'
    printf("months: %d\n", months);
    return 0;
}