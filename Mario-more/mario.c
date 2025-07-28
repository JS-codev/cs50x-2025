#include <stdio.h>
#include "cs50.h"

void print_row(int bricks);

int main(void) {
    int n; // get no. of bricks

    // input
    do {
        get_int("Int: ");
    } while (n < 0); // keep asking for a positive input always

    // Print
    for (int i = 0; i < n; i++) {
        print_row(n-1);
    }
}

void print_row(int n) {
    for (int a = 0; a < n; a++) {
        printf(" "); // print empty space
    }
    printf("#"); // after reaching end it prints #

    printf("\n"); // go to next line
}
