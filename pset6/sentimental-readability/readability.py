from cs50 import get_string
import re

# Get input from User
text = get_string("Text: ")

# Sets starting value (Note: words is 1 because you might not put a space if typing one word)
letters = 0
words = 1
sentences = 0

# Checks the letters one by one in text and increments the specific value for each character
for letter in text:
    if (re.search("[a-zA-z]", letter)):
        letters += 1
    elif (re.search("\s", letter)):
        words += 1
    elif (re.search("(\.|\!|\?)", letter)):
        sentences += 1

# Math stuff for the Coleman-Liau index
L = ((letters / words) * 100)
S = ((sentences / words) * 100)

calc = ((0.0588 * L) - (0.296 * S) - 15.8)
grade = round(calc)

# Prints out the grade level
if (grade < 1):
    print("Before Grade 1")
elif (grade > 16):
    print("Grade 16+")
else:
    print(f"Grade {grade}")