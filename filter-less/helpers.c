#include <math.h>
#include "helpers.h"

// GRAYSCALE
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed +
                             image[i][j].rgbtGreen +
                             image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed   = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue  = avg;
        }
    }
}

// SEPIA
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed   = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue  = image[i][j].rgbtBlue;

            int sepiaRed   = round(0.393 * originalRed +
                                   0.769 * originalGreen +
                                   0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed +
                                   0.686 * originalGreen +
                                   0.168 * originalBlue);
            int sepiaBlue  = round(0.272 * originalRed +
                                   0.534 * originalGreen +
                                   0.131 * originalBlue);

            image[i][j].rgbtRed   = sepiaRed   > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue  = sepiaBlue  > 255 ? 255 : sepiaBlue;
        }
    }
}

// REFLECT
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// BLUR
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Copy original image
    for (int i = 0; i < height; i++)
       for (int j = 0; j < width; j++)
           copy[i][j] = image[i][j];

    // Compute blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sumR = 0, sumG = 0, sumB = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumR += copy[ni][nj].rgbtRed;
                        sumG += copy[ni][nj].rgbtGreen;
                        sumB += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed   = round(sumR / count);
            image[i][j].rgbtGreen = round(sumG / count);
            image[i][j].rgbtBlue  = round(sumB / count);
        }
    }
}
