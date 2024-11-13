 /*Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * Header file that contains function prototypes for cleaningOperations.c.
 * The following functions are used to clean the array data given from the user.
 */

float* read_data(int *rows, int *columns);
float* clean_delete(float* initialArray, int rows, int columns);
void clean_impute(float* initialArray, int rows, int columns);
void output_data(float* initialArray, int rows, int columns);