#include <stdio.h>

#define MOUNTAINS_LENGTH 13
#define MIN_INDEX_HEIGHT 0
#define MAX_INDEX_HEIGHT 1000

int max_to_the_right(int mountains[], int mountains_length, int index) {
    // the function checks the highest point right to the current index
    int max_to_the_right = mountains[index];
    // iterate over the indexes right to the current index and find the highest
    for (int i = index; i < mountains_length; i++) {
        if (mountains[i] > max_to_the_right) {
            max_to_the_right = mountains[i];
        }
    }
    // return the highest point right to the index
    return max_to_the_right;
}

int max_to_the_left(int mountains[], int index) {
    // the function checks the highest point left to the current index
    int max_to_the_left = mountains[index];
    // iterate over the indexes left to the current index and find the highest
    for (int i = index; i >= 0; i--) {
        if (mountains[i] > max_to_the_left) {
            max_to_the_left = mountains[i];
        }
    }
    // return the highest point left to the index
    return max_to_the_left;
}

int main(void) {
    int index_height;
    int mountains[MOUNTAINS_LENGTH] = {0};
    // take the heights of each index
    for (int i = 0; i < MOUNTAINS_LENGTH; i++) {
        scanf("%d", &index_height);
        // if the height is impossible - print an error message and
        // finish the program
        if (index_height < MIN_INDEX_HEIGHT || index_height > MAX_INDEX_HEIGHT){
            printf("Error!\n");
            return 0;
        }
        mountains[i] = index_height;
    }

    int litres = 0;
    int max_right, max_left, delta;
    // find the volume for each index and add it to the litres sum
    // we find the volume by comparing the index height to the minimum of
    // the highest points right of it and left of it
    for (int i = 0; i < MOUNTAINS_LENGTH; i++) {
        max_right = max_to_the_right(mountains, MOUNTAINS_LENGTH, i);
        max_left = max_to_the_left(mountains, i);
        // if the right highest point is higher - we take the left highest point
        // and calculate the delta, which is effectively the number of litres
        if (max_right > max_left) {
            delta = max_left - mountains[i];
        } else {
            // else - we take the right highest point
            delta = max_right - mountains[i];
        }
        // adding the delta to the litres sum
        litres += delta;
    }
    // print the litres sum
    printf("Total water: %d liters\n", litres);
    return 0;
}
