#include <stdio.h>

int main(void)
{
    float weight; // your body weight
    float value;  // the value equal to platinum

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    int ret = scanf("%f", &weight);
    if (ret == 0)
    {
        perror("Please enter a valid number.\n");
        return -1;
    }

    value = 17000.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum price drop, eat more to maintain your value.\n");

    return 0;
}