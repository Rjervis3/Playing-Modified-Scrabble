
/*****************************************************************
 * Michael Owusu                                                 *
 * Box:  4271                                                    *
 * Supplemental Problem 4 for CSC 161                            *
 * Assignment for Friday, April 9th                              *
 *****************************************************************/

/* ***************************************************************
 * Academic honesty certification:                               *
 
 *   Written/online sources used:                                *
 * "http://stackoverflow.com/questions/7466018/scan-an-array-
   using-strcmp" referenced for help with string composition     *
   function
 
 *  Reference toward my supplemental problem 3 and how to        *
    initialize arrays recursively   
 
    "http://stackoverflow.com/questions/20817734/simple-error-c  *
    -reading-input" for help with error using scanf
 *
 
   "http://stackoverflow.com/questions/19893354/incompatible     *
 * -pointer-to-integer-although-using-char-of-arrays" referenced *
 *  for help trouble shooting pointer errors
 
 * "http://www.dreamincode.net/forums/topic/270424-how-to-make   *
 * -function-repeat/" referenced for help making procedure repeat*
 
 * "http://www.cplusplus.com/reference/cstring/strncmp/"         *
 * referenced for help using string compare function             *
 
 * "http://stackoverflow.com/questions/20157372/fill-a-matrix-2d
   -array-recursively-in-java" referenced for help creating an   *
    empty 2d array
 
 *   Help obtained                                               *

 *  Professor Walker explained words, strings, and character     *
 *  arrays and helped troubleshoot errors
 
 *   My signature below confirms that the above list of sources  *
 *   is complete AND that I have not talked to anyone else       *
 *   [e.g., CSC 161 students] about the solution to this problem *
 *                                                               *
 *   Signature:                                                  *
 *****************************************************************/

// Begin Supplemental Problem 4: Playing Modified Scrabble

// Load Libraries
#include <stdio.h>
#include <string.h>


//Check Horizontal funtion to check if the given word can be added horizontally at the given location
int check_horizontal (char * word, int row, int col, int num_rows, int num_cols, char grid
                      [num_rows][num_cols]){
    
    /*
     Pre-Conditions:
     row is a valid row location within the grid*
     col is a valid column location within the grid*
     word is a valid string
     num_rows is the total number of rows in the grid*
     num_cols is the total number of columns in the grid*
     grid is the two-dimensional array representing the grid*
     
     Post-Conditions:
     returns true (i.e., 1) if the word can be added to the grid
     horizontally with the first letter at the given row and col
     returns false (i.e., 0) otherwise
     the grid is NOT changed
     */
    
    // Declarations
    int j,k = 0;
    
    // Check if row and column are valid locations within the grid
    if (row-1 < num_rows && col-1 < num_cols)
    {
        // Make sure word will fit in chart
        if (strlen(word) <= (num_cols - (col-1)))
        {

            for (j=col-1,k=0; (j < strlen(word)); j++,k++)
            {
                // Check to see if word is valid
                if ((grid[row-1][j] == word[k]) || (grid[row-1][j] == ' '))
                {
                }
                else
                {
                    printf("Horizontal Check: Invalid word!\n ");
                    return 0;
                }
            }
            printf("Valid Word!\n\n");
            return 1;
        }
        else
        {
            printf("Word is too long! ");
            return 0;
        }
    }
    else
    {
        printf("Invalid location! ");
        return 0;
    }
}




// Check Vertical function to check if the given word can be added horizontally at the given location
int check_vertical (char * word, int row, int col, int num_rows, int num_cols, char grid
                    [num_rows][num_cols]){
    /*
     Pre-Conditions:
     
     row is a valid row location within the grid
     col is a valid column location within the grid
     word is a valid string
     num_rows is the total number of rows in the grid
     num_cols is the total number of columns in the grid
     grid is the two-dimensional array representing the grid
     
     Post-Conditions:
     returns true (i.e., 1) if the word can be added to the grid
     vertically with the first letter at the given row and col
     returns false (i.e., 0) otherwise
     the grid is NOT changed
     */
    
    // Declarations
    int j,k = 0;
    
    // Check if row and column are valid locations within the grid
    if (row-1 < num_rows && col-1 < num_cols)
    {
        // Make sure word will fit in chart
        if (strlen(word) <= (num_rows - (row-1)))
        {
            
            for (j=row-1,k=0; (j < strlen(word)); j++,k++)
            {
                // Check to see if word is valid
                if ((grid[j][col-1] == word[k]) || (grid[j][col-1] == ' '))
                {
                }
                else
                {
                    printf("Vertical Check: Invalid word!\n ");
                    return 0;
                }
            }
            printf("Valid Word!\n\n");
            return 1;
        }
        else
        {
            printf("Word is too long! ");
            return 0;
        }
    }
    else
    {
        printf("Invalid location! ");
        return 0;
    }
}


//Begin Main Procedure

/*Pre-Conditions
 Word cannot be over 100 characters
 
 Post Conditions
 Creates a grid of size specified by user
 Words can be entered into grid horizontally vertically and randomly where they will fit without overwriting other words
 */
int main() {
    
    // Declarations
    int R,C,i,j,row,col,k,n,m;
    char option;
    char word[100];
    const char * quit = "QUITQUIT";
    
    // Begin Simple UI
    printf("\n\nHello!\n");
    printf("Welcome to A Modified Game of Scrabble!\n\n");
    
    // Get a row number
    printf("\nEnter a number, R, for the number of rows on your Scrabble board.\n\n");
    scanf("%d", &R);
    printf("\n");
    
    // Get a column number
    printf("Enter a number, C, for the number of columns on your Scrabble board.\n\n");
    scanf("%d", &C);
    printf("\n\n");
    
    
    // Create a blank grid of size C x R
    char grid [R][C];
    for (i=0; i<R; i++)
    {
    
        for (j=0; j<C; j++)
        {
            grid[i][j] = ' ';
        }
    }
    
    printf("Enter QUITQUIT into your grid as a word of the game to end program\n\n");
    
    while (strcmp(word, quit) != 0){
        
        // Get word
        printf("Enter your word of choice:\n\n");
        scanf("%s", word);
        printf("\n\n");
        
        // Entry Options
        printf("Type 'H' to input a word horizontally at a specified location.\n");
        printf("Type 'V' to input a word vertically at a specified location.\n");
        printf("Type 'R' to input a word at a random location on the grid.\n\n\n");
        
        printf("Select Entry Type.\n\n");
        scanf("\n%c", &option);
        printf("\n");
   
        // Entry Options implemented
        if (option == 'H' || option == 'V' || option == 'R')
        {
            if (option == 'H')
            {
                printf("Choose word location. Please enter a row number followed by a column number:\n\n");
                scanf("%d %d", &row, &col);
                printf("\n\n");
                
                if (check_horizontal(word, row, col, R, C, grid) == 1)
                {
                    k = 0;
                    // Add Word to grid Horizonally
        
                    for (j=col-1; j<((strlen(word) + col -1)); j++,k++) // minus 1 from col to account for 0 place
                    {
                        grid[row-1][j] = word[k];
                        // minus 1 from row to account for zero place in array
                    }
                    
                    for (i=0; i<R; i++)
                    {
                        for (j=0; j<C; j++)
                        {
                            printf("%3c", grid[i][j]);
                        }
                        printf ("\n");
                    }
                }
            
            else
            {
                printf ("Sorry! Invalid input. Please try again.\n\n");
            }
            }

            if (option == 'V')
            {
                printf("Choose word location. Please enter a row number followed by a column number:\n\n");
                scanf("%d %d", &row, &col);
                printf("\n\n");
                
                if (check_vertical (word, row, col, R, C, grid) == 1){
                    k = 0;
                    // Add Word to grid Vertically
                    for (i=row-1; i<((strlen(word) + row -1)); i++,k++) // minus 1 from row to account for 0 place
                    {
                        grid[i][col-1] = word[k];
                        // minus 1 from column to account for zero place in array
                    }
                    for (i=0; i<R; i++)
                    {
                        for (j=0; j<C; j++)
                        {
                            printf("%3c", grid[i][j]);
                        }
                        printf ("\n");
                    }
                }
            
                else
                {
                    printf ("Sorry! Invalid input. Please try again.\n\n");
                }
            }
        
      
            if (option == 'R')
            {
                for (i=0; i<R; i++)
                {
                    for (j=0; j<C; j++)
                    {
                        if (check_vertical (word, i+1, j+1, R, C, grid) == 1)
                        {
                            k = 0;
                            // Add Word to grid Vertically
                            for (n=i; n<((strlen(word) + i)); n++,k++) // minus 1 from row to account for 0 place
                            {
                                grid[n][j] = word[k];
                                    // minus 1 from row to account for zero place in array
                            }
                            i=R;
                            j=C;
                        }
                        else if (check_horizontal(word, i+1, j+1, R, C-1, grid) == 1)
                        {
                            k = 0;
                            // Add Word to grid Horizonally
                            for (n=j+1; n<((strlen(word) + j+1)); n++,k++) // minus 1 from col to account for 0 place
                            {
                                printf("Horizontal %c = %c\n", grid[i][n], word[k]);
                                grid[i][n] = word[k];
                                // minus 1 from row to account for zero place in array
                            }
                            i=R;
                            j=C;
                        }
                    }
                }
                for (i=0; i<R; i++)
                {
                    for (j=0; j<C; j++)
                    {
                        printf("%3c", grid[i][j]);
                    }
                    printf ("\n");
                }
            }
        }

        
        else
        {
            printf("Invalid Entry Type!\n");
        }
    }
    
    //print done statement and return 0
    printf("End Program\n\n\n");
        return 0;
}

