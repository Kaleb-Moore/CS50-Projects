#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int StartSize;
    do
    {
        StartSize = get_int("Start Size: ");
    }
    while (StartSize < 9);

    // TODO: Prompt for end size
    int EndSize;
    do
    {
        EndSize = get_int("End Size: ");
    }
    while (EndSize < StartSize);

    // TODO: Calculate number of years until we reach threshold
    int Years = 0;
    while (StartSize < EndSize)
    {
        StartSize = (StartSize + (StartSize / 3) - (StartSize / 4));
        Years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", Years);
}