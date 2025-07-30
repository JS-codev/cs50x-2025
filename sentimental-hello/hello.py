#include <Python.h>
#include <cs50>



from cs50 import get_string

name = get_string("What is your name?\n")
print(f"hello, {name}")
