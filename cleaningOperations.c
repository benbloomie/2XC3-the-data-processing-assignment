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

    float *p = malloc(*rows * *columns * sizeof(float));
    if (p == NULL) {
        fprintf(stderr, "Could not Allocate Memory.\n");
        exit(1);
    }

    float value;
    // starts reading from after the first two values
    for (int i = 0; i < *rows * *columns; i++) {
        // scans each element in the text file, and converts to a float
        if (fscanf(stdin, "%f", &value) == 1) {
            p[i] = value;   // appends each value to array 
        }
        else {
            fprintf(stderr, "Could not Read Data.");
        }
    }
    return p;
}


// takes our initialized array from read_size, with rows and columns
// initializes array using malloc, with rows and columns  
// copy all the data from initialArray to this newArray
// iterates through each element in initialArray [rows & columns]
    // if it recognizes a row that has nan in it, don't append to the newArray
    // if a row does not have a nan element, add the row to the newArray
    // USE REALLOC TO DO SO
// return final array
float* clean_delete(float* array, float rows, float columns) {
    return NULL;
}


// takes our initialized array from read_size, with rows and columns
// initializes array using malloc, with rows and columns
// iterates through each element in initialArray [rows & columns]
    // if scanf recongnizes nan, take the average of the numbers in the column, and replace it with that.
        // if the column only has nan, replace all with 0
        // use math.h, isnan to do this
    // add each new element to newArray
void clean_impute(float* array, float rows, float columns) {

}

void output_data(float* array, float rows, float columns) {
    printf("%.0f %.0f \n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int outputValue = i * (int)columns + j;
            if (isnan(array[outputValue])) {
                array[outputValue] = 0;
            }
            printf("%.3f ", array[outputValue]);
        }
        puts("");
    }
}





