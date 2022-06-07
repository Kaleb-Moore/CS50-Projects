import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE SEQUENCE")

    # TODO: Read database file into a variable
    people = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        if (sys.argv[1] == "databases/large.csv"):
            for person in reader:
                person["AGATC"] = int(person["AGATC"])
                person["TTTTTTCT"] = int(person["TTTTTTCT"])
                person["AATG"] = int(person["AATG"])
                person["TCTAG"] = int(person["TCTAG"])
                person["GATA"] = int(person["GATA"])
                person["TATC"] = int(person["TATC"])
                person["GAAA"] = int(person["GAAA"])
                person["TCTG"] = int(person["TCTG"])
                people.append(person)
        elif (sys.argv[1] == "databases/small.csv"):
            for person in reader:
                person["AGATC"] = int(person["AGATC"])
                person["AATG"] = int(person["AATG"])
                person["TATC"] = int(person["TATC"])
                people.append(person)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sq:
        for line in sq:
            data = line

    # TODO: Find longest match of each STR in DNA sequence
    AGATC = longest_match(data, "AGATC")
    TTTTTTCT = longest_match(data, "TTTTTTCT")
    AATG = longest_match(data, "AATG")
    TCTAG = longest_match(data, "TCTAG")
    GATA = longest_match(data, "GATA")
    TATC = longest_match(data, "TATC")
    GAAA = longest_match(data, "GAAA")
    TCTG = longest_match(data, "TCTG")

    # TODO: Check database for matching profiles
    if (sys.argv[1] == "databases/large.csv"):
        for person in people:
            if (person["AGATC"] == AGATC):
                if (person["TTTTTTCT"] == TTTTTTCT):
                    if (person["AATG"] == AATG):
                        if (person["TCTAG"] == TCTAG):
                            if (person["GATA"] == GATA):
                                if (person["TATC"] == TATC):
                                    if (person["GAAA"] == GAAA):
                                        if (person["TCTG"] == TCTG):
                                            print(person["name"])
                                            exit()
        print("No Match")

    elif (sys.argv[1] == "databases/small.csv"):
        for person in people:
            if (person["AGATC"] == AGATC):
                if (person["AATG"] == AATG):
                    if (person["TATC"] == TATC):
                        print(person["name"])
                        exit()
        print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
