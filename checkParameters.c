/* Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * This code works as a command-line utility, that checks for any additional parameters entered by the user.
 * It will scan for the -d flag, and return a value based on the arguments for additional implementation
 * The program accurately handles invalid inputs, and allows users to access a help message if they require.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Name of the function: printHelpMessage
 *
 * Function Description:
 *  Outputs a help message that guides the user on how to use the program properly.
 */
int printHelpMessage() {
    puts("Usage: clean [-d]");
}

/* Name of the function: scanParameters
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
            puts("-d USED");
            return 1;
        }
    }
    // if -d flag is not used, return 0
    else {
        puts("no -d USED");
        return 0;
    }
}