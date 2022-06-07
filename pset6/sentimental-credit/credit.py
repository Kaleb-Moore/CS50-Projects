from cs50 import get_string
import re

# Ask for a number from the user and loop until something greater than 0 is given.
while True:
    number = get_string("Number: ")
    if int(number) > 0:
        break

sum = 0

# Adds the last digit of the credit card to sum.
working = int(number)
while (working > 0):
    ld = working % 10
    sum += ld
    working //= 100


# Calculates the sum of the 2nd last digits multipled by 2 and add to sum (simplifies 2 digit results before adding).
working = int(number) // 10
while (working > 0):
    ld = working % 10
    mbt = ld * 2
    sum += (mbt % 10) + (mbt // 10)
    working //= 100


# Regex to see which card it belongs to.
if (sum % 10) == 0:
    if (re.search("^4([0-9]{15}|[0-9]{12})", number)):
        print("VISA")
    elif (re.search("(^34|^37)[0-9]{13}", number)):
        print("AMEX")
    elif (re.search("^[5][1-5][0-9]{14}", number)):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")