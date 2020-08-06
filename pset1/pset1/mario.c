#include <cs50.h>
#include <stdio.h>


void mario(int h);                  //function decleration
int main(void)
{
    int height;
    do
    {
        height = get_int("Height :");
    }
    while (height < 1 || height > 8);
    mario(height);                      //function call

}
void mario(int h)                       //function to print
{
    int i;
    int k;
    int j;
    for (i = 0; i < h; i++)
    {
        for (k = h - 1 ; k > i; k--)
        {
            printf(" ");                //print empty space

        }
        for (j = 0; j <= i; j++)
        {
            printf("#");                //print '#'

        }
        
        
        printf("\n");

    }
}
