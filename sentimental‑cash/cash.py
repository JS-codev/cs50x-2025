#include <cs50.h>
#include <Python.h>


from cs50 import get_float
import math

def main():
    # Prompt until valid non-negative float
    while True:
        try:
            dollars = get_float("Change owed: ")
        except ValueError:
            continue
        if dollars >= 0:
            break

    cents = round(dollars * 100)
    coins = 0

    for value in (25, 10, 5, 1):
        count = cents // value
        coins += count
        cents -= count * value

    print(coins)

if __name__ == "__main__":
    main()


