// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int words;
unsigned int hashv;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hashv = hash(word);
    node *cursor = table[hashv];
    while (cursor != 0)
    {
        if (strcmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *f = fopen(dictionary, "r");
    // check if dictionary is read successfully
    if (f == NULL)
    {
        printf("Cannot open dictionary file: %s\n", dictionary);
        return false;
    }
    // read the words until we reach the end of file
    char word[LENGTH + 1];
    while (fscanf(f, "%s", word) != EOF)
    {
        // alloc memory for each node
        node *n = malloc(sizeof(node));
        // quit program if malloc is null
        if (n == NULL)
        {
            return false;
        }
        // copy word prom dictionary to memory
        strcpy(n->word, word);
        hashv = hash(word);
        n->next = table[hashv];
        table[hashv] = n;
        words++;
    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (words > 0)
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // using a temp variable to store te pointer
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}