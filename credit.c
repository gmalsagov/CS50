// German Malsagov
// 07.06.2017
// gmalsagov@gmail.com
//
// Purpose: This code completes prompts the user for a credit card number and then 
//          reports (via printf) whether it is a valid American Express (start with 
//          34 or 37), MasterCard (51, 52, 53, 54, or 55), or Visa (4) card number, 
//          per the definitions of each’s format herein.
//
// Input:   * card number
//
// Output:  * AMEX
//          * MASTERCARD
//          * VISA
//          * INVALID (if wrong)
//
// Testing: code was tested using data found in 
//          https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0, sum = 0, sum1 = 0, sum2 = 0, digit1 = 0, digit2 = 0, digit22 = 0;
    printf("Please, enter your card number \n");
    long long number = get_long_long();
    
    while (number > 0)
    {
        
        // Second-to-last and every other digits and storing in string A
        if (number > 9)
        {
            digit2 = (number/10) % 10;
            
            //printf("Second-to-last digit is %i\n", digit2);
            digit22 = 2*digit2;
            
            // Condition for non-decimal numbers to get product's digits
            if (digit22 > 9)
                {
                     int prod_dig1 = digit22/10;
                     int prod_dig2 = digit22 % 10;
                     digit22 = prod_dig1 + prod_dig2;
                }
            
            sum2 += digit22;    
        }
        
        
        digit1 = number % 10;
        //printf("Next digit is %i\n", digit1);
        
        i++;
        number = number/100;
        
        sum1 += digit1;

    }
    
    //printf("Sum: %i\n", sum);
    sum = sum1 + sum2;
    
    if (sum % 10 == 0)
        {
            if (digit1 == 3 && (digit2 == 7 || digit2 == 4))
            {
                printf("AMEX\n");
            }
            else if (digit2 == 5 && (digit1 == 1 || digit1 == 2 || digit1 == 3 || digit1 == 4 || digit1 == 5))
            {
                printf("MASTERCARD\n");
            }
            else if (digit2 == 4 || digit1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
            
    else
        {
            printf("INVALID\n");
        }
    
    return 0;
}


