#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Asks user what Height they want the pyramid to be at (max 8)
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);

    for (int i = 1; i <= Height; i++)
    {
        //Determines spaces needed at the start of the row and prints them to terminal
        int spaces = Height - i;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        //Determines the amount of # need for the row after the spaces and puts two spaces after them and prints that to the termainal
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");

        //Determines how many # are needed to finish that row and prints new line and prints that to the terminal
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}