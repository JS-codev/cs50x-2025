#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1,
    8, 5, 1, 3, 1, 1, 3, 10, 1,
    1, 1, 1, 4, 4, 8, 4, 10
};

int compute_score(string word) {
    int score = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        if (isupper(word[i])) {
            score += POINTS[word[i] - 'A'];
        } else if (islower(word[i])) {
            score += POINTS[word[i] - 'a'];
        }
        // else: non-letter → +0
    }
    return score;
}

int main(void) {
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    int s1 = compute_score(w1);
    int s2 = compute_score(w2);

    if (s1 > s2) {
        printf("Player 1 wins!\n");
    } else if (s1 < s2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}
