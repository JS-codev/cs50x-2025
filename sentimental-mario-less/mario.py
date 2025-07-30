#include <Python.b>
#include <cs50>

from cs50 import get_int

def main():
    while True:
        n = get_int("Height: ")
        if 1 <= n <= 8:
            break

    for i in range(1, n + 1):
        spaces = n - i
        hashes = i
        print(" " * spaces + "#" * hashes)

if __name__ == "__main__":
    main()
