#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        /*k is for cipher word*/
        string k = argv[1];
        printf("%s\n", k);
        /*transfer k to the base*/
        for (int i = 0; i < strlen(k); i++)
        {
            if (isupper(k[i]))
            {
                k[i] = k[i] - 64;
            }
            else if(islower(k[i]))
            {
                k[i] = k[i] - 96;
            }
            else
            {
                 printf("Usage: ./vigenere k");
                 return 1;
            }
        }

        printf("plaintext: ");
        string p_text = get_string();

        /* A:65 Z:90 a:97 z:122*/
        int counter = 0;
        for (int i = 0; i < strlen(p_text); i++)
        {
            if (isupper(p_text[i]))
            {
                p_text[i] = (p_text[i] - 65 + k[counter % strlen(k)] - 1) % 26 + 65;
            }
            else if (islower(p_text[i]))
            {
                p_text[i] = (p_text[i] - 97 + k[counter % strlen(k)] - 1) % 26 + 97;
            }
            else
            {
                counter--;
            }
            counter++;
        }
        printf("ciphertext: %s\n", p_text);
        return 0;
    }
    else
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
}
