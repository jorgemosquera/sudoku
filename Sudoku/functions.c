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

void printSudoku(int **sudoku){
    
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
    for(int i = 0; i < MAX_NUM + 4; i++){
        
        if(i%4==0){
            printf("-------------------------\n");
        }
        else {
            int shiftIndex = ((i%4)-1)*3;
            int shiftZones = (i/4)*3;
            for(int j = 0; j < MAX_NUM + 4; j++){
                if(j%4==0){
                    printf("| ");
                }
                else {
                    int value = sudoku[(j/4)+shiftZones][(j%4)-1 + shiftIndex];
                    if(value){
                        printf("%d ",value);
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
void shuffle(int* ptr){
    
    int pos;
    int temp;
    for(int i = 0; i < MAX_NUM; i++){
        pos = rand()% MAX_NUM;
        temp = ptr[pos];
        ptr[pos] = ptr[i];
        ptr[i] = temp;
    }
}


/*
 * Given a array, verify if it has unique elements.
 * Return 1 if is unique 0 if not.  
*/
int hasUniqueNumbers(int* ptr){

    int numbers[MAX_NUM] = {0};
    for (int i = 0; i < MAX_NUM; i++){
        // In order to allow for null values. 0 will be skipped.
        if(ptr[i]!=0){
            numbers[ptr[i]-1]++;
        }
    }
    for(int i = 0; i < MAX_NUM; i++){
        if(numbers[i]>1){
            return 0;          
        }
    }
    return 1;
}


/*
 * Given a sudoku and a row number, modify an array of with the numbers of 
 * the specified row.
*/
void getRow(int* row, int** sudoku, int rowNumber){

    int shiftZone = (rowNumber/3)*3;
    int shiftIndex =  3*(rowNumber%3);
    // i controls the position of the result row
    for(int i = 0; i < MAX_NUM; i++){
        row[i] = sudoku[i/3+ shiftZone][i%3+ shiftIndex];
    }   
//    printLine(row);
}

/*
 * Given a sudoku and a column number, modify an array with the numbers of 
 * the specified column.
*/
void getColumn(int* column, int** sudoku, int columnNumber){

    int shiftZone = (columnNumber/3);
    int shiftIndex =  (columnNumber%3);
    // i controls the position of the result row
    for(int i = 0; i < MAX_NUM; i++){
        column[i] = sudoku[((i/3)*3)+shiftZone][((i%3)*3)+shiftIndex];
    }
}

void printLine(int* line){
    printf("\nThe values of the line are:\n");
    for(int i = 0; i< MAX_NUM; i++){
        printf("%d ",line[i]);
    }
}

void shuffleSudoku(int** sudoku){
    for(int i = 0; i< MAX_NUM ; i++ ){
        shuffle(sudoku[i]);
    }
}

void createSudoku(int** sudoku){
    int correctSudoku = 1;
    int iterations = 0;
    
    int* row = malloc(sizeof(int)*MAX_NUM);
    if(row == NULL){
        printf("There was a problem creating the row. GoodBye.");
        exit;       
    }
    
    int* column = malloc(sizeof(int)*MAX_NUM);
    if(column == NULL){
        printf("There was a problem creating the row. GoodBye.");
        exit;       
    }
    
    while(correctSudoku){
        printf("%d\n", iterations);
        shuffleSudoku(sudoku);
        for(int i = 0; i < MAX_NUM; i++){
            getRow(row, sudoku, i);
            if(hasUniqueNumbers(row)){
                correctSudoku = 0;
            } else {
                correctSudoku = 1;
                break;
            }
        }
        
        for(int i = 0; i < MAX_NUM; i++){
            getColumn(column, sudoku, i);
            if(hasUniqueNumbers(column)){
                correctSudoku = 0;
            } else {
                correctSudoku = 1;
                break;
            }
        }
        iterations++;
    }
    
    printSudoku(sudoku);
    free(row);
    free(column);
} 

int correctSudoku(int** sudoku){
    int result = 1;
    
    int row[MAX_NUM];
    int column[MAX_NUM];
    
    // First lets check if the zones are correct
    for(int i =0; i < MAX_NUM; i++){
        if(!hasUniqueNumbers(sudoku[i])){
            result = 0;
            break;
        }
    }
    
    // Now lets check the rows:
    for(int i =0; i < MAX_NUM; i++){
        getRow(row, sudoku, i);
        if(!hasUniqueNumbers(row)){
            result = 0;
            break;
        }
    }
    
    // finally lets check the columns:
    for(int i =0; i < MAX_NUM; i++){
        getColumn(column, sudoku, i);
        if(!hasUniqueNumbers(column)){
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
void checkAvailableNumbersByZone(int* line, int** sudoku, int zone){

    for (int i = 0; i < MAX_NUM; i++){
        // In order to allow for null values. 0 will be skipped.
        if(sudoku[zone][i]!=0){
            line[sudoku[zone][i]-1]++;
        }
    }
}

/*
 * Given a array, return a list with the available numbers.
 * Return 0 if is available 1 if not.  
*/
void checkAvailableNumbersByRow(int* line, int** sudoku, int rowNumber){
    
    int rowTemp[MAX_NUM] = {0};    
    getRow(rowTemp, sudoku, rowNumber);
//    printLine(rowTemp);
    
    for (int i = 0; i < MAX_NUM; i++){
        // In order to allow for null values. 0 will be skipped.
        if(rowTemp[i]!=0){
            line[rowTemp[i]-1]++;
        }
    }
//    printLine(line);
}

void checkAvailableNumbersByColumn(int* line, int** sudoku, int columnNumber){
    
    int column[MAX_NUM] = {0};
    getColumn(column, sudoku, columnNumber);
    
    for (int i = 0; i < MAX_NUM; i++){
        // In order to allow for null values. 0 will be skipped.
        if(column[i]!=0){
            line[column[i]-1]++;
        }
    }
}

void checkAvailableNumbers(int* line, int** sudoku, int rowNumber, int columnNumber){
    int column[MAX_NUM] = {0};
    int row[MAX_NUM] = {0};
    int zone[MAX_NUM] = {0};
    
    int zoneNumber = (rowNumber/3)*3 + columnNumber/3;
    
    checkAvailableNumbersByColumn(column, sudoku, columnNumber);
    checkAvailableNumbersByRow(row, sudoku, rowNumber);
    checkAvailableNumbersByZone(zone, sudoku, zoneNumber);
    
//    printf("\nRow:");
//    printLine(row);
//    printf("\nColumn:");
//    printLine(column);
//    printf("\nZone:");
//    printLine(zone);
    
    for(int i = 0; i < MAX_NUM; i ++) {
        line[i] = column[i] | row[i];
        line[i] = line[i] | zone[i];
    }
    
//    printf("\nResult:");
//    printLine(line);    
}

int quantityNumbersAvailable(int* temp){
    int result = 0;
    for (int i = 0; i < MAX_NUM; i++){
        if(!temp[i]){
            result++;
        }
    }
    printf("\nthe quantity of numbers available is: %d", result);
    return result;
}

void printAvailableNumbers(int** sudoku, int zone){
    
    int* tempLine = malloc(sizeof(int)*MAX_NUM);
    if(tempLine == NULL){
        printf("There was a problem creating the row. GoodBye.");
        exit(0);       
    }
    
    checkAvailableNumbersByZone(tempLine, sudoku, zone);
    
    for(int i = 0; i < MAX_NUM; i++){
        if(tempLine[i]!=1){
            printf("%d ", i+1);
        }
    }
    
    free(tempLine);
}

int pickAvailableNumber(int** sudoku, int rowNumber, int columnNumber){
    
    int pos = 0;
    int tempLine[MAX_NUM] = {0};
    
    checkAvailableNumbers(tempLine, sudoku, rowNumber, columnNumber);
//    printLine(tempLine);
    int quantity = quantityNumbersAvailable(tempLine);
   
    if(quantity> 0){
    
        do {
        pos = rand()% MAX_NUM;
    //    printf("\nThe position is: %d",pos);
    //    printf("\nthe value of %d is %d",pos+1,tempLine[pos]);
    //    printf("\nThe number %d is %s available",pos+1,tempLine[pos]?"not":"");

        } while(tempLine[pos]);
        pos = pos + 1;
    } 
    printf("\nThe number picked is: %d",pos);
//    free(tempLine);
    
    return pos;
}

void createSudoku2(int** sudoku){
    int zone;
    int index;
    for (int i = 0; i < MAX_NUM; i++){ // rows
        for (int j = 0; j < MAX_NUM; j++){ // columns
            zone = (i/3)*3 + j/3;
            index = (i%3)*3 + j%3;
//            printf("%d %d\n",zone,index);

            do {
                sudoku[zone][index] = pickAvailableNumber(sudoku,i,j);
            }
            while(!correctSudoku(sudoku));
            
            printSudoku(sudoku);
        }   
    }
}

void createSudoku3(int** sudoku) {
    int zone;
    int index;
    int row = 0;
    int column = 0;

    // create firstRow row= 0
    for (column = 0; column < MAX_NUM; column++) {
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        do {
            sudoku[zone][index] = pickAvailableNumber(sudoku, row, column);
        } while (!correctSudoku(sudoku));
        printSudoku(sudoku);
    }
    
    //create secondRow row = 1
    //take zone 2 numbers
    
    numbers_t* zone2Numbers = createList();
    for(int i = 0; i < MAX_NUM/3 ; i++){
        appendNumber(&zone2Numbers,sudoku[2][i]);
    }
    displayList(zone2Numbers);
    
//    int selectedValue = pickNumberFromList(&zone2Numbers);
//    printf("\nThe selected value is: %d", selectedValue);
//    removeByValue(&zone2Numbers, selectedValue);
//    displayList(zone2Numbers);
    
//    
//    //take empty slots from zone 0 and 1
    int emptySlots[MAX_NUM-3] = {0};
    int randomSlot = 0;
    
    while(length(zone2Numbers)){
        //pick a random slot from zone2Numbers
        do {
            randomSlot = rand()%(MAX_NUM - 3);
        } while (emptySlots[randomSlot]);
        emptySlots[randomSlot] = 1;
//        printf("\nThe selected slot is: %d",randomSlot);
        
        // convert the randomSlot to zone index notation.
        row = 1;
        column = randomSlot;
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        int selectedValue = 0;
        
        do {
            selectedValue = pickNumberFromList(&zone2Numbers);
            sudoku[zone][index] = selectedValue;
        } while (!correctSudoku(sudoku));
//            printf("\nThe selected value is: %d", selectedValue);

        removeByValue(&zone2Numbers, selectedValue);
        
        printSudoku(sudoku);
        
//        displayList(zone2Numbers);
    }
    
    
}