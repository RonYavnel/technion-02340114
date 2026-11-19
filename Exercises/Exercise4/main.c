#include <stdio.h>

int main(void) {
    int last_five[5];
    int counter = 0;
    int num;
    while (scanf("%d", &num) != EOF) {
        if (counter < 5) {
            last_five[counter] = num;
        } else {
            for (int i = 1; i < 5; i++) {
                last_five[i - 1] = last_five[i];
            }
        }
        counter++;
    }
    for (int i = 0; i < counter; i++) {
        printf("%d\n", last_five[i]);
    }
    return 0;
}
