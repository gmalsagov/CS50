/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

void search(int tile);
bool legalmove(void);
void swap(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int n = d*d - 1;
    // Iterate over rows and columns
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            // Set tile number
            board[row][col] = n;
            //printf("Tile number is %d\n", board[row][col]);
            n--;
        }
    }
    // Ensure if size of the board is even to swap 1 and 2
    if (d % 2 == 0)
    {
        int tempel = board[d-1][d - 2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tempel;
    }
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // iterate over rows and cols
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            // Print blank space (underscore) if the tile number is 0
            if (board[row][col] == 0)
            {
                printf("[ _]");
            }
            else
            {
                printf("[%2i] ", board[row][col]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Ensure proper tile number inserted
    if (tile < 1 || tile > d*d - 1)
    {
        return false;
    }
    
    int tile_row = 0;
    int tile_col = 0;
    
    // Find location of tile
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (board[row][col] == tile)
            {
                tile_row = row;
                tile_col = col;
            }
        }
    }
    
    // Conditions for neighbouring tiles
    if (tile_row - 1 >= 0 && board[tile_row - 1][tile_col] == 0)
    {
        board[tile_row - 1][tile_col] = board[tile_row][tile_col];
        board[tile_row][tile_col] = 0;
        return true;
    }
    else if (tile_row + 1 < d && board[tile_row + 1][tile_col] == 0)
    {
        board[tile_row + 1][tile_col] = board[tile_row][tile_col];
        board[tile_row][tile_col] = 0;
        return true;
    }
    else if (tile_col - 1 >= 0 && board[tile_row][tile_col - 1] == 0)
    {
        board[tile_row][tile_col - 1] = board[tile_row][tile_col];
        board[tile_row][tile_col] = 0;
        return true;
    }
    else if (tile_col + 1 < d && board[tile_row][tile_col + 1] == 0)
    {
        board[tile_row][tile_col + 1] = board[tile_row][tile_col];
        board[tile_row][tile_col] = 0;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int order = 0;
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (++order != d*d && board[row][col] != order)
            {
                return false;
            }
        }
    }
    return true;
}
