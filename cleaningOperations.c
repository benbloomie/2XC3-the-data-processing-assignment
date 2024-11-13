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

float* read_data(int *rows, int *columns) {
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
    return NULL;
}

float* clean_delete(float* initialArray, int rows, int columns) {
    // takes our initialized array from read_size, with rows and columns
    // initializes array using malloc, with rows and columns  
    // copy all the data from initialArray to this newArray
    // iterates through each element in initialArray [rows & columns]
        // if it recognizes a row that has nan in it, don't append to the newArray
        // if a row does not have a nan element, add the row to the newArray
        // USE REALLOC TO DO SO
    // return final array
    return NULL;
}

void clean_impute(float* initialArray, int rows, int columns) {
    // takes our initialized array from read_size, with rows and columns
    // initializes array using malloc, with rows and columns
    // iterates through each element in initialArray [rows & columns]
        // if scanf recongnizes nan, take the average of the numbers in the column, and replace it with that.
            // if the column only has nan, replace all with 0
            // use math.h, isnan to do this
        // add each new element to newArray
}

void output_data(float* initialArray, int rows, int columns) {
    // output each element in the same was as it looms in the text file
    // output each element to 3 decimal places
        // use print formatted to do so (printf)
}





