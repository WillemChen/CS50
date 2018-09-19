// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// hash table size
#define HASHTABLESIZE 65536

#define SEED 347
#define TWO_POWER 16

// hash table strcut
typedef struct __HASH_TABLE_NODE
{
    char word[LENGTH + 1];
    struct __HASH_TABLE_NODE *pNext;
} node;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
unsigned int hashFunction(const char *word);
void initTable(void);
node* append(node* new_node, int hash_value);

#endif // DICTIONARY_H
