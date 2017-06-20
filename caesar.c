#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h> // atoi function

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Convert from string to integer
        int k = atoi(argv[1]);
        
        // Get text to be encrypted
        printf("plaintext: ");
        string p = get_string();

        // Create new string c to save encrypted text
        string c = p;
    
        if (p != NULL)
        {
            // iterate over n number of times to scan through all characters of string p
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                 // Condition for aplhabetic characters only
                 if (isalpha(p[i]))
                {
                     // Cond for upper case letters
                     if (isupper(p[i]))
                     {
                         c[i] = 65 + (p[i] - 65 + k) % 26;
                     }
                     // Cond for lower case letters
                     if (islower(p[i]))
                     {
                         c[i] = 97 + (p[i] - 97 + k) % 26;
                     }
                }
            }
            printf("ciphertext: %s\n", c);
        }
    }

    else
    {
        // ./make + key is required
        printf("Number of Inputs is Invalid\n");
        return 1;
    }
     return 0;
}