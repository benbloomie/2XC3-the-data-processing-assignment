 /*Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * Header file that contains function prototypes for cleaningOperations.c.
 * The following functions are used to clean the array data given from the user.
 */

float* read_data(float *rows, float *columns);
float* clean_delete(float* array, float rows, float columns);
void clean_impute(float* array, float rows, float columns);
void output_data(float* array, float rows, float columns);