#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int height, row, space, hash;

    do
    {
         printf("Height: \n");
         height = get_int();
    }
    while (height < 0 || height > 23);

    for (row = 1; row <= height; row++)
    {
         for (space = 1; space <= height - row; space++)
         {
              printf(" ");
         }
         for (hash = 1; hash <= row + 1; hash++)
         {
              printf("#");
         }
         printf("\n");
    }
    return 0;
}
