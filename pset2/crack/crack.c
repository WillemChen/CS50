#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>

#define SALT "50"


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string s = argv[1];
    printf("%s\n",s);
    char *test_word = "AAAAA";
    char *p;
    char *crypt_word;
    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            crypt_word = crypt(&test_word[4 - i], SALT);
            printf("%s %s ", crypt_word, &test_word[4 - i]);
            p = &test_word[4-i];
            (int)p = (int)p + 1;
            printf("%s\n", p);
        }
    }


}