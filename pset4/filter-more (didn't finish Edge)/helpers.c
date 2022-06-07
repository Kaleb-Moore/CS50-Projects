#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    //Top Left Corner case
                    temp[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);
                    temp[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                    temp[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
                }
                else if (j > 0 && j < (width - 1))
                {
                    //Top Row case
                    temp[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                    temp[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                    temp[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
                }
                else if (j == (width - 1))
                {
                    //Top Right Corner case
                    temp[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.0);
                    temp[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.0);
                    temp[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.0);
                }
            }
            else if (i > 0 && i < (height - 1))
            {
                if (j == 0)
                {
                    //Left Side case
                    temp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                    temp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                    temp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
                }
                else if (j > 0 && j <( width - 1))
                {
                    //Middle case
                    temp[i][j].rgbtRed = (round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0));
                    temp[i][j].rgbtGreen = (round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0));
                    temp[i][j].rgbtBlue = (round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0));
                }
                else if (j == (width - 1))
                {
                    //Right Side case
                    temp[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
                    temp[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
                    temp[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
                }
            }
            else if (i == (height - 1))
            {
                if (j == 0)
                {
                    //Bottom Left Corner case
                    temp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 4.0);
                    temp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.0);
                    temp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.0);
                }
                else if (j > 0 && j < (width - 1))
                {
                    //Bottom Row case
                    temp[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
                    temp[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
                    temp[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
                }
                else if (j == (width - 1))
                {
                    //Bottom Right Corner case
                    temp[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed) / 4.0);
                    temp[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen) / 4.0);
                    temp[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue) / 4.0);
                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE Gx = image[i][j];
            RGBTRIPLE Gy = image[i][j];

            if (i == 0)
            {
                if (j == 0)
                {
                    //Top Left Corner case
                    Gx.rgbtRed = ((image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                    Gx.rgbtGreen = ((image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                    Gx.rgbtBlue = ((image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));

                    Gy.rgbtRed = ((image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                    Gy.rgbtGreen = ((image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                    Gy.rgbtBlue = ((image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j > 0 && j < (width - 1))
                {
                    //Top Row case
                    Gx.rgbtRed = ((image[i][j - 1].rgbtRed * (-2)) + (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j - 1].rgbtRed * (-1)) + (image[i + 1][j + 1].rgbtRed));
                    Gx.rgbtGreen = ((image[i][j - 1].rgbtGreen * (-2)) + (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j - 1].rgbtGreen * (-1)) + (image[i + 1][j + 1].rgbtGreen));
                    Gx.rgbtBlue = ((image[i][j - 1].rgbtBlue * (-2)) + (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j - 1].rgbtBlue * (-1)) + (image[i + 1][j + 1].rgbtBlue));

                    Gy.rgbtRed = ((image[i + 1][j - 1].rgbtRed * (-2)) + (image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed * (-1)));
                    Gy.rgbtGreen = ((image[i + 1][j - 1].rgbtGreen * (-2)) + (image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen * (-1)));
                    Gy.rgbtBlue = ((image[i + 1][j - 1].rgbtBlue * (-2)) + (image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue * (-1)));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j == (width - 1))
                {
                    //Top Right Corner case
                    Gx.rgbtRed = ((image[i][j - 1].rgbtRed * (-2)) + (image[i + 1][j - 1].rgbtRed * (-1)));
                    Gx.rgbtGreen = ((image[i][j - 1].rgbtGreen * (-2)) + (image[i + 1][j - 1].rgbtGreen * (-1)));
                    Gx.rgbtBlue = ((image[i][j - 1].rgbtBlue * (-2)) + (image[i + 1][j - 1].rgbtBlue * (-1)));

                    Gy.rgbtRed = ((image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2));
                    Gy.rgbtGreen = ((image[i + 1][j - 1].rgbtGreen) + (image[i + 1][j].rgbtGreen * 2));
                    Gy.rgbtBlue = ((image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtBlue * 2));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
            }
            else if (i > 0 && i < (height - 1))
            {
                if (j == 0)
                {
                    //Left Side case
                    Gx.rgbtRed = ((image[i - 1][j + 1].rgbtRed) + (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                    Gx.rgbtGreen = ((image[i - 1][j + 1].rgbtGreen) + (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                    Gx.rgbtBlue = ((image[i - 1][j + 1].rgbtBlue) + (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));

                    Gy.rgbtRed = ((image[i - 1][j].rgbtRed * (-2)) + (image[i - 1][j + 1].rgbtRed * (-1)) + (image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                    Gy.rgbtGreen = ((image[i - 1][j].rgbtGreen * (-2)) + (image[i - 1][j + 1].rgbtGreen * (-1)) + (image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                    Gy.rgbtBlue = ((image[i - 1][j].rgbtBlue * (-2)) + (image[i - 1][j + 1].rgbtBlue * (-1)) + (image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (image[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j > 0 && j < (width - 1))
                {
                    //Middle case
                    Gx.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j + 1].rgbtRed) + (image[i][j - 1].rgbtRed * (-2)) + (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j - 1].rgbtRed * (-1)) + (image[i + 1][j + 1].rgbtRed));
                    Gx.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j + 1].rgbtGreen) + (image[i][j - 1].rgbtGreen * (-2)) + (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j - 1].rgbtGreen * (-1)) + (image[i + 1][j + 1].rgbtGreen));
                    Gx.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j + 1].rgbtBlue) + (image[i][j - 1].rgbtBlue * (-2)) + (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j - 1].rgbtBlue * (-1)) + (image[i + 1][j + 1].rgbtBlue));

                    Gy.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j].rgbtRed * (-2)) + (image[i - 1][j + 1].rgbtRed * (-1)) + (image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                    Gy.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j].rgbtGreen * (-2)) + (image[i - 1][j + 1].rgbtGreen * (-1)) + (image[i + 1][j - 1].rgbtGreen) + (image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                    Gy.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j].rgbtBlue * (-2)) + (image[i - 1][j + 1].rgbtBlue * (-1)) + (image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                    temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                    temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                    temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j == (width - 1))
                {
                    //Right Side case
                    Gx.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i][j - 1].rgbtRed * (-2)) + (image[i + 1][j - 1].rgbtRed * (-1)));
                    Gx.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i][j - 1].rgbtGreen * (-2)) + (image[i + 1][j - 1].rgbtGreen * (-1)));
                    Gx.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i][j - 1].rgbtBlue * (-2)) + (image[i + 1][j - 1].rgbtBlue * (-1)));

                    Gy.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j].rgbtRed * (-2)) + (image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2));
                    Gy.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j].rgbtGreen * (-2)) + (image[i + 1][j - 1].rgbtGreen) + (image[i + 1][j].rgbtRed * 2));
                    Gy.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j].rgbtBlue * (-2)) + (image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtRed * 2));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                    temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                    temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                    temp[i][j].rgbtBlue = 255;
                    }
                }
            }
            else if (i == (height - 1))
            {
                if (j == 0)
                {
                    //Bottom Left Corner case
                    Gx.rgbtRed = ((image[i - 1][j + 1].rgbtRed) + (image[i][j + 1].rgbtRed * 2));
                    Gx.rgbtGreen = ((image[i - 1][j + 1].rgbtGreen) + (image[i][j + 1].rgbtGreen * 2));
                    Gx.rgbtBlue = ((image[i - 1][j + 1].rgbtBlue) + (image[i][j + 1].rgbtBlue * 2));

                    Gy.rgbtRed = ((image[i - 1][j].rgbtRed * (-2)) + (image[i - 1][j + 1].rgbtRed * (-1)));
                    Gy.rgbtGreen = ((image[i - 1][j].rgbtGreen * (-2)) + (image[i - 1][j + 1].rgbtGreen * (-1)));
                    Gy.rgbtBlue = ((image[i - 1][j].rgbtBlue * (-2)) + (image[i - 1][j + 1].rgbtBlue * (-1)));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j > 0 && j < (width - 1))
                {
                    //Bottom Row case
                    Gx.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j + 1].rgbtRed) + (image[i][j - 1].rgbtRed * (-2)) + (image[i][j + 1].rgbtRed * 2));
                    Gx.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j + 1].rgbtGreen) + (image[i][j - 1].rgbtGreen * (-2)) + (image[i][j + 1].rgbtGreen * 2));
                    Gx.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j + 1].rgbtBlue) + (image[i][j - 1].rgbtBlue * (-2)) + (image[i][j + 1].rgbtBlue * 2));

                    Gy.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j].rgbtRed * (-2)) + (image[i - 1][j + 1].rgbtRed * (-1)));
                    Gy.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j].rgbtGreen * (-2)) + (image[i - 1][j + 1].rgbtGreen * (-1)));
                    Gy.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j].rgbtBlue * (-2)) + (image[i - 1][j + 1].rgbtBlue * (-1)));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
                else if (j == (width - 1))
                {
                    //Bottom Right Corner case
                    Gx.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i][j - 1].rgbtRed * (-2)));
                    Gx.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i][j - 1].rgbtGreen * (-2)));
                    Gx.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i][j - 1].rgbtBlue * (-2)));

                    Gy.rgbtRed = ((image[i - 1][j - 1].rgbtRed * (-1)) + (image[i - 1][j].rgbtRed * (-2)));
                    Gy.rgbtGreen = ((image[i - 1][j - 1].rgbtGreen * (-1)) + (image[i - 1][j].rgbtGreen * (-2)));
                    Gy.rgbtBlue = ((image[i - 1][j - 1].rgbtBlue * (-1)) + (image[i - 1][j].rgbtBlue * (-2)));

                    temp[i][j].rgbtRed = sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed * Gy.rgbtRed));
                    temp[i][j].rgbtGreen = sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen * Gy.rgbtGreen));
                    temp[i][j].rgbtBlue = sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue * Gy.rgbtBlue));

                    if (temp[i][j].rgbtRed > 255)
                    {
                        temp[i][j].rgbtRed = 255;
                    }
                    else if (temp[i][j].rgbtGreen > 255)
                    {
                        temp[i][j].rgbtGreen = 255;
                    }
                    else if (temp[i][j].rgbtBlue > 255)
                    {
                        temp[i][j].rgbtBlue = 255;
                    }
                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
