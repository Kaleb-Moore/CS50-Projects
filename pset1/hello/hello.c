#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Gets the users name and prints to terminal
    string name = get_string("What is your name?: ");
    printf("hello, %s\n", name);
}