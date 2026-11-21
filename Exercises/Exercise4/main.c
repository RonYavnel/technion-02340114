#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// question 1:

int midterm_quiz_q1(char arr[], int n);

int midterm_quiz_q1(char arr[], int n) {
    int counter[26] = {0};
    for (int i = 0; i < n; i++) {
        char ch = arr[i];
        if (counter[ch - 97] == 0) {
            counter[ch - 97]++;
        }
    }
    int count_different_chars
}





// question 2:
// int is_prime(long long n);
// int midterm_quiz_q2(long long n);
//
// bool is_prime(long long n) {
//     bool prime = true;
//     if (n == 1) {
//         return false;
//     }
//     if (n == 2) {
//         return true;
//     }
//     for (int i = 2; i < n; i++) {
//         if (n%i == 0) {
//             prime = false;
//         }
//     }
//     return prime;
// }
//
// int midterm_quiz_q2(long long n) {
//     int counter = 0;
//     for (int i = 2; pow(2,i) <= n; i++) {
//         if (is_prime(pow(2,i) - 1)) {
//             counter++;
//         }
//     }
//     return counter;
// }


int main(void) {
    long long n = 100;
    printf("%d", midterm_quiz_q2(n));
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
