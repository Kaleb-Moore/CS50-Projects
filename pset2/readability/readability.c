#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//Prototypes for functions
int letterCounter(string word);
int wordCounter(string word);
int sentenceCounter(string word);

int main(void)
{
    //Gets all the letters, words, and sentences for the text entered.
    string text = get_string("Text: ");
    int letters = letterCounter(text);
    int words = wordCounter(text);
    int sentence = sentenceCounter(text);

    //Calculations for the average letters per 100 words and average words per 100 sentences
    float L = ((letters / (float) words) * 100);
    float S = ((sentence / (float) words) * 100);

    //Calculates Grade
    float calculation = ((0.0588 * L) - (0.296 * S) - 15.8);
    int grade = round(calculation);

    //Displays grade range
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

//Counts the amount of letters inside the text, excluding spaces and special characters.
int letterCounter(string word)
{
    int letters = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

//Counts how many words are in the text entered. Does this by counting the spaces and the special characters(!, ?, .)
int wordCounter(string word)
{
    int words = 1;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 32)
        {
            words++;
        }
    }
    return words;
}

//Counts how many sentences in the text entered
int sentenceCounter(string word)
{
    int sentence = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 33 || word[i] == 46 || word[i] == 63)
        {
            sentence++;
        }
    }
    return sentence;
}