#include <stdio.h>
#include <stdbool.h>

#define ABC 26

int main()
{
    bool letters[ABC] = {0};

    printf("Enter a sequece of english letters, that ends with zero:\n");
    while (1) {
        char c;
        if (scanf(" %c", &c) != 1)
            return 1;
        if (c == '0') {
            break;
        }
        if (c >= 'A' && c <= 'Z') {
            letters[c - 'A'] = true;
        }
    }
    bool is_true = true;
    for (int i = 0; i < ABC; i++) {
        if (!letters[i]) {
            is_true = false;
        }
    }
    if (is_true) {
        printf("all the capital letters appeared\n");
    } else {
        printf("not all capital letters appeared\n");
    }
    return 0;
}