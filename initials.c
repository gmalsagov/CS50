#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Ask user for input
    //printf("Please enter your full name\n");
    string s = get_string();
    int i = 0;
    
    if (s != NULL)
    {
        // Searching for first character
        while (s[i] == ' ')
            {
                i++;
            }
            printf("%c", toupper(s[i]));

        // Iterate over the characters in s one at a time
        for (int j = i + 1, n = strlen(s); j < n; j++)
        {
            // Searching for character after space
            while (s[j] == ' ' && s[j + 1] != '\0')
            {
                j++;
                
                if (s[j] != ' ')
                {
                // print i's character in s
                printf("%c", toupper(s[j]));
                }
            }
        
        }
        printf("\n");
    }
}