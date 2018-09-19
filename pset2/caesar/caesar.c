#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string num = argv[1];
        int i = atoi(num);
        printf("plaintext: ");
        string s = get_string();
        printf("ciphertext: ");
        for (int j = 0, n = strlen(s); j < n; j++)
        {
            if (isalpha(s[j]))
            {
                if (isupper(s[j]))
                {
                    int aphi = s[j] - 65;
                    printf("%c", ((aphi + i) % 26 + 65));
                }
                if (islower(s[j]))
                {
                    int aphi = s[j] - 97;
                    printf("%c", (aphi + i) % 26 + 97);
                }
            }
            else
            {
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}