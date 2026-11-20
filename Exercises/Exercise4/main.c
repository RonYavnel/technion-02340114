#include <stdio.h>

int midterm_quiz_q1(char arr[], int n);

int midterm_quiz_q1(char arr[], int n) {
    int counter[26] = {0};
    for (int i = 0; i < n; i++) {
        char ch = arr[i];
        if (counter[ch-97] == 0) {
            counter[ch-97]++;
        }
    }
    int count_different_chars = 0;
    for (int i = 0; i < 25; i++) {
        count_different_chars += counter[i];
    }
    return count_different_chars;
}


int main(void) {
    char arr[5] = {'a', 'b', 'a', 'a', 'a'};
    int count_different_chars = midterm_quiz_q1(arr, 5);
    printf("%d", count_different_chars);
}
//     int last_five[5];
//     int counter = 0;
//     int num;
//     while (scanf("%d", &num) != EOF) {
//         if (counter < 5) {
//             last_five[counter] = num;
//         } else {
//             for (int i = 1; i < 5; i++) {
//                 last_five[i - 1] = last_five[i];
//             }
//         }
//         counter++;
//     }
//     for (int i = 0; i < counter; i++) {
//         printf("%d\n", last_five[i]);
//     }
//     return 0;
// }
