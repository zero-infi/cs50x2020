#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    char s[600];
    int scount = 0;
    int lcount = 0;
    int wcount = 1;
    string k = get_string("Text: ");
    for (int i = 0 ; i < strlen(k) ; i++)
    {
        if (k[i] == '.' || k[i] == '!' || k[i] == '?')
        {
            scount += 1;
        }
        else if (k[i] == ' ')
        {

            wcount += 1;
        }
        else
        {
            if (k[i] >= 'a' &&  k[i] <= 'z')      //check small letter
            {
                lcount += 1;
            }
            else if (k[i] >= 'A' && k[i] <= 'Z')   //check capital
            {

                lcount += 1;
            }
        }
    }
    printf("%i\n",lcount);
    printf("%i\n",scount);
    // printf("%i\n",wcount);
    //  float w = (float) 100 / words;
    // float L = letters * w;
    // float S = (float) sentences / words;

    int index;
    float w = (float)100 / wcount;
    float L = lcount * w;
    float S = (float) scount / wcount;
    S *= 100;
    float I = 0.0588 * L - 0.296 * S - 15.8;
    index = round(I);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
