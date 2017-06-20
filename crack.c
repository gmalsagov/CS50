#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if input array contains 2 arguments
    if (argc != 2)
    {
        printf("Please enter hash to crack\n");
        return 1;
    }
    
     // Get Salt
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    //printf("salt is %s\n", salt);
    
    // Declare all upper&lower letters
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Step 1. One-Character Password
    char pass1[2];
    
    // Iterate over all alphabetical letters
    for (int i = 0, n = strlen(alpha); i < n; i++)
    {
        pass1[0] = alpha[i];
        pass1[1] = '\0';
        
        // Encrypt one-character pass
        string oneword = crypt(pass1, salt);
        eprintf("Pass is %s\n", pass1);
        
        // Compare encrypted pass with input hash
        int check1 = strcmp(oneword, argv[1]);
        if (check1 == 0)
        {
            printf("Password is: %s\n", pass1);
            return 0;
        }
    }
    
    // Step 2. Two-Character Password
    char pass2[3];
        
        // Iterate first character through alpha
        for (int i = 0; i < strlen(alpha); i++)
        {
            pass2[0] = alpha[i];
            
            // Iterate second character through alpha
            for (int j = 0; j < strlen(alpha); j++)
            {
                pass2[1] = alpha[j];
                pass2[2] = '\0';
                
                // Encrypt two-character pass
                string twoword = crypt(pass2, salt);
                eprintf("Pass is %s\n", pass2);
                
                // Compare encrypted pass with input hash
                int check2 = strcmp(twoword, argv[1]);
                if (check2 == 0)
                {
                    printf("Password is: %s\n", pass2);
                    return 0;
                }
            }
        }
        
        
    // Step 3. Three-Character Password
    char pass3[4];
    
    // Iterate first character through alpha
    for (int i = 0; i < strlen(alpha); i++)
    {
        pass3[0] = alpha[i];
        
        // Iterate second character through alpha
        for (int j = 0; j < strlen(alpha); j++)
        {
            pass3[1] = alpha[j];
            
            // Iterate third character through alpha
            for (int k = 0; k < strlen(alpha); k++)
            {
                pass3[2] = alpha[k];
                pass3[3] = '\0';
                
                // Encrypt three-char pass
                string threeword = crypt(pass3, salt);
                eprintf("Pass is %s\n", pass3);
                
                // Compare three-char pass with input hash
                int check3 = strcmp(threeword, argv[1]);
                if (check3 == 0)
                {
                    printf("Password is: %s\n", pass3);
                    return 0;
                }
            }
                
        }
    }
    
    // Step 4. Four-Character Password  
    char pass4[5];
    
    // Iterate first character through alpha
    for (int i = 0; i < strlen(alpha); i++)
    {
        pass4[0] = alpha[i];
        
        // Iterate second character through alpha
        for (int j = 0; j < strlen(alpha); j++)
        {
            pass4[1] = alpha[j];
            
            // Iterate third character through alpha
            for (int k = 0; k < strlen(alpha); k++)
            {
                pass4[2] = alpha[k];
                
                // Iterate fourth character through alpha
                for (int l = 0; l < strlen(alpha); l++)
                {
                    pass4[3] = alpha[l];
                    pass4[4] = '\0';
                    
                    // Encrypt four-char pass
                    string fourword = crypt(pass4, salt);
                    eprintf("Pass is %s\n", pass4);
                    
                    // Compare four-char pass with hash
                    int check4 = strcmp(fourword, argv[1]);
                    if (check4 == 0)
                    {
                        printf("Password is: %s\n", pass4);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

