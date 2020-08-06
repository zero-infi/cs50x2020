#include "helpers.h"
#include <math.h>
#include <stdlib.h>
// Convert (int)image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // taking averge of red green blue of indivdual pixel
    {
        for (int j = 0; j < width; j++)
        {
            int a = round((float)((int)image[i][j].rgbtBlue + (int)image[i][j].rgbtGreen + (int)image[i][j].rgbtRed)/3);
            BYTE avj = (BYTE) a;
            image[i][j].rgbtBlue = avj;// updating pixel 
            image[i][j].rgbtGreen = avj;// updating pixel 
            image[i][j].rgbtRed = avj;// updating pixel 
        }
    }
    
    return;
}

// Reflect (int)image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE  tem[1][1];
    for (int r = 0; r < height; r++) // exchanging pixel
    {
        
        int min = 0;
        int max = width-1;
        while (min < max)
        {
            tem[0][0] = image[r][max];
            image[r][max] = image[r][min];
            image[r][min] = tem[0][0];
            --max;
            ++min;

        }
      
    }
    return;
}

// Blur (int)image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)   //copying image
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)   // iterator row
    {
        for (int j = 0; j < width; j++)  //iterator column
        {
            if (i == 0)      // 1st row 
            {
                if (j == 0)     // topmost left corner
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j + 1].rgbtRed + (int) temp[i + 1][j].rgbtRed + 
                               (int) temp[i + 1][j + 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j + 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen + 
                               (int) temp[i + 1][j + 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j + 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + 
                               (int) temp[i + 1][j + 1].rgbtBlue;
                    avgR = round((float)avgR / 4);
                    avgG = round((float)avgG / 4);
                    avgB = round((float)avgB / 4);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else if (j == width - 1)     // topmost right corner
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i + 1][j].rgbtRed +
                               (int) temp[i + 1][j - 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen +  
                               (int) temp[i + 1][j - 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + 
                               (int) temp[i + 1][j - 1].rgbtBlue;
                    avgR = round((float)avgR / 4);
                    avgG = round((float)avgG / 4);
                    avgB = round((float)avgB / 4);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else    // top edeges cases
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i + 1][j].rgbtRed + 
                               (int) temp[i + 1][j - 1].rgbtRed + (int) temp[i][j + 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen + 
                               (int) temp[i + 1][j - 1].rgbtGreen + (int) temp[i][j + 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + 
                               (int) temp[i + 1][j - 1].rgbtBlue + (int) temp[i][j + 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                    avgR = round((float)avgR / 6);
                    avgG = round((float)avgG / 6);
                    avgB = round((float)avgB / 6);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
            }
            else if (i == height - 1)     // last row
            {
                if (j == 0)     // bottom most lesft corner
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j + 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                               (int) temp[i - 1][j + 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j + 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen + 
                               (int) temp[i - 1][j + 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j + 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue + 
                               (int) temp[i - 1][j + 1].rgbtBlue;
                    avgR = round((float)avgR / 4);
                    avgG = round((float)avgG / 4);
                    avgB = round((float)avgB / 4);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else if (j == width - 1)    // bottom most rught corner
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                               (int) temp[i - 1][j - 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen +  
                               (int) temp[i - 1][j - 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue + 
                               (int) temp[i - 1][j - 1].rgbtBlue;
                    avgR = round((float)avgR / 4);
                    avgG = round((float)avgG / 4);
                    avgB = round((float)avgB / 4);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else      // edges cases
                {
                    int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                               (int) temp[i - 1][j - 1].rgbtRed + (int) temp[i][j + 1].rgbtRed + (int) temp[i - 1][j + 1].rgbtRed;
                    int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen + 
                               (int) temp[i - 1][j - 1].rgbtGreen + (int) temp[i][j + 1].rgbtGreen + (int) temp[i - 1][j + 1].rgbtGreen;
                    int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue + 
                               (int) temp[i - 1][j - 1].rgbtBlue + (int) temp[i][j + 1].rgbtBlue + (int) temp[i - 1][j + 1].rgbtBlue;
                    avgR = round((float)avgR / 6);
                    avgG = round((float)avgG / 6);
                    avgB = round((float)avgB / 6);
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
            }
            else if (j == 0)      // first column
            {
                int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j + 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                           (int) temp[i - 1][j + 1].rgbtRed + (int) temp[i + 1][j].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j + 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen + 
                           (int) temp[i - 1][j + 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j + 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue + 
                           (int) temp[i - 1][j + 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                avgR = round((float)avgR / 6);
                avgG = round((float)avgG / 6);
                avgB = round((float)avgB / 6);
                image[i][j].rgbtRed = (BYTE) avgR;
                image[i][j].rgbtGreen = (BYTE) avgG;
                image[i][j].rgbtBlue = (BYTE) avgB;
            }
            else if (j == width - 1)    // last column
            {
                int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                           (int) temp[i - 1][j - 1].rgbtRed + (int) temp[i + 1][j].rgbtRed + (int) temp[i + 1][j - 1].rgbtRed;
                int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen + 
                           (int) temp[i - 1][j - 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen + (int) temp[i + 1][j - 1].rgbtGreen;
                int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue +
                           (int) temp[i - 1][j - 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + (int) temp[i + 1][j - 1].rgbtBlue;
                avgR = round((float)avgR / 6);
                avgG = round((float)avgG / 6);
                avgB = round((float)avgB / 6);
                image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
            }
            else       //other cases in which box of 9*9 make
            {
                int avgR = (int) temp[i][j].rgbtRed + (int) temp[i][j - 1].rgbtRed + (int) temp[i - 1][j].rgbtRed + 
                           (int) temp[i - 1][j - 1].rgbtRed + (int) temp[i + 1][j].rgbtRed + (int) temp[i + 1][j - 1].rgbtRed + 
                           (int) temp[i][j + 1].rgbtRed + (int) temp[i - 1][j + 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                int avgG = (int) temp[i][j].rgbtGreen + (int) temp[i][j - 1].rgbtGreen + (int) temp[i - 1][j].rgbtGreen + 
                           (int) temp[i - 1][j - 1].rgbtGreen + (int) temp[i + 1][j].rgbtGreen + (int) temp[i + 1][j - 1].rgbtGreen + 
                           (int) temp[i][j + 1].rgbtGreen + (int) temp[i - 1][j + 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                int avgB = (int) temp[i][j].rgbtBlue + (int) temp[i][j - 1].rgbtBlue + (int) temp[i - 1][j].rgbtBlue + 
                           (int) temp[i - 1][j - 1].rgbtBlue + (int) temp[i + 1][j].rgbtBlue + (int) temp[i + 1][j - 1].rgbtBlue + 
                           (int) temp[i][j + 1].rgbtBlue + (int) temp[i - 1][j + 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                avgR = round((float)avgR / 9);
                avgG = round((float)avgG / 9);
                avgB = round((float)avgB / 9);
                image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
            }
        }
    }
    free(temp);  // free temp
    return;
}

//edge detection
void edges(int height, int width, RGBTRIPLE image[height][width]) //uses the matrix to detect and give edges colour
{
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));  //Temp storage for orignal image
    for (int i = 0; i < height; i++)   //cpoying image in temp
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)  //iterator row
    {
        for (int j = 0; j < width; j++) //iterator column
        {
            if (i == 0)    // 1st row
            {
                if (j == 0) //for the top right corner
                {

                    int GxR = (2 * (int) temp[i][j + 1].rgbtRed) + (int) temp[i + 1][j + 1].rgbtRed;
                    int GxG = (2 * (int) temp[i][j + 1].rgbtGreen) + (int) temp[i + 1][j + 1].rgbtGreen;
                    int GxB = (2 * (int) temp[i][j + 1].rgbtBlue) + (int) temp[i + 1][j + 1].rgbtBlue;
                    int GyR = (2 * (int) temp[i + 1][j].rgbtRed) + (int) temp[i + 1][j + 1].rgbtRed;
                    int GyG = (2 * (int) temp[i + 1][j].rgbtGreen) + (int) temp[i + 1][j + 1].rgbtGreen;
                    int GyB = (2 * (int) temp[i + 1][j].rgbtBlue) + (int) temp[i + 1][j + 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else if (j == width - 1)   //for the top left corner
                {
                    int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i + 1][j - 1].rgbtRed;
                    int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i + 1][j - 1].rgbtGreen;
                    int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i + 1][j - 1].rgbtBlue;
                    int GyR = (-2 * (int) temp[i + 1][j].rgbtRed) - (int) temp[i + 1][j - 1].rgbtRed;
                    int GyG = (-2 * (int) temp[i + 1][j].rgbtGreen) - (int) temp[i + 1][j - 1].rgbtGreen;
                    int GyB = (-2 * (int) temp[i + 1][j].rgbtBlue) - (int) temp[i + 1][j - 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else     //for the top row
                {
                    int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i + 1][j - 1].rgbtRed + (2 * (int) temp[i][j + 1].rgbtRed) + 
                              (int) temp[i + 1][j + 1].rgbtRed;
                    int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i + 1][j - 1].rgbtGreen + (2 * (int) temp[i][j + 1].rgbtGreen) + 
                              (int) temp[i + 1][j + 1].rgbtGreen;
                    int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i + 1][j - 1].rgbtBlue + (2 * (int) temp[i][j + 1].rgbtBlue) + 
                              (int) temp[i + 1][j + 1].rgbtBlue;
                    int GyR = (2 * (int) temp[i + 1][j].rgbtRed) + (int) temp[i + 1][j - 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                    int GyG = (2 * (int) temp[i + 1][j].rgbtGreen) + (int) temp[i + 1][j - 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                    int GyB = (2 * (int) temp[i + 1][j].rgbtBlue) + (int) temp[i + 1][j - 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)         //for the bottom left corner
                {
                    int GxR = (2 * (int) temp[i][j + 1].rgbtRed) + (int) temp[i - 1][j + 1].rgbtRed;
                    int GxG = (2 * (int) temp[i][j + 1].rgbtGreen) + (int) temp[i - 1][j + 1].rgbtGreen;
                    int GxB = (2 * (int) temp[i][j + 1].rgbtBlue) + (int) temp[i - 1][j + 1].rgbtBlue;
                    int GyR = (-2 * (int) temp[i - 1][j].rgbtRed) - (int) temp[i - 1][j + 1].rgbtRed;
                    int GyG = (-2 * (int) temp[i - 1][j].rgbtGreen) - (int) temp[i - 1][j + 1].rgbtGreen;
                    int GyB = (-2 * (int) temp[i - 1][j].rgbtBlue) - (int) temp[i - 1][j + 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;// updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else if (j == width - 1)   //for the bottom right corner
                {   
                    int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed;
                    int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen;
                    int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue;
                    int GyR = (-2 * (int) temp[i - 1][j].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed;
                    int GyG = (-2 * (int) temp[i - 1][j].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen;
                    int GyB = (-2 * (int) temp[i - 1][j].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;  // updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;// updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;// updating pixel 
                }
                else //for the bottom most line
                {
                    int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed + (2 * (int) temp[i][j + 1].rgbtRed) + 
                              (int) temp[i - 1][j + 1].rgbtRed;
                    int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen + (2 * (int) temp[i][j + 1].rgbtGreen) + 
                              (int) temp[i - 1][j + 1].rgbtGreen;
                    int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue + (2 * (int) temp[i][j + 1].rgbtBlue) + 
                              (int) temp[i - 1][j + 1].rgbtBlue;
                    int GyR = (2 * (int) temp[i - 1][j].rgbtRed) + (int) temp[i - 1][j - 1].rgbtRed + (int) temp[i - 1][j + 1].rgbtRed;
                    int GyG = (2 * (int) temp[i - 1][j].rgbtGreen) + (int) temp[i - 1][j - 1].rgbtGreen + (int) temp[i - 1][j + 1].rgbtGreen;
                    int GyB = (2 * (int) temp[i - 1][j].rgbtBlue) + (int) temp[i - 1][j - 1].rgbtBlue + (int) temp[i - 1][j + 1].rgbtBlue;
                    int avgR = pow(GxR, 2) + pow(GyR, 2);
                    avgR = round(sqrt(avgR));
                    int avgG = pow(GxG, 2) + pow(GyG, 2);
                    avgG = round(sqrt(avgG));
                    int avgB = pow(GxB, 2) + pow(GyB, 2);
                    avgB = round(sqrt(avgB));
                    if (avgR >= 255)
                    {
                        avgR = 255;
                    }
                    if (avgG >= 255)
                    {
                        avgG = 255;
                    }
                    if (avgB >= 255)
                    {
                        avgB = 255;
                    }
                    image[i][j].rgbtRed = (BYTE) avgR;   // updating pixel 
                    image[i][j].rgbtGreen = (BYTE) avgG;  // updating pixel 
                    image[i][j].rgbtBlue = (BYTE) avgB;   // updating pixel 
                }
            }   
            else if (j == 0)  //for the left most line
            {   
                int GxR = (2 * (int) temp[i][j + 1].rgbtRed) + (int) temp[i - 1][j + 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                int GxG = (2 * (int) temp[i][j + 1].rgbtGreen) + (int) temp[i - 1][j + 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                int GxB = (2 * (int) temp[i][j + 1].rgbtBlue) + (int) temp[i - 1][j + 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                int GyR = (-2 * (int) temp[i - 1][j].rgbtRed) - (int) temp[i - 1][j + 1].rgbtRed + (2 * (int) temp[i + 1][j].rgbtRed) + 
                          (int) temp[i + 1][j + 1].rgbtRed;
                int GyG = (-2 * (int) temp[i - 1][j].rgbtGreen) - (int) temp[i - 1][j + 1].rgbtGreen + (2 * (int) temp[i + 1][j].rgbtGreen) + 
                          (int) temp[i + 1][j + 1].rgbtGreen;
                int GyB = (-2 * (int) temp[i - 1][j].rgbtBlue) - (int) temp[i - 1][j + 1].rgbtBlue + (2 * (int) temp[i + 1][j].rgbtBlue) + 
                          (int) temp[i + 1][j + 1].rgbtBlue;
                int avgR = pow(GxR, 2) + pow(GyR, 2);
                avgR = round(sqrt(avgR));
                int avgG = pow(GxG, 2) + pow(GyG, 2);
                avgG = round(sqrt(avgG));
                int avgB = pow(GxB, 2) + pow(GyB, 2);
                avgB = round(sqrt(avgB));
                if (avgR >= 255)
                {
                    avgR = 255;
                }
                if (avgG >= 255)
                {
                    avgG = 255;
                }
                if (avgB >= 255)
                {
                    avgB = 255;
                }
                image[i][j].rgbtRed = (BYTE) avgR;    // updating pixel 
                image[i][j].rgbtGreen = (BYTE) avgG;  // updating pixel 
                image[i][j].rgbtBlue = (BYTE) avgB;  // updating pixel 
            }
            else if (j == width - 1)//for the right most line
            {
                //err
                int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed - (int) temp[i + 1][j - 1].rgbtRed;
                int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen - (int) temp[i + 1][j - 1].rgbtGreen;
                int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue - (int) temp[i + 1][j - 1].rgbtBlue;
                int GyR = (-2 * (int) temp[i - 1][j].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed + (2 * (int) temp[i + 1][j].rgbtRed) + 
                          (int) temp[i + 1][j - 1].rgbtRed;
                int GyG = (-2 * (int) temp[i - 1][j].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen + (2 * (int) temp[i + 1][j].rgbtGreen) + 
                          (int) temp[i + 1][j - 1].rgbtGreen;
                int GyB = (-2 * (int) temp[i - 1][j].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue + (2 * (int) temp[i + 1][j].rgbtBlue) + 
                          (int) temp[i + 1][j - 1].rgbtBlue;
                int avgR = pow(GxR, 2) + pow(GyR, 2);
                avgR = round(sqrt(avgR));
                int avgG = pow(GxG, 2) + pow(GyG, 2);
                avgG = round(sqrt(avgG));
                int avgB = pow(GxB, 2) + pow(GyB, 2);
                avgB = round(sqrt(avgB));
                if (avgR >= 255)
                {
                    avgR = 255;
                }
                if (avgG >= 255)
                {
                    avgG = 255;
                }
                if (avgB >= 255)
                {
                    avgB = 255;
                }
                image[i][j].rgbtRed = (BYTE) avgR;     // updating pixel 
                image[i][j].rgbtGreen = (BYTE) avgG;   // updating pixel 
                image[i][j].rgbtBlue = (BYTE) avgB;    // updating pixel 
            }
            else                    //for the rest of the image
            {
                int GxR = (-2 * (int) temp[i][j - 1].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed - (int) temp[i + 1][j - 1].rgbtRed + 
                          (2 * (int) temp[i][j + 1].rgbtRed) + (int) temp[i - 1][j + 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                int GxG = (-2 * (int) temp[i][j - 1].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen - (int) temp[i + 1][j - 1].rgbtGreen + 
                          (2 * (int) temp[i][j + 1].rgbtGreen) + (int) temp[i - 1][j + 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                int GxB = (-2 * (int) temp[i][j - 1].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue - (int) temp[i + 1][j - 1].rgbtBlue + 
                          (2 * (int) temp[i][j + 1].rgbtBlue) + (int) temp[i - 1][j + 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                int GyR = (-2 * (int) temp[i - 1][j].rgbtRed) - (int) temp[i - 1][j - 1].rgbtRed + (2 * (int) temp[i + 1][j].rgbtRed) + 
                          (int) temp[i + 1][j - 1].rgbtRed - (int) temp[i - 1][j + 1].rgbtRed + (int) temp[i + 1][j + 1].rgbtRed;
                int GyG = (-2 * (int) temp[i - 1][j].rgbtGreen) - (int) temp[i - 1][j - 1].rgbtGreen + (2 * (int) temp[i + 1][j].rgbtGreen) + 
                          (int) temp[i + 1][j - 1].rgbtGreen - (int) temp[i - 1][j + 1].rgbtGreen + (int) temp[i + 1][j + 1].rgbtGreen;
                int GyB = (-2 * (int) temp[i - 1][j].rgbtBlue) - (int) temp[i - 1][j - 1].rgbtBlue + (2 * (int) temp[i + 1][j].rgbtBlue) + 
                          (int) temp[i + 1][j - 1].rgbtBlue - (int) temp[i - 1][j + 1].rgbtBlue + (int) temp[i + 1][j + 1].rgbtBlue;
                int avgR = pow(GxR, 2) + pow(GyR, 2);
                avgR = round(sqrt(avgR));
                int avgG = pow(GxG, 2) + pow(GyG, 2);
                avgG = round(sqrt(avgG));
                int avgB = pow(GxB, 2) + pow(GyB, 2);
                avgB = round(sqrt(avgB));
                if (avgR >= 255)
                {
                    avgR = 255;
                }
                if (avgG >= 255)
                {
                    avgG = 255;
                }
                if (avgB >= 255)
                {
                    avgB = 255;
                }
                image[i][j].rgbtRed = (BYTE) avgR;        // updating pixel   
                image[i][j].rgbtGreen = (BYTE) avgG;      // updating pixel 
                image[i][j].rgbtBlue = (BYTE) avgB;       // updating pixel 
            }
        }
    }
    free(temp);  //free  temp
    return;
}

