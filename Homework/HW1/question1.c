#include <stdio.h>

int main(void) {
    int match, gg, hh, aa;
    int man_united_goals = 0, opponent_goals = 0, matches_count = 0, points = 0;
    int last_match = 0;
    // each iteration we take a game result as an input
    while (scanf("%d", &match) == 1) {
        // extract the match no., goals scored for man_united
        // and for the opponent
        aa = match%100;
        hh = (match/100)%100;
        gg = match/10000;
        // check the sequence of match numbers and detect and print
        // any missing match numbers before this one.
        if (gg - last_match != 1) {
            for (int i = last_match + 1; i < gg; i++) {
                printf("Error Match %d is Missing\n", i);
            }
        }
        // update the last match number
        last_match = gg;
        // adding the points according to the results
        if (hh > aa) {
            points+= 3;
        } else if (hh == aa) {
            points++;
        }
        // calculating the goals for both teams according to the results
        man_united_goals+= hh;
        opponent_goals+= aa;
        // increase the match count in the end of every iteration
        matches_count++;
    }
    // print a summary
    double avg_man_united_goals = (double)man_united_goals/matches_count;
    double avg_opponent_goals = (double)opponent_goals/matches_count;
    printf("Points Gained: %d\n", points);
    printf("Average Goals Scored: %.2f\n", avg_man_united_goals);
    printf("Average Goals Conceded: %.2f\n", avg_opponent_goals);
    printf("Total Matches Calculated: %d\n", matches_count);
    return 0;
}
