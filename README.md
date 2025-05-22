# clean - Data Cleaning Utility  
A C-based command-line tool for cleaning data by deleting or inserting missing values.

---

## Description  
The `clean` utility processes data containing `NaN` entries (not-a-number), allowing users to choose between two cleaning methods:

- **Imputation:** Replace `NaN` values with the average of their respective columns.
- **Deletion:** Remove rows that contain any `NaN` values.

It reads data from standard input and writes the cleaned result to standard output in the same format.

---

## Getting Started

### Dependencies  
- Terminal environment (Linux, macOS, WSL)  
- GCC or any C compiler  

### Installing  
1. Clone or download the repository:

    ```bash
    git clone https://github.com/benbloomie/2XC3-the-data-processing-assignment
    cd 2XC3-the-data-processing-assignment
    ```

2. Compile the program using the Makefile:

    ```bash
    make
    ```

---

## Executing the Program

## Executing the Program

Run the program using `clean`. Use the following options:

- To clean data using the **default imputation strategy** (replace `NaN` with column averages):

    ```bash
    File: bad_data.txt
    3 4
    nan nan 5.3 1.0
    nan 1.8 1.9 nan
    nan 2.8 nan nan
    
    ./clean < bad_data.txt > cleaned_data.txt
    
    File: cleaned_data.txt
    3 4
    0.000 2.300 5.300 1.000
    0.000 1.800 1.900 1.000
    0.000 2.800 3.600 1.000
    ```

- To clean data using the **deletion strategy** (remove rows containing `NaN` values):

    ```bash
    File: bad_data2.txt
    4 4
    nan nan 5.3 1.0
    1.0 1.8 1.9 2.3
    nan 2.8 nan nan
    0.0 1.2 3.4 5.6
    
    ./clean -d < bad_data2.txt > cleaned_data.txt
    
    File: cleaned_data.txt
    2 4
    1.000 1.800 1.900 2.300
    0.000 1.200 3.400 5.600
