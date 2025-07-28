#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(i + 1);// i becomes 1, i becomes 2,
    }
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++) // bricks = 1 but i remains 0, brickes becomes 2 but i remains 0.
{
    {
        printf("#");
    }
    printf("\n");
}
