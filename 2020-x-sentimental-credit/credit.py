from cs50 import get_string

number = get_string("Insert credit card number:")

def get_digit(number, n):
    return int(number) // 10**n % 10

def get_prve_dve(number):
    return int(number) // 10 ** (len(number) -2) % 100

def get_prvo(number):
    return int(number) // 10 ** (len(number) -1) % 10

def sum_of_sodih(number):
    i = 0
    for g in range(1, len(number), 2):
        i += get_digit(get_digit(int(number), g) * 2, 0) + get_digit(get_digit(int(number), g) * 2, 1)
    #print(f"{i}")
    return i

def sum_of_lihih(number):
    i = 0
    for g in range(0, len(number), 2):
        i += get_digit(int(number), g)
    # print(f"{i}")
    return i

#print(f"{get_prve_dve(number)}")

#print(f"{sum_of_sodih(number) + sum_of_lihih(number)}")

if (sum_of_sodih(number) + sum_of_lihih(number)) % 10 == 0:
    if get_prve_dve(number) == 34 or get_prve_dve(number) == 37:
        print("AMEX")
    elif 50 < get_prve_dve(number) < 56:
        print("MASTERCARD")
    elif get_prvo(number) == 4:
        print("VISA")
else:
    print("INVALID")

