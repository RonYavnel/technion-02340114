#include <stdio.h>
#include <stdbool.h>

#define BINGO_CARD_LENGTH 10
#define MIN_BINGO_NUM 1
#define MAX_BINGO_NUM 75

bool is_num_in_card(int bingo_arr[], int bingo_arr_length, int num) {
    // this function checks if a num exists in a bingo card
    for (int i = 0; i < bingo_arr_length; i++) {
        // iterate over the bingo card and try finding the number
        if (bingo_arr[i] == num) {
            // if found - return true
            return true;
        }
    }
    // if not found - return false
    return false;
}
bool is_card_full(int bingo_arr[], int bingo_arr_length,
                  bool hist_of_lotteries[], int hist_of_lotteries_length) {

    // the function checks if there is a bingo - if all the numbers in
    // the bingo are covered by the lottery
    int counter = 0;
    // count the covered numbers
    for (int i = 0; i < hist_of_lotteries_length; i++) {
        // if the number has already been declared - check it
        if (hist_of_lotteries[i]) {
            // if the numbers is in the card - increase the counter
            if (is_num_in_card(bingo_arr, bingo_arr_length, i)) {
                counter++;
            }
        }
    }
    // return true if all the numbers in the card are covered. else - false
    return counter == bingo_arr_length;
}
int main(void) {
    int bingo_arr[BINGO_CARD_LENGTH];
    int card_num;
    // take the bingo card numbers
    for (int i = 0; i < BINGO_CARD_LENGTH; i++) {
        scanf("%d", &card_num);
        // if there is an exception (number out of limits) - stop the program
        if (card_num < MIN_BINGO_NUM || card_num > MAX_BINGO_NUM) {
            printf("Error!\n");
            return 0;
        }
        // else - put the number in the right place
        bingo_arr[i] = card_num;
    }

    // initiate a histogram of lotteries, in which all numbers' appearance
    // is false by default
    bool hist_of_lotteries[MAX_BINGO_NUM - MIN_BINGO_NUM + 2] = {false};
    int lottery_num, lotteries_count = 0;
    bool is_bingo_completed = false;
    while (true) {
        scanf("%d", &lottery_num);
        // if the lottery number is zero - stop the loop and go to the verdict
        if (lottery_num == 0) {
            break;
        }
        // if there is an exception (number out of limits) - stop the program
        if (lottery_num < MIN_BINGO_NUM || lottery_num > MAX_BINGO_NUM) {
            printf("Error!\n");
            return 0;
        }
        // else - mark the lottery number in the histogram as 'true'
        hist_of_lotteries[lottery_num] = true;
        // increase the counter of lottery numbers if the bingo is not
        // completed yet
        if (!is_bingo_completed) {
            lotteries_count++;
        }
        // then check if the bingo is completed
        // (so that the last round will count)
        is_bingo_completed = is_card_full(bingo_arr,
               BINGO_CARD_LENGTH,
                             hist_of_lotteries,
          MAX_BINGO_NUM - MIN_BINGO_NUM + 2);
    }

    // the verdict
    // if the bingo is completed - print the message and the counter
    if (is_bingo_completed) {
        printf("Bingo after %d draws!\n", lotteries_count);
    } else {
        // else - print a message, iterate over the numbers that are both in
        // the bingo card but not in the histogram in
        // ascending order and print them
        printf("No bingo. Missing:");
        for (int i = MIN_BINGO_NUM; i < MAX_BINGO_NUM - MIN_BINGO_NUM + 2; i++){
            if ((is_num_in_card(bingo_arr,
                BINGO_CARD_LENGTH, i)) &&
                (!hist_of_lotteries[i])) {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
}