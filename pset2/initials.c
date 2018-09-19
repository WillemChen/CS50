#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    int n = 0;
    if (s[0] != ' ')
    {
        printf("%c", toupper(s[0]));
    }
   while (s[n+1] != '\0')
   {
       if (s[n] == ' ' && s[n+1] != ' ')
       {
           printf("%c", toupper(s[n + 1]));
       }
       n++;
    }
   printf("\n");
}