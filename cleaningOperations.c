/* Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * This code implements the functions that are used to clean the given array data.
 * OTHER STUFF
 * MORE STUFF
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Read each entry as a float
// returns an array of floats, using standard input from text file
// reads first line of text file
    // *rows = first number
    // *columns = second number 
// initializes array using malloc, with rows and columns 
// reads through rest of the file, creating a new array [TEST CASE FOR NULL]
    // iterates through each row in the text file
        // appends each element to a row in the 2D array
        // columns are each value in the array
        // special casing for NAN where scanf assigns it to special float value nan
// returns the array after iterating through rows i and columns j
float* read_data(float *rows, float *columns) {
    // reads the first two strings from standard input
    if (fscanf(stdin, "%f %f", rows, columns) != 2) {
        fprintf(stderr, "Could not read row and column values. \n");  
        exit(1);
    }

    // allocates memory for the 2D array using the specified rows and columns
    float (*p)[(int)*columns] = malloc(*rows * *columns * sizeof(float));
    if (p == NULL) {
        fprintf(stderr, "Could not Allocate Memory.\n");
        exit(1);
    }

    // intializes variables to process the loop and assign values
    float value;
    // iterates over each row
    for (int i = 0; i < (int)(*rows); i++) {
        // iterates over each column
        for (int j = 0; j < (int)(*columns); j++) {
            // reads each value, and assigns it to the corresponding entry that we are iterating at
            if (fscanf(stdin, "%f", &value) == 1) {
                p[i][j] = value;
                printf("Value: %.2f     (Row: %d, Column: %d)\n", value, i, j);
            } else {
                fprintf(stderr, "Error: Could not read data at Row %d, Column %d.\n", i, j);
                free(p); // free allocated memory on error
                exit(1);
            }
        }
    }
    return (float*)p;
}


// takes our initialized array from read_size, with rows and columns
// initializes array using malloc, with rows and columns  
// copy all the data from initialArray to this newArray
// iterates through each element in initialArray [rows & columns]
    // if it recognizes a row that has nan in it, don't append to the newArray
    // if a row does not have a nan element, add the row to the newArray
    // USE REALLOC TO DO SO
// return final array
float* clean_delete(float* array, int rows, int columns) {
    // CAST AS 2D
    // ITERATE THROUGH
    // DELETE BAD ROW
    return NULL;
}


// takes our initialized array from read_size, with rows and columns
// initializes array using malloc, with rows and columns
// iterates through each element in initialArray [rows & columns]
    // if scanf recongnizes nan, take the average of the numbers in the column, and replace it with that.
        // if the column only has nan, replace all with 0
        // use math.h, isnan to do this
    // add each new element to newArray
void clean_impute(float* array, int rows, int columns) {
    float (*p)[columns] = (float (*)[columns])array;    // cast array as a 2D array

    for (int i = 0; i < rows; i++) {
        // iterates over each column
        for (int j = 0; j < columns; j++) {
            // checks if the current element in the array reads nan
            if (isnan(p[i][j])) {   
                float columnTotal = 0;
                int numbers = 0;
                
                // loops through each element in the column where nan was located
                for (int k = 0; k < rows; k++) {
                    // checks if the current element is a valid number
                    if (!isnan(p[k][j])) {
                        columnTotal += p[k][j];
                        numbers ++; // increments counter of valid numbers in the column
                    }

                }
                // checks how many valid numbers were in the row
                if (numbers > 0) {
                    p[i][j] = (columnTotal / numbers);  // assigns the nan entry to the average of valid numbers
                }
                else {
                    p[i][j] = 0;    // assigns the nan entry to 0, if no valid numbers are in the column
                }
            }
        }
    }
}

void output_data(float* array, int rows, int columns) {
    float (*p)[columns] = (float (*)[columns])array;    // casts array to a 2D pointer
    printf("%d %d \n", rows, columns);  // prints out rows and columns

    // iterates through each row (i) and column (j) in the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j ++) {
            printf("%.3f ", p[i][j]);
        }
        puts("");   // adds a new line after each row
    }
}





