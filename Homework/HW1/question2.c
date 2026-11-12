#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int count = 0;
    char ch;
    // a flag of validity
    bool is_valid = true;
    printf("Please enter transcript:\n");
    // in each iteration, we check whether the data is valid (with the help
    // of the counter),
    // and if it is not valid - raise the flag
    while (scanf("%c", &ch) == 1) {
        // even position means this character should be a digit
        if (count%2 == 0) {
            // make sure that the first number is 0
            if (count == 0 && ch != '0') {
                is_valid = false;
            }
            // make sure that the second number is 5
            if (count == 2 && ch != '5') {
                is_valid = false;
            }
            // make sure that each number is a digit between 0-9
            if (!(ch >= '0' && ch <= '9')) {
                is_valid = false;
            }
        } else {
            // if its an odd position - make sure its a comma
            if (ch != ',') {
                is_valid = false;
            }
        }
        // increment the counter each iteration
        count++;
    }
    // after the inputs - make sure the length is exactly 19
    if (count != 19) {
        is_valid = false;
    }
    // print the summary
    if (is_valid) {
        printf("The phone number supplied is a real number.\n");
    } else {
        printf("The phone number supplied is not a real number.\n");
    }
    return 0;
}
