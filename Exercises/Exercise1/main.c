#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int new_num = 0;
    while (n > 0) {
        new_num *= 10;
        new_num += n % 10;
        n /= 10;
    }
    printf("The result is: %d\n", new_num);
}