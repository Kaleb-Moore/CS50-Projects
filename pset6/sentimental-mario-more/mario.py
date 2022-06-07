# Takes an input from the user and prints out a pyramid of that height.
from cs50 import get_int

# Keeps asking for Height if it isn't between 1-8 inclusive.
while True:
    height = get_int("Height: ")
    if (height >= 1) and (height <= 8):
        break

# Loops over height and prints #'s for each line depending on what line it is.
for i in range(height):
    print(" " * (height - (i + 1)) + "#" * (i+1) + "  " + "#" * (i+1))

exit()