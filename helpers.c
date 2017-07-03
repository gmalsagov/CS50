/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Recursive searching algorithm
    
    // Ensure array size is positive
    if (n < 1)
    {
        return false;
    }
    
int left, right, middle;
    left = 0;
    right = n - 1;
    
    // Repeat until smallest number is equal to largerst number in the array
    while (left <= right)
    {
        middle = (left + right)/2;
        
        // Condition for a number being searched (SN)
        if (values[middle] == value)
        {
            return true;
        }
        
        // if SN is larger than number in the middle of array, search in the right half of the array
        if (values[middle] < value)
        {
            left = middle + 1;
        }
        
        // if SN is smaller than number in the middle of array, search in the left half of the array
        if (values[middle] > value)
        {
            right = middle - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Insertion sort algorithm
    int i, j = 0, element = 0;
    
    // iterate over the whole array apart from 0'th term
    for (i = 1; i < n; i++)
    {
        // iterate from last to first number in the sorted array
        for (j = i; j > 0 && values[j - 1] > values[j]; j--)
        {
            
            element = values[j];
            values[j] = values[j - 1];
            values[j - 1] = element;
        }
    }
    return;
}
    
