from cs50 import get_int
from sys import exit

while True:
    x = get_int("Height: ")

    if x < 1 or x > 8:
        print("Not correct input")
    else:
        for i in range(x):
            print(" " * (x-i-1), end = "")
            print("#" * (i + 1), end =" ")
            print("#" * (i + 1))
        exit(0)
