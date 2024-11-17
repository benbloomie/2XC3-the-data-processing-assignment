/* Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * This program processes all the functionalities that handle the cleaning of the array read from a given text file.
 * It scans for the '-d' flag to determine which cleaning functions to use, and calls the corresponding function.
 * After processing the data, it simply prints out the cleaned array to standard output.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "checkParameters.h"
#include "cleaningOperations.h"

/* Function Name: main
 *
 * Parameters:
 *  int argc --> number of command-line argument
 *  char *argv[] --> an array that holds all the command-line arguments
 * Function Description:
 *  This function first checks if the -d flag was used, to determine which cleaning function to use on the data.
 */
int main(int argc, char *argv[]) {
    int perameterSelection = scanParameters(argc, argv);    // reads this first in case of --help usage
    float rows, columns;
    float *createdArray = read_data(&rows, &columns);   // creates array, and assigns the values of rows and columns

    // if the -d flag is recognized when calling scanParameters use the deletion function
    if (perameterSelection == 1) {
        int newRows;
        float* cleanedArray = clean_delete(createdArray, rows, columns, &newRows);  // creates cleaned array, and assigns value of newRows
        output_data(cleanedArray, newRows, columns);
        free(cleanedArray); // free allocated memory before exiting
    }
    // if the -d flag is not recognized when calling scanParameters use the imputation function
    else {
        clean_impute(createdArray, rows, columns);
        output_data(createdArray, rows, columns);
    }

    free(createdArray); // free allocated memory before exiting
    return 0;
}


