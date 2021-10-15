// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1001;
node *tmp1;
int velikost;
char *geslo;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char *word1 = calloc(45, sizeof(char));
    for (int i = 0; i < strlen(word); i++)
    {
        word1[i] = tolower(word[i]);
    }
    node *tmp = NULL;
    tmp1 = table[hash(word1)];
    int n = 0;
    while (tmp1 != NULL)
    {

        if (strcasecmp(word1, tmp1->word) == 0)
        {
            free(word1);
            return true;
        }
        else
        {
            tmp1 = tmp1->next;
        }

    }
    free(word1);
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    for(int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n=27;
        }

        hash = ((hash << 3) + n) % 1000;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int *velikost1 = malloc(sizeof(int));
    *velikost1 = 0;

    FILE *slovar = fopen(dictionary, "r");
    if (slovar == NULL)
    {
        return false;
    }

    geslo = malloc(LENGTH+1);

    if(geslo == NULL)
    {
        return false;
    }

    while (fscanf(slovar, "%s", geslo) != EOF)
    {
        *velikost1 = *velikost1 + 1;

        node *tmp = malloc(sizeof(node));

        if(tmp == NULL)
        {
            return false;
        }

        strcpy(tmp->word, geslo);
        tmp->next = table[hash(geslo)];
        table[hash(geslo)] = tmp;

    }
    velikost = *velikost1;
    printf("%p\n", velikost1);
    free(velikost1);
    fclose(slovar);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return velikost;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp;
    node *cursor;
    for (int i=0; i < 1001; i++)
    {
        tmp = table[i];
        cursor = tmp;
        while (tmp != NULL)
        {
            cursor = tmp->next;
            free(tmp);
            tmp = cursor;
        }

    }
    free(cursor);
    free(tmp);
    free(geslo);
    free(tmp1);

    return true;
}
