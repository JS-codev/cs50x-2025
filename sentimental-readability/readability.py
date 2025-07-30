#include <cs50.h>
#include <Python.h>


from cs50 import get_string
import math

def main():
    text = get_string("Text: ")
    letters = sum(1 for c in text if c.isalpha())
    words   = sum(1 for c in text if c == ' ') + 1
    sentences = sum(1 for c in text if c in '.!?')

    L = letters * 100 / words
    S = sentences * 100 / words
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    main()
