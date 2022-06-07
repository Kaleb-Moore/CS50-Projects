#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long creditCard;

    //Asks user for card number and will keep asking until it is given a value greater than 0
    do
    {
        printf("Enter a card number: ");
        scanf("%ld", &creditCard);
    }
    while (creditCard <= 0);

    int sum = 0;
    int counter = 0;
    long divide = 10;

    //Used a working copy of the credit card number to make changes and run calculations
    long workingCopy = creditCard;


    //Adds the last digit to a sum and then divides the number by 100 to get the next one to add. Stops when the number is 0.
    while (workingCopy > 0)
    {
        int lastDigit = workingCopy % 10;
        sum += lastDigit;
        workingCopy /= 100;
    }


    //Takes the credit card number and removes the last digit.
    //Then doubles the digit and adds it together if it is a two digit number.
    //Then adds to the sums and divides by 100 to get the next digit.
    workingCopy = creditCard / 10;
    while (workingCopy > 0)
    {
        int lastDigit = workingCopy % 10;
        int multipleByTwo = lastDigit * 2;
        sum += ((multipleByTwo % 10) + (multipleByTwo / 10));
        workingCopy /= 100;
    }

    //Checks the credit cards length and stores it in the counter value for calculations
    workingCopy = creditCard;
    do
    {
        workingCopy /= 10;
        counter++;
    }
    while (workingCopy != 0);

    //Takes the length of the card number and returns a divisor to get the first digit
    for (int i = 0; i < counter - 2; i++)
    {
        divide *= 10;
    }

    //Uses the divisor to get the first or first two digits of the credit cards number for checks.
    int firstDigit = creditCard / divide;
    int firstTwo = creditCard / (divide / 10);

    //Checks if the credit card is valid and prints the corresponding credit card type.
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (counter == 13 || counter == 16))
        {
            printf("VISA\n");
        }
        else if ((firstTwo == 34 || firstTwo == 37) && counter == 15)
        {
            printf("AMEX\n");
        }
        else if ((firstTwo >= 51 && firstTwo <= 55) && counter == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
