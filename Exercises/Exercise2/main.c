#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);
    if (c == 'z') {
        printf("a");
    }
    else {
        printf("%c", c + 1);
    }
}


// tests - example:
// name: student_tests.json
// new line: with /n. for example: 2/n1
/*
{
    "tests":
    [
        {
            "name": "aaaaa",
            "input": "bbbb",
            "output: "cccc"
        },
        {
            "name":
            "input":
            "output:
        }
    ]
}
*/
