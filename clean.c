/* Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * CODE FUNCTIONALITY
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
 *  This function first checks if the -d flag was used, to determine which cleaning method to use on the data.
 */
int main(int argc, char *argv[]) {
    int perameterSelection = scanParameters(argc, argv);    // reads this first in case of --help usage
    float rows, columns;
    float *createdArray = read_data(&rows, &columns);

    // if the -d flag is recognized when calling scanParameters use the deletion method
    if (perameterSelection == 1) {
        puts("USING DELETION");
        int newRows;
        float* cleanedArray = clean_delete(createdArray, rows, columns, &newRows);
        output_data(cleanedArray, newRows, columns);
        free(cleanedArray);
    }
    // if the -d flag is not recognized when calling scanParameters use the imputation method
    else {
        puts("USING IMPUTATION");
        clean_impute(createdArray, rows, columns);
        output_data(createdArray, rows, columns);
    }

    free(createdArray); // Free allocated memory
    return 0;
}


