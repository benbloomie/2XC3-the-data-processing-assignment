/* Benjamin Bloomfield, bloomfib, November 20, 2024 
 *
 * This code works as a command-line utility, that checks for any additional parameters entered by the user.
 * It will scan for the -d flag, and return a value based on the arguments for additional implementation
 * The program accurately handles invalid inputs, and allows users to access a help message if they require.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function Name: printHelpMessage
 *
 * Function Description:
 *  Outputs a help message that guides the user on how to use the program properly.
 */
void printHelpMessage() {
    puts("clean - Data Cleaning Utility");
    puts("Version: v1.0.2");
    puts("");
    puts("Clean is a command-line utility that allows user to clean data in two different ways.");
    puts("The user can chose to have each row containing NaN, or impute the occurrences of NaN");
    puts("based on the average of all the NaN entries in the same column.");
    puts("");
    puts("The user will redirect text files as standard input, choose which method to clean");
    puts("the data, and send standard output to either the terminal or a text file.");
    puts("If no arguments are specified, the program will perform the imputation method.");
    puts("");
    puts("Usage:");
    puts("      clean [-d]");
    puts("      clean [--help]");
    puts("");
    puts("Arguments:");
    puts("      -d      Deletes each row that contains a NaN value.");
    puts("      --help  Displays the help message.");
    puts("");
    puts("Usage Examples:");
    puts("      clean       Cleans the data by replacing all occurences of NaN with the column average.");
    puts("      clean -d    Cleans the data by deleting each row containing NaN.");

}

/* Function Name: scanParameters
 *
 * Function Description:
 *  Scans command-line arguments to search for a -d or --help flag.
 *  Sets the base value, and if specified, the start, and finish values.
 * Return Value and Output:
 *  If the -d flag is present, return a value of 1 for further iteration.
 *  If the -d flag is not present, return a value of 0
 *  If the --help flag is used, print the corresponding message.
 */
int scanParameters(int argc, char *argv[]) {
    // checks if a command-line argument before performing operations
    if (argc > 1) {
        // checks if user inputs help message
        if (strcmp(argv[1], "--help") == 0) {
            printHelpMessage();
            exit(0);
        }
        // if -d flag is used, return 1
        else if (strcmp(argv[1], "-d") == 0) {
            return 1;
        }
    }
    // if -d flag is not used, return 0
    else {
        return 0;
    }
}