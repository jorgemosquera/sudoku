/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.h"
#include "arrayList.h"
#define MAX_NUM 9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printSudoku(int **sudoku) {

    /*
    0 1 2 3 4  5  6  7 8  9 10 11 12
    --------------------------------
     | 1 2 3 | 11 12 13 | 21 22 23 |
     | 4 5 6 | 41 42 43 | 51 52 53 |
     | 7 8 9 | 1 2 3 | 1 2 3 |
     -------------------------
     | 1 2 3 | 1 2 3 | 1 2 3 |
     | 1 2 3 | 1 2 3 | 1 2 3 |
     | 1 2 3 | 1 2 3 | 1 2 3 |
     ----------------|--------
     | 1 2 3 | 1 2 3 | 1 2 3 |
     | 1 2 3 | 1 2 3 | 1 2 3 |
     | 1 2 3 | 1 2 3 | 1 2 3 | 
     -------------------------
     * 
     */

    /*
     * this loop prints all the sudoku without formating
    printf("\n-------------------------\n");
    for(int i = 0; i < MAX_NUM; i++){
        for(int j = 0; j < MAX_NUM; j++){
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
     */

    // This loop iterates though the rows
    // i defines the row number
    printf("\n");
    for (int i = 0; i < MAX_NUM + 4; i++) {

        if (i % 4 == 0) {
            printf("-------------------------\n");
        } else {
            int shiftIndex = ((i % 4) - 1)*3;
            int shiftZones = (i / 4)*3;
            for (int j = 0; j < MAX_NUM + 4; j++) {
                if (j % 4 == 0) {
                    printf("| ");
                } else {
                    int value = sudoku[(j / 4) + shiftZones][(j % 4) - 1 + shiftIndex];
                    if (value) {
                        printf("%d ", value);
                    } else {
                        printf("  ");
                    }

                }
            }
            printf("\n");
        }
    }
}

/*
 * Given a array, shuffle the elements. 
 */
void shuffle(int* ptr) {

    int pos;
    int temp;
    for (int i = 0; i < MAX_NUM; i++) {
        pos = rand() % MAX_NUM;
        temp = ptr[pos];
        ptr[pos] = ptr[i];
        ptr[i] = temp;
    }
}

/*
 * Given a array, verify if it has unique elements.
 * Return 1 if is unique 0 if not.  
 */
int hasUniqueNumbers(int* ptr) {

    int numbers[MAX_NUM] = {0};
    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (ptr[i] != 0) {
            numbers[ptr[i] - 1]++;
        }
    }
    for (int i = 0; i < MAX_NUM; i++) {
        if (numbers[i] > 1) {
            return 0;
        }
    }
    return 1;
}

/*
 * Given a sudoku and a row number, modify an array of with the numbers of 
 * the specified row.
 */
void getRow(int* row, int** sudoku, int rowNumber) {

    int shiftZone = (rowNumber / 3)*3;
    int shiftIndex = 3 * (rowNumber % 3);
    // i controls the position of the result row
    for (int i = 0; i < MAX_NUM; i++) {
        row[i] = sudoku[i / 3 + shiftZone][i % 3 + shiftIndex];
    }
    //    printLine(row);
}

/*
 * Given a sudoku and a column number, modify an array with the numbers of 
 * the specified column.
 */
void getColumn(int* column, int** sudoku, int columnNumber) {

    int shiftZone = (columnNumber / 3);
    int shiftIndex = (columnNumber % 3);
    // i controls the position of the result row
    for (int i = 0; i < MAX_NUM; i++) {
        column[i] = sudoku[((i / 3)*3) + shiftZone][((i % 3)*3) + shiftIndex];
    }
}

// Prints the elements of the array

void printLine(int* line) {
    printf("\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d ", line[i]);
    }
}

void shuffleSudoku(int** sudoku) {
    for (int i = 0; i < MAX_NUM; i++) {
        shuffle(sudoku[i]);
    }
}

int correctSudoku(int** sudoku) {
    int result = 1;

    int row[MAX_NUM];
    int column[MAX_NUM];

    // First lets check if the zones are correct
    for (int i = 0; i < MAX_NUM; i++) {
        if (!hasUniqueNumbers(sudoku[i])) {
            result = 0;
            break;
        }
    }

    // Now lets check the rows:
    for (int i = 0; i < MAX_NUM; i++) {
        getRow(row, sudoku, i);
        if (!hasUniqueNumbers(row)) {
            result = 0;
            break;
        }
    }

    // finally lets check the columns:
    for (int i = 0; i < MAX_NUM; i++) {
        getColumn(column, sudoku, i);
        if (!hasUniqueNumbers(column)) {
            result = 0;
            break;
        }
    }

    return result;
}

/*
 * Given a array, return a list with the available numbers.
 * Return 0 if is available 1 if not.  
 */
void checkAvailableNumbersByZone(int* line, int** sudoku, int zone) {

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (sudoku[zone][i] != 0) {
            line[sudoku[zone][i] - 1]++;
        }
    }
}

/*
 * Given a array, return a list with the available numbers.
 * Return 0 if is available 1 if not.  
 */
void checkAvailableNumbersByRow(int* line, int** sudoku, int rowNumber) {

    int rowTemp[MAX_NUM] = {0};
    getRow(rowTemp, sudoku, rowNumber);
    //    printLine(rowTemp);

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (rowTemp[i] != 0) {
            line[rowTemp[i] - 1]++;
        }
    }
    //    printLine(line);
}

/*
 * Given a array, return a list with the available numbers.
 * Return 0 if is available 1 if not.  
 */
void checkAvailableNumbersByColumn(int* line, int** sudoku, int columnNumber) {

    int column[MAX_NUM] = {0};
    getColumn(column, sudoku, columnNumber);

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (column[i] != 0) {
            line[column[i] - 1]++;
        }
    }
}

/*
 * Given a array, return a list with the available numbers.
 * Return 0 if is available 1 if not.  
 */
void checkAvailableNumbers(int* line, int** sudoku, int rowNumber, int columnNumber) {
    int column[MAX_NUM] = {0};
    int row[MAX_NUM] = {0};
    int zone[MAX_NUM] = {0};

    int zoneNumber = (rowNumber / 3)*3 + columnNumber / 3;

    checkAvailableNumbersByColumn(column, sudoku, columnNumber);
    checkAvailableNumbersByRow(row, sudoku, rowNumber);
    checkAvailableNumbersByZone(zone, sudoku, zoneNumber);

    for (int i = 0; i < MAX_NUM; i++) {
        line[i] = column[i] | row[i];
        line[i] = line[i] | zone[i];
    }

}

int quantityNumbersAvailable(int* temp) {
    int result = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (!temp[i]) {
            result++;
        }
    }
    //    printf("\nthe quantity of numbers available is: %d", result);
    return result;
}

void printAvailableNumbers(int** sudoku, int zone) {

    int* tempLine = malloc(sizeof (int)*MAX_NUM);
    if (tempLine == NULL) {
        printf("There was a problem creating the row. GoodBye.");
        exit(0);
    }

    checkAvailableNumbersByZone(tempLine, sudoku, zone);

    for (int i = 0; i < MAX_NUM; i++) {
        if (tempLine[i] != 1) {
            printf("%d ", i + 1);
        }
    }

    free(tempLine);
}

int pickAvailableNumber(int** sudoku, int rowNumber, int columnNumber) {

    int pos = 0;
    int tempLine[MAX_NUM] = {0};

    checkAvailableNumbers(tempLine, sudoku, rowNumber, columnNumber);
    //    printLine(tempLine);
    int quantity = quantityNumbersAvailable(tempLine);

    if (quantity > 0) {

        do {
            pos = rand() % MAX_NUM;
            //    printf("\nThe position is: %d",pos);
            //    printf("\nthe value of %d is %d",pos+1,tempLine[pos]);
            //    printf("\nThe number %d is %s available",pos+1,tempLine[pos]?"not":"");

        } while (tempLine[pos]);
        pos = pos + 1;
    }
    //    printf("\nThe number picked is: %d",pos);
    //    free(tempLine);

    return pos;
}

void createSudoku(int** sudoku) {

    int row = 0;
    while (row < MAX_NUM) {
        if (createByRow(sudoku, row)) {
            resetSudoku(sudoku);
            row = 0;
        } else {
            row++;
        }
    }
    printSudoku(sudoku);


}

int createRow(int** sudoku, int rowNumber) {
    int zone;
    int index;
    int row = rowNumber;
    int column = 0;

    // create firstRow row= 0
    for (column = 0; column < MAX_NUM; column++) {
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        do {
            int selectedValue = pickAvailableNumber(sudoku, row, column);
            if (selectedValue == 0) {
                return 1;
            } else {
                sudoku[zone][index] = selectedValue;
            }

        } while (!correctSudoku(sudoku));
        //        printSudoku(sudoku);
    }

    return 0;
}

int createByRow(int** sudoku, int rowNumber) {

    int clearNumber = 0;
    while (createRow(sudoku, rowNumber)) {
        if (clearNumber == 5) {
            return 1;
        }
        clearRow(sudoku, rowNumber);
        clearNumber++;
    }
    return 0;
}

void clearRow(int** sudoku, int rowNumber) {
    //    printf("\nCLearing row and starting again");
    int shiftZone = (rowNumber / 3)*3;
    int shiftIndex = 3 * (rowNumber % 3);
    // i controls the position of the result row
    for (int i = 0; i < MAX_NUM; i++) {
        sudoku[i / 3 + shiftZone][i % 3 + shiftIndex] = 0;
        ;
    }
}

void resetSudoku(int** sudoku) {
    //    printf("\nSudoku Reset");
    for (int i = 0; i < MAX_NUM; i++) {
        for (int j = 0; j < MAX_NUM; j++) {
            sudoku[i][j] = 0;
        }
    }
}

/*
 * Given a array, return a list with the available slots.
 * Return 0 if the slot is available, 1 if it is not available.  
 */
void checkAvailableSlotsByZone(int* line, int** sudoku, int zone) {

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (sudoku[zone][i] != 0) {
            line[i]++;
        }
    }
}

/*
 * Given a array, return a list with the available slots.
 * Return 0 if the slot is available, 1 if it is not available.  
 */
void checkAvailableSlotsByRow(int* line, int** sudoku, int row) {
    int rowTemp[MAX_NUM] = {0};
    getRow(rowTemp, sudoku, row);

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (rowTemp[i] != 0) {
            line[i]++;
        }
    }
}

/*
 * Given a array, return a list with the available slots.
 * Return 0 if the slot is available, 1 if it is not available.  
 */
void checkAvailableSlotsByColumn(int* line, int** sudoku, int column) {
    int columnTemp[MAX_NUM] = {0};
    getColumn(columnTemp, sudoku, column);

    for (int i = 0; i < MAX_NUM; i++) {
        // In order to allow for null values. 0 will be skipped.
        if (columnTemp[i] != 0) {
            line[i]++;
        }
    }
}

int isNumberInLine(int* line, int number) {
    int result = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (line[i] == number) {
            result = 1;
            break;
        }
    }
    return result;
}

// Returns an array with the zones that have missing numbers. 0 zone has a missing number
// 1 the zone doesn't have missing number.

void getZonesWithMissingNumbers(int* line, int** sudoku) {
    for (int i = 0; i < MAX_NUM; i++) {
        line[i] = 0;
        for (int j = 0; j < MAX_NUM; j++) {
            if (sudoku[i][j] == 0) {
                line[i]++;
                break;
            }
        }
    }
}

void solveByOnePositionInZone(int** sudoku) {
    //    Lets start try to solve a sudoku
    int continueCheckingZones = 0;
    int zones[MAX_NUM] = {0};
    do {
        getZonesWithMissingNumbers(zones, sudoku);
        //        printf("\nthe zones with missing numbers:");
        //        printLine(zones);

        continueCheckingZones = 0;
        for (int zone = 0; zone < MAX_NUM; zone++) {
            if (zones[zone]) {
                // The idea is to loop trough the zones, looking for easy numbers
                int availableNumbers[MAX_NUM] = {0};
                int availableSlots[MAX_NUM] = {0};

                // we start looping through the available numbers
                int number = 0;
                int continueChecking = 0;
                do {
                    // First we check for the available Numbers per zone
                    checkAvailableNumbersByZone(availableNumbers, sudoku, zone);
                    continueChecking = 0;
                    //TODO: just loop trough the available numbers. not all of them/
                    for (int i = 0; i < MAX_NUM; i++) {
                        // And we check for the available slots
                        checkAvailableSlotsByZone(availableSlots, sudoku, zone);
                        if (!availableNumbers[i]) {
                            number = i + 1;
                            int possibleSlots[MAX_NUM] = {0};

                            // and now we start looping though the empty slots
                            for (int i = 0; i < MAX_NUM; i++) {
                                if (availableSlots[i]) {
                                    possibleSlots[i]++;
                                } else {
                                    int row[MAX_NUM] = {0};
                                    int column[MAX_NUM] = {0};
                                    int rowNumber = i / 3 + (zone / 3)*3;
                                    int columnNumber = i % 3 + (zone % 3)*3;
                                    getRow(row, sudoku, rowNumber);
                                    getColumn(column, sudoku, columnNumber);
                                    if (isNumberInLine(row, number) || isNumberInLine(column, number)) {
                                        possibleSlots[i]++;
                                    }
                                }
                            }

                            // we get the list of possibleSlot position for the number in that zone
                            int index = 0;
                            // if there is only one possible slot for the number in that zone
                            if (quantityNumbersAvailable(possibleSlots) == 1) {

                                // we get the index of the slot
                                for (int i = 0; i < MAX_NUM; i++) {
                                    if (!possibleSlots[i]) {
                                        index = i;
                                        break;
                                    }
                                }

                                // and we assign the number to that zone.
                                sudoku[zone][index] = number;
                                // if we assign a number we check again.
                                continueChecking = 1;
                                continueCheckingZones = 1;
                            }
                        }

                    }
                } while (continueChecking);
            }
        }
    } while (continueCheckingZones);
}

void solveSudoku(int** sudoku) {
    int checking = 0;
    do {
        checking = 0;
        solveByOnePositionInZone(sudoku);
        solveByRow(sudoku, &checking);
        solveByColumn(sudoku, &checking);
    } while(checking);
    

}

int solveRow(int** sudoku, int rowNumber, int* checking) {

    int number = 0; // temp variable to translate from rowNumbers to Sudoku Number
    int rowNumbers[MAX_NUM] = {0};
    int rowSlots[MAX_NUM] = {0};
    int result = 0;

    checkAvailableNumbersByRow(rowNumbers, sudoku, rowNumber);
    checkAvailableSlotsByRow(rowSlots, sudoku, rowNumber);

    //    printLine(rowNumbers);
    //    printLine(rowSlots);

    // we start looping through the available Numbers
    for (int i = 0; i < MAX_NUM; i++) {
        if (!rowNumbers[i]) {
            number = i + 1;
            int possibleSlots[MAX_NUM] = {0};
            // and now we start looping though the empty slots
            for (int i = 0; i < MAX_NUM; i++) {
                if (rowSlots[i]) {
                    possibleSlots[i]++;
                } else {
                    int column[MAX_NUM] = {0};
                    getColumn(column, sudoku, i);
                    if (isNumberInLine(column, number)) {
                        possibleSlots[i]++;
                    }
                }
            }
            // we get the list of possibleSlot position for the number in that row
            int position = 0;
            // if there is only one possible slot for the number in that zone
            if (quantityNumbersAvailable(possibleSlots) == 1) {
                // we get the index of the slot
                for (int i = 0; i < MAX_NUM; i++) {
                    if (!possibleSlots[i]) {
                        position = i;
                        break;
                    }
                }
                // and we assign the number to that zone.
                int zone = (rowNumber / 3)*3 + position / 3;
                int index = (rowNumber % 3)*3 + position % 3;
                sudoku[zone][index] = number;
                result = 1;
                *checking = 1;
            }
        }
    }
    
    return result;
}

int solveColumn(int** sudoku, int columnNumber, int* checking) {
    int number = 0; // temp variable to translate from rowNumbers to Sudoku Number
    int columnNumbers[MAX_NUM] = {0};
    int columnSlots[MAX_NUM] = {0};
    int result = 0;

    checkAvailableNumbersByColumn(columnNumbers, sudoku, columnNumber);
    checkAvailableSlotsByColumn(columnSlots, sudoku, columnNumber);

    // we start looping through the available Numbers
    for (int i = 0; i < MAX_NUM; i++) {
        if (!columnNumbers[i]) {
            number = i + 1;
            int possibleSlots[MAX_NUM] = {0};
            // and now we start looping though the empty slots
            for (int i = 0; i < MAX_NUM; i++) {
                if (columnSlots[i]) {
                    possibleSlots[i]++;
                } else {
                    int row[MAX_NUM] = {0};
                    getRow(row, sudoku, i);
                    if (isNumberInLine(row, number)) {
                        possibleSlots[i]++;
                    }
                }
            }

            // we get the list of possibleSlot position for the number in that row
            int position = 0;
            // if there is only one possible slot for the number in that zone
            if (quantityNumbersAvailable(possibleSlots) == 1) {
                // we get the index of the slot
                for (int i = 0; i < MAX_NUM; i++) {
                    if (!possibleSlots[i]) {
                        position = i;
                        break;
                    }
                }
                // and we assign the number to that zone.
                int zone = (position / 3)*3 + columnNumber / 3;
                int index = (position % 3)*3 + columnNumber % 3;
                sudoku[zone][index] = number;
                result = 1;
                *checking = 1;
            }
        }
    }

    return result;
}

void solveByRow(int** sudoku, int* checking) {
    int continueChecking = 0;
    for (int row = 0; row < MAX_NUM; row++){
        continueChecking = 0;
        do {
            continueChecking = solveRow(sudoku,row, checking);
        } while(continueChecking);
    }
}

void solveByColumn(int** sudoku, int* checking) {
    int continueChecking = 0;
    for (int column = 0; column < MAX_NUM; column++){
        continueChecking = 0;
        do {
            continueChecking = solveColumn(sudoku,column, checking);
        } while(continueChecking);
    }
}
