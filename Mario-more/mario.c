
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        get_int("Height:");
    }
    while (n < 1 && n > 8); // prompts them only for 1 - 8 int inputs.

    // Print a pyramid of that height (e.g user input 5)
    for (int i = 0; i < n; i++) // i becomes 1 after 1st iteration.
    {
        // Print row of bricks
        int spaces = n - i - 1; // 1st iteration: 5 - 0 - 1 = 4
        int bricks = i + 1;    // 1st iteration: 0 + 1 = 1
        print_row(spaces, bricks);
    }
    return 0;
}


void print_row(int spaces, int bricks) { // 1st iteration: (4, 1)
    for (int i = 0; i < spaces; i++) {
        printf(" "); // 1st iterate: print 4 spaces first
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#"); // 1st iterate: print a # at 5th position.
    }

    // print 2 empty lines (in middle hill):
    printf(" ");
    printf(" ");


    for (int i = 0; i < bricks; i++) // Go to next right-side of hill
    {
        printf("#"); // 1st iterate: print a #.
    }

    printf("\n"); // go to next line
}
