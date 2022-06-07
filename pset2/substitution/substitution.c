#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLetter(string s);
int doubles(string s);

int main(int argc, string argv[])
{
    //Checks if there are 2 command line arguments
    if (argc == 2)
    {
        //Checks to make sure there are 26 characters
        int length = strlen(argv[1]);

        if (length == 26)
        {

            //Checks to make sure there are 26 LETTERS and no doubles
            int count = isLetter(argv[1]);
            int doubleCount = doubles(argv[1]);

            if (count == 26 && doubleCount == 0)
            {
                //Prompts the user to give a string to encrypt
                string plainText = get_string("plaintext: ");
                string cipherText = plainText;

                //loops throught the text and replaces the letter
                for (int i = 0, n = strlen(plainText); i < n; i++)
                {
                    //Replaces letter with correct UPPERCASE in the cipher
                    if (plainText[i] >= 65 && plainText[i] <= 90)
                    {
                        int j = plainText[i] - 65;
                        cipherText[i] = toupper(argv[1][j]);
                    }
                    //Replaces the letter with correct LOWERCASE in the cipher
                    else if (plainText[i] >= 97 && plainText[i] <= 122)
                    {
                        int j = plainText[i] - 97;
                        cipherText[i] = tolower(argv[1][j]);
                    }
                }
                //Returns encrypted text with no issues and exits with no errors
                printf("ciphertext: %s\n", cipherText);
                return 0;
            }
            else
            {
                //This has a double purpose of reminding the user the KEY must be 26 DIFFERENT letters so no doubles
                printf("Key must contain 26 different characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./substitution KEY\n");
            return 1;
        }
    }
    else
    {
        //Informs user of correct user of program
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}


//Checks to see if there are double letters in the cipher provided
int doubles(string s)
{
    int alphabet[26] = { 0 };
    int doubleCount = 0;

    //Checks each letter in the string and increments the alphabet array by one if the letter is present
    for (int i = 0; i < 26; i++)
    {
        int check = toupper(s[i]);
        int j = check - 65;
        alphabet[j]++;
    }

    //Checks the alphabet array for anything that isn't 1, and updates the double count
    for (int c = 0; c < 26; c++)
    {
        if (alphabet[c] != 1)
        {
            doubleCount++;
        }
    }

    //Returns count for program comparison, if the doubleCount is not 0 it will fail.
    return doubleCount;
}


//Checks to make sure every letter in the cipher is in fact a letter and not a symbol
int isLetter(string s)
{
    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
        else
        {
            printf("Usage: ./subsitution KEY\n");
        }
    }
    return count;
}
