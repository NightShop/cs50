from cs50 import get_float
from sys import exit


while True:
    change = get_float("Change owed: ")
    if change < 0:
        print("Repeat")
    else:
        i = 0
        no_coins = change // 0.25
        change = change % 0.25
        change = round(change, 2)
        no_coins += change // 0.10
        change = change % 0.10
        change = round(change, 2)
        no_coins += change // 0.05
        change = change % 0.05
        change = round(change, 2)
        no_coins += change // 0.01
        print(f"{round(no_coins)}")
        exit(0)



