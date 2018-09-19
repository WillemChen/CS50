// Implements a dictionary's functionality

#include "dictionary.h"

node *hashtable[HASHTABLESIZE];
unsigned int word_count;
bool loaded;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int hash_value = hashFunction(word);
    node *cur = hashtable[hash_value];
    while (cur)
    {
        if (strcasecmp(cur->word, word) == 0)
        {
            return true;
        }
        cur = cur->pNext;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fdict = fopen(dictionary, "r");
    char word[LENGTH + 1];
    if (!fdict)
    {
        return false;
    }
    //
    initTable();

    while (fscanf(fdict, "%s", word) != EOF)
    {
        // allocate memory to node and assign word to the node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        strcpy(new_node->word, word);

        // hash the word
        unsigned int hash_value = hashFunction(word);

        // according to hash value,append new node to the hash table
        append(new_node, hash_value);
        word_count++;
    }
    fclose(fdict);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        node *cur = hashtable[i];
        while (cur != NULL)
        {
            node *temp = cur;
            cur = cur->pNext;
            free(temp);
        }
    }
    loaded = false;
    return true;
}

unsigned int hashFunction(const char *word)
{
    unsigned int hash_num = 0;
    while (*word)
    {
        hash_num = hash_num * SEED + tolower((*word++));
    }
    return hash_num & ((1 << TWO_POWER) - 1);
}

node *append(node *new_node, int hash_value)
{
    new_node->pNext = hashtable[hash_value];
    hashtable[hash_value] = new_node;
    return hashtable[hash_value];
}

void initTable(void)
{
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        hashtable[i] = NULL;
    }
}