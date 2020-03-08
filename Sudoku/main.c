/* 
 * File:   main.c
 * Author: j_a_m
 *
 * Created on February 2, 2020, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9
void printLine(int* line);
void printSudoku(int** sudoku);
void shuffle(int* zone);
int hasUniqueNumbers(int* ptr);
void getRow(int* rowResult, int** sudoku, int rowNumber);
void getColumn(int* columnResult, int** sudoku, int columnNumber);

void shuffleSudoku(int** sudoku);
void createSudoku(int** sudoku);
int correctSudoku(int** sudoku);


/*
 * 
 */
int main() {
    
    srand((unsigned int)(time(NULL)));
    
    //this is a correct Sudoku Example
    
    int* goodSudoku[9]; 
    
     
    int xzone1[MAX_NUM] = {9, 7, 8, 2, 5, 1, 4, 3, 6};
    int xzone2[MAX_NUM] = {1, 6, 4, 7, 3, 8, 5, 2, 9};
    int xzone3[MAX_NUM] = {5, 3, 2, 9, 4, 6, 1, 8, 7};
    int xzone4[MAX_NUM] = {7, 4, 5, 6, 9, 3, 1, 8, 2};
    int xzone5[MAX_NUM] = {2, 9, 3, 8, 1, 5, 6, 4, 7};
    int xzone6[MAX_NUM] = {6, 1, 8, 7, 2, 4, 3, 9, 5};
    int xzone7[MAX_NUM] = {8, 6, 4, 3, 2, 9, 5, 1, 7};
    int xzone8[MAX_NUM] = {3, 5, 1, 4, 7, 6, 9, 8, 2};
    int xzone9[MAX_NUM] = {2, 7, 9, 8, 5, 1, 4, 6, 3};
    
    goodSudoku[0] = xzone1;
    goodSudoku[1] = xzone2;
    goodSudoku[2] = xzone3;
    goodSudoku[3] = xzone4;
    goodSudoku[4] = xzone5;
    goodSudoku[5] = xzone6;
    goodSudoku[6] = xzone7;
    goodSudoku[7] = xzone8;
    goodSudoku[8] = xzone9;
    
                         
/*
    int zone1[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone2[MAX_NUM] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int zone3[MAX_NUM] = {21, 22, 23, 24, 25, 26, 27, 28, 29};
    int zone4[MAX_NUM] = {31, 32, 33, 34, 35, 36, 37, 38, 39};
    int zone5[MAX_NUM] = {41, 42, 43, 44, 45, 46, 47, 48, 49};
    int zone6[MAX_NUM] = {51, 52, 53, 54, 55, 56, 57, 58, 59};
    int zone7[MAX_NUM] = {61, 62, 63, 64, 65, 66, 67, 68, 69};
    int zone8[MAX_NUM] = {71, 72, 73, 74, 75, 76, 77, 78, 79};
    int zone9[MAX_NUM] = {81, 82, 83, 84, 85, 86, 87, 88, 89};
*/    
    int *sudoku[9]; 
    
    int zone1[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone2[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone3[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone4[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone5[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone6[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone7[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone8[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone9[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    sudoku[0] = zone1;
    sudoku[1] = zone2;
    sudoku[2] = zone3;
    sudoku[3] = zone4;
    sudoku[4] = zone5;
    sudoku[5] = zone6;
    sudoku[6] = zone7;
    sudoku[7] = zone8;
    sudoku[8] = zone9;
    
     
    
//=============================================================================== 
    
//    int test[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    shuffle(test, MAX_NUM);
//    printf("The array is unique: %s",hasUniqueNumbers(test, MAX_NUM)?"TRUE":"FALSE");
    
//    printSudoku(sudoku);
    
//    ===========================================================================
//  Testing getRow    
    /*
    int* row = malloc(sizeof(int)*MAX_NUM);
    if(row == NULL){
        printf("There was a problem creating the row. GoodBye.");
        exit;       
    }
    
//    getRow(row,sudoku,8);
    
    free(row);
    */

//    ===========================================================================
//  Testing getColumn
    /*
    int* column = malloc(sizeof(int)*MAX_NUM);
    if(column == NULL){
        printf("There was a problem creating the row. GoodBye.");
        exit;       
    }
    
//    getColumn(column,sudoku,8);
//    printLine(column);
    
    free(column);
*/
//    ===========================================================================
//  Testing shuffleSudoku
    
//    shuffleSudoku(sudoku);
    
//    printSudoku(sudoku);
    
//    createSudoku(sudoku);

//    ===========================================================================
    
    printf("Is a correct Sudoku ? %s",correctSudoku(sudoku)?"YES":"NO");
    
    return (0);
}

void printSudoku(int *sudoku[]){
    
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
                    printf("%d ",sudoku[(j/4)+shiftZones][(j%4)-1 + shiftIndex]);
                }
            }
            printf("\n");
    }
    }
}

void shuffle(int* ptr){
    
/*
 * Given a array, shuffle the elements. 
*/  
    int pos;
    int temp;
    for(int i = 0; i < MAX_NUM; i++){
        pos = rand()% MAX_NUM;
        temp = ptr[pos];
        ptr[pos] = ptr[i];
        ptr[i] = temp;
    }
}

int hasUniqueNumbers(int* ptr){
/*
 * Given a array, verify if it has unique elements.
 * Return 1 if is unique 0 if not.  
*/
    int numbers[MAX_NUM] = {0};
    for (int i = 0; i < MAX_NUM; i++){
        numbers[ptr[i]]++;
    }
    for(int i = 0; i < MAX_NUM; i++){
        if(numbers[i]>1){
            return 0;          
        }
    }
    return 1;
}

void getRow(int* row, int** sudoku, int rowNumber){
/*
 * Given a sudoku and a row number, modify an array of with the numbers of 
 * the specified row.
*/
    int shiftZone = (rowNumber/3)*3;
    int shiftIndex =  3*(rowNumber%3);
    // i controls the position of the result row
    for(int i = 0; i < MAX_NUM; i++){
        row[i] = sudoku[i/3+ shiftZone][i%3+ shiftIndex];
    }    
}

void getColumn(int* column, int** sudoku, int columnNumber){
/*
 * Given a sudoku and a column number, modify an array with the numbers of 
 * the specified column.
*/
    int shiftZone = (columnNumber/3);
    int shiftIndex =  (columnNumber%3);
    // i controls the position of the result row
    for(int i = 0; i < MAX_NUM; i++){
        column[i] = sudoku[((i/3)*3)+shiftZone][((i%3)*3)+shiftIndex];
    }
}

void printLine(int* line){
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
    
    free(row);
    free(column);
    
    return result;
}