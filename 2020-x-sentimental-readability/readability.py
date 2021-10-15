from cs50 import get_string

string = get_string("Text:")

def st_crk(string):
    i=0
    for char in string:
       if char.isalpha():
           i += 1
    return i

def st_besed(string):
    i=1
    for char in string:
        if char == " ":
            i += 1
    return i

def st_stavkov(string):
    i=0
    locila = [".", "!", "?"]
    for char in string:
        if char in locila:
            i += 1
    return i

#print(f"{st_crk(string)}")
#print(f"{st_besed(string)}")
#print(f"{st_stavkov(string)}")

L = st_crk(string) / st_besed(string) *100
S = st_stavkov(string) / st_besed(string) *100

index = 0.0588 * L - 0.296 * S - 15.8
grade =  round(index)



if grade >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before grade 1")
else:
    print(f"Grade {grade}")
