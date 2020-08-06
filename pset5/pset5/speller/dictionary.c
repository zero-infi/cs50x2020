// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
//#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 140;

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);
    node *f = table[key];
    while (f != NULL)
    {

        if (strcasecmp(f->word, word) == 0)
        {
            return true;
        }
        f = f->next;
    }
    return false;
}

// Hashes word to a number
// unsigned int hash(const char *word)
// {
//     int ch = tolower(word[0]) ;


//     int temp = ch%97;
//     //printf("\n  %i \n", temp %N);
//     return temp % N;

// }
unsigned int hash(const char *word)
{
    int temp = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        temp += tolower(word[i]);
    }
    //temp += tolower(word[0]);
    return temp % N;

}
int count = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE *fp = fopen(dictionary, "r");
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    if (fp != NULL)
    {
        char temp[LENGTH + 1];
        while (fscanf(fp, "%s\n", temp) != EOF)
        {
            node *n = malloc(sizeof(node));
            strcpy(n->word, temp);
            ++count;
            int key = hash(temp);
            node *tmp = NULL;
            tmp = table[key];
            if (table[key] == NULL)
            {
                table[key] = n;
                n->next = NULL;
            }
            else
            {
                // n->next = table[key];
                // table[key] = n ;
                while (tmp->next != NULL)
                {
                    tmp = tmp->next;
                }
                tmp -> next = n;

            }

        }
        fclose(fp);
        return true;

    }

    else
    {
        return false;
    }

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return count;

}

// Unloads dictionary from memory, returning true if successful else false
// bool unload(void)
// {
//     for(int i= 0 ; i < N ; i++)
//     {
//          node* temp = table[i];
//         while(table[i] != NULL)
//         {
//               node* tem = temp[i];
//             t[i] = table[i]->next;
//             free(tem);

//         }

//     }
//     return true;
// }
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);

        }
    }
    return true;
}