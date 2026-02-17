#include <stdio.h>
#define PI 3.14159
int main(void)
{
    double radius;
    int volume;

    printf("Enter radius :");

    scanf("%le", &radius);

    volume = (4 * (radius * radius * radius)) / 3.0;

    printf("volume is : %d \n\n", volume);
    return 0;
}