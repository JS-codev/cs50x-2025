#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        printf("Change owed (in cents): ");
        scanf("%d", &cents);
    }
    while (cents < 0);

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
