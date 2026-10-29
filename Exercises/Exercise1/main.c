#include <stdio.h>
# define PI 3.14
int main(void) {
    int a;
    printf("enter an integer: ");
    int r = scanf("%d", &a);
    if (r == 1)
    {
        printf("%d", a);
    }
    else
    {
        printf("not an integer");
    }


}