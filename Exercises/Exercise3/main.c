#include <stdio.h>

int main(void) {
    int n, sum = 0, counter = 0;
    do {
        scanf("%d", &n);
        if (n > 0) {
            sum += n;
            counter++;
        }
    } while (n != 0);
    printf("the average is: %.2f\n", (double) sum / counter);
}