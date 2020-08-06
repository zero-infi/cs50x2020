#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)                                  //check for correct number of arguments
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(key[i] >= '0' && key[i] <= '9'))      //check for invalid characters in the key
        {
            printf("Invalid characters in key");
            return 1;
        }
        
    }
    
    string j = get_string("plaintext:  ");              //taking user input
    int k = 0;
    
    for (int i = 0; i < strlen(key); i++)   //
    {
        k += key[i];
        k -= 48;
        k *= 10;
    }
    k /= 10;
    //printf("%i \n",z);
    if (k > 26)  // if no. greater than z or Z then take remainder 
    {
        k = k % 26;
    }
    char x = (char) k;
    for (int i = 0; i < strlen(j); i++)
    {
        if (j[i] >= 'a' && j[i] <= 'z')      //check small letter
        {
            char temp = j[i];
            int t2 = (int) temp;
            t2 += x;
            if (t2 > 122)
            {
                t2 -= 26;
            }
            temp = (char) t2;
            j[i] = temp;
            //printf("%c", j[i]);
        }
        if (j[i] >= 'A' && j[i] <= 'Z')   //check capital
        {
            int temp = j[i];
            temp += x;
            if (temp > 90)
            {
                temp -= 26;
            }
            j[i] = (char) temp;
        }

    }
    printf("ciphertext: %s\n", j);                      //printing the outpur of the program
}
