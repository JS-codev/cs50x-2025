#include <stdio.h>
#include <math.h>

int main(void) {
    float dollars;
    int cents;
    do {
        printf("Change owed: ");
        if (scanf("%f", &dollars) != 1) {
            // clear invalid input
            while (getchar() != '\n');
            dollars = -1;
        }
    } while (dollars < 0);

    cents = (int)round(dollars * 100);

    int coins = 0;

    coins += cents / 25;
    cents %= 25;

    coins += cents / 10;
    cents %= 10;

    coins += cents / 5;
    cents %= 5;

    coins += cents;

    printf("%d\n", coins);
}
