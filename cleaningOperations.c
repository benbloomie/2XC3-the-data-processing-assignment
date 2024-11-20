/* Benjamin Bloomfield, bloomfib, November 20, 2024 
 *
 * This code implements the functions that are used to clean the given array data, and output the cleaned results.
 * It handles the initialization of the 2D array from file redirection, and implements various functions 
 * that iterate through the data in the array, and clean it based on user specifications.
 * It then outputs the cleaned data in the same format as the file it reads.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Function Name: read_data
 * 
 * Parameters: 
 *  float *rows --> Pointer to store the number of rows based on the given set of data
 *  float *columns --> Pointer to store the number of columns
 * Function Description:
 *  Iterates through each entry in a text file, and converts it to a floating-point value.
 *  Stores each value in a allocated 2D array.
 *  Assigns the row and column value to the first and second numbers in the file correspondingly.
 * Return Value and Output:
 *  Returns a pointer to the 1D representation of the 2D array.
 *  Outputs an error message if the memory could not be allocated, and exits with error code 1.
 */
float* read_data(float *rows, float *columns) {
    // reads the first two strings from standard input
    if (fscanf(stdin, "%f %f", rows, columns) != 2) {
        fprintf(stderr, "Could not read row and column values. \n");  
        exit(1);
    }

    // allocates memory for the 2D array using the specified rows and columns
    float (*p)[(int)*columns] = malloc(*rows * *columns * sizeof(float));
    // ensures the the memory was properly allocated
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
            } else {
                fprintf(stderr, "Error: Could not read data at Row %d, Column %d.\n", i, j);
                free(p); // free allocated memory on error
                exit(1);
            }
        }
    }
    return (float*)p;   // casts back to 1D array to return
}

/* Function Name: clean_delete
 * 
 * Parameters:
 *  float* array --> Pointer to the 1D representation of the 2D array
 *  int rows --> Number of rows in the original array
 *  int columns --> Number of columns in the original array
 *  int *newRows --> Pointer to store the new number of rows from the filtered array
 * Function Description:
 *  Iterates through the generated array from read_data, indicating any rows that include NaN.
 *  Creates a new array, only featuring rows from the original array that don't contain NaN.
 *  Allocates memory for the new array, and updates the new number of rows of the array.
 * Return Value and Output
 *  Returns a pointer to the 1D representation of the filtered 2D array.
 *  Outputs an error message if the memory could not be allocated, and exits with error code 1.
 */
float* clean_delete(float* array, int rows, int columns, int *newRows) {
    float (*p)[columns] = (float (*)[columns])array;    // cast array as a 2D array
    *newRows = 0;  
    float* newArray = NULL; // allocates the memory for the newArray

    // iterates over each row
    for (int i = 0; i < rows; i++) {
        int nanIsFound = 0; // initializes a counter to 0 for each row, to track occurences of nan
        // iterates over each column
        for (int j = 0; j < columns; j++) {
            // if nan is found, increment counter to indicate the row has a nand element
            if (isnan(p[i][j])) {
                nanIsFound++;
                break;  // break, since we don't need to continue searching for nan
            }
        }
        // if the row has no nan elements, create the space in the new array
        if (nanIsFound == 0) {
            *newRows += 1;    // updates row count for new array
            newArray = realloc(newArray, *newRows * columns * sizeof(float));  // allocates memory for updated array size
            // ensures the the memory was properly allocated
            if (newArray == NULL) {
                fprintf(stderr, "Could not Allocate Memory for Re-Allocation.\n");
                exit(1);
            }

            float (*q)[columns] = (float (*)[columns])newArray; // casts newArray as a 2D array to copy over data
            // iterates through each value in the column
            for (int k = 0; k < columns; k++) {
                q[(*newRows) - 1][k] = p[i][k]; // appends each element in row i and column k to the new 2D array
            }
        }
    }
    return (float*)newArray;
}

/* Function Name: clean_impute
 * 
 * Function Description:
 *  Iterates through the original array, and replaces all NaN values with the average 
 *  of all the non NaN values in the same column of where NaN was located.
 *  If a column only contains NaN, each element is replaced by 0. 
 */
void clean_impute(float* array, int rows, int columns) {
    float (*p)[columns] = (float (*)[columns])array;    // cast array as a 2D array

    for (int i = 0; i < rows; i++) {
        // iterates over each column
        for (int j = 0; j < columns; j++) {
            // checks if the current element in the array reads nan
            if (isnan(p[i][j])) {   
                // instantiates variables to be used for further implementation while looping over the column
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

/* Function Name: clean_delete
 * 
 * Function Description:
 *  Iterates through each element in the array, and sends it to standard output.
 *  Prints the number of rows and columns, followed by the array, in the same manner of the text file.
 *  Called after applying modifications using the clean functions, to output the newly formatted array.
 */
void output_data(float* array, int rows, int columns) {
    float (*p)[columns] = (float (*)[columns])array;    // casts array to a 2D pointer
    printf("%d %d \n", rows, columns);  // prints out rows and columns before iterating through array

    // iterates through each row (i) and column (j) in the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j ++) {
            printf("%.3f ", p[i][j]);
        }
        puts("");   // adds a new line after each row
    }
}