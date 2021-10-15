from cs50 import get_int
from sys import exit

while True:
    x = get_int("Input integer: \n")

    if x < 1 or x > 8:
        print("Not correct input")
    else:
        print(f"Height: {x}")
        for i in range(x):
            print(" " * (x-i-1), end = "")
            print("#" * (i + 1) )
        exit(0)
