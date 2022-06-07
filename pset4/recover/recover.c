#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Defines an 8 bit unsigned int
typedef uint8_t BYTE;

//Defines the block size of the Formatted FAT memory card
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    //Checks to make sure we are getting the program input as well as the file to read from
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Opening the file and making sure it is actually there
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File cannot be opened \n");
        return 1;
    }

    //Defines a buffer to store the byte of the image in FAT blocks
    BYTE buffer[BLOCK_SIZE];

    //Creates an array for the file name
    char newfile[8];
    //Creates a new pointer that we will be pushing blocks of data to after its open
    FILE *jpeg;
    //Count to see if this is the first jpeg that we found in the data
    int count = 0;

    //Reads the block of data until there isn't a full block to read
    //This should be fine as the empty space of a block should contain 0's
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        //Checks for the identifing blocks of a jpeg image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If it finds the indentifing blocks and the count isn't 0, it first closes the image that we were writing too
            if (count != 0)
            {
                fclose(jpeg);
            }

            //Prints new string for file name
            sprintf(newfile, "%03i.jpg", count++);

            //Opens the file name
            jpeg = fopen(newfile, "w");

            //Writes the buffer to the file we just opened
            fwrite(buffer, 1, BLOCK_SIZE, jpeg);
        }

        //If the starting bytes of the block don't equal a new jpeg and the count is greater than 0 then just append to the file that is open
        else if (count > 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg);
        }
    }
}