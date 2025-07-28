#include <stdio.h>
#include <cs50.h>

int main() {
    long card = get_long("Number: ");
    int length = 0;
    long temp = card;
    while (temp > 0) {
        temp /= 10;
        length++;
    }
    if (length != 13 && length != 15 && length != 16) { // check for card validity
        printf("INVALID\n");
        return 0;
    }

    // Apply Luhn’s Algorithm:
    int sum1 = 0, sum2 = 0;
    temp = card;
    while (temp > 0) {
        sum1 += temp % 10; // Add the last digit (not doubled) to sum1
        temp /= 10;
        int digit = temp % 10;
        digit *= 2; // multiply every other digit by 2
        sum2 += digit / 10 + digit % 10; // Add the digits of the product (e.g., 12 → 1 + 2)
        temp /= 10;
    }
    int total = sum1 + sum2;
    if (total % 10 != 0) {
        printf("INVALID\n"); // check if total's last digit is 0
        return 0;
    }

    // Extract first two digits:
    long header = card;
    while (header >= 100) {
        header /= 10;
    }

    // Determine card type:
    if ((header == 34 || header == 37) && length == 15) {
        printf("AMEX\n");
    } else if (51 <= header && header <= 55 && length == 16) {
        printf("MASTERCARD\n");
    } else if (header / 10 == 4 && (length == 13 || length == 16)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}
