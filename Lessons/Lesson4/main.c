#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}



int main(void) {
    printf("Hello, World!\n");
    return 0;
}
