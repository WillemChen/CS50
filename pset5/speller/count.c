#include <stdio.h>
#include <string.h>
#define DICTIONARY "dictionaries/large"

int main()
{
    char *dict = DICTIONARY;
    FILE *fp = fopen(dict, "r");
    char word[46];
    int word_count[26] = { 0 };
    int len_count[45] = { 0 };
    while (fscanf(fp, "%s", word) != EOF)
    {
        word_count[word[0] - 'a']++;
        int k = strlen(word);
        len_count[k-1]++;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c:%i\n",(i+97),word_count[i]);
    }
    for (int i = 0; i < 45; i++)
    {
        printf("len%2i:%5i  ", (i+1), len_count[i]);
        if(i%3 == 2) putchar('\n');
    }
    fclose(fp);
}