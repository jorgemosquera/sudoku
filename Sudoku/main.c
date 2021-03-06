/* 
 * File:   main.c
 * Author: j_a_m
 *
 * Created on February 2, 2020, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"
#include "arrayList.h"
#include "gridFunctions.h"

#define MAX_NUM 9




/*
 * 
 */
int main() {
    
    srand((unsigned int)(time(NULL)));
    
    int* easySudoku[9];
    int easy1[MAX_NUM] = {0, 3, 0, 7, 5, 0, 0, 0, 6};
    int easy2[MAX_NUM] = {0, 1, 0, 0, 3, 0, 9, 8, 4};
    int easy3[MAX_NUM] = {0, 6, 0, 0, 4, 8, 3, 0, 0};
    int easy4[MAX_NUM] = {0, 0, 3, 9, 1, 2, 0, 0, 4};
    int easy5[MAX_NUM] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int easy6[MAX_NUM] = {8, 0, 0, 6, 7, 4, 5, 0, 0};
    int easy7[MAX_NUM] = {0, 0, 1, 6, 8, 0, 0, 9, 0};
    int easy8[MAX_NUM] = {6, 7, 5, 0, 9, 0, 0, 4, 0};
    int easy9[MAX_NUM] = {2, 0, 0, 0, 1, 5, 0, 3, 0};
    
    easySudoku[0] = easy1;
    easySudoku[1] = easy2;
    easySudoku[2] = easy3;
    easySudoku[3] = easy4;
    easySudoku[4] = easy5;
    easySudoku[5] = easy6;
    easySudoku[6] = easy7;
    easySudoku[7] = easy8;
    easySudoku[8] = easy9;
       
    int* intermediateSudoku[9];
    int intermediate1[MAX_NUM] = {6,0,9,7,1,0,0,5,0};
    int intermediate2[MAX_NUM] = {0,4,0,5,0,9,0,0,0};
    int intermediate3[MAX_NUM] = {0,0,1,6,0,0,0,0,0};
    int intermediate4[MAX_NUM] = {2,0,7,0,0,0,0,6,0};
    int intermediate5[MAX_NUM] = {0,8,0,0,6,0,9,0,0};
    int intermediate6[MAX_NUM] = {0,9,0,0,2,4,0,0,8};
    int intermediate7[MAX_NUM] = {0,0,8,0,0,0,0,0,0};
    int intermediate8[MAX_NUM] = {0,0,0,4,0,0,0,5,0};
    int intermediate9[MAX_NUM] = {3,0,0,0,0,7,0,0,0};
    
    intermediateSudoku[0] = intermediate1;
    intermediateSudoku[1] = intermediate2;
    intermediateSudoku[2] = intermediate3;
    intermediateSudoku[3] = intermediate4;
    intermediateSudoku[4] = intermediate5;
    intermediateSudoku[5] = intermediate6;
    intermediateSudoku[6] = intermediate7;
    intermediateSudoku[7] = intermediate8;
    intermediateSudoku[8] = intermediate9;
    
    
    int* unsolvedSudoku[9];
    
    int yzone1[MAX_NUM] = {0, 8, 0, 4, 0, 0, 0, 0, 0};
    int yzone2[MAX_NUM] = {0, 0, 0, 0, 0, 6, 0, 3, 0};
    int yzone3[MAX_NUM] = {0, 3, 2, 5, 0, 0, 1, 0, 0};
    int yzone4[MAX_NUM] = {0, 0, 3, 1, 0, 0, 0, 0, 4};
    int yzone5[MAX_NUM] = {6, 0, 5, 0, 0, 0, 8, 0, 7};
    int yzone6[MAX_NUM] = {4, 0, 0, 0, 0, 6, 9, 0, 0};
    int yzone7[MAX_NUM] = {0, 0, 9, 0, 0, 8, 6, 2, 0};
    int yzone8[MAX_NUM] = {0, 5, 0, 7, 0, 0, 0, 0, 0};
    int yzone9[MAX_NUM] = {0, 0, 0, 0, 0, 9, 0, 8, 0};
    
    unsolvedSudoku[0] = yzone1;
    unsolvedSudoku[1] = yzone2;
    unsolvedSudoku[2] = yzone3;
    unsolvedSudoku[3] = yzone4;
    unsolvedSudoku[4] = yzone5;
    unsolvedSudoku[5] = yzone6;
    unsolvedSudoku[6] = yzone7;
    unsolvedSudoku[7] = yzone8;
    unsolvedSudoku[8] = yzone9;
    
    //this is a new sudoko
    
    int* newSudoku[9];
    
    int nzone1[MAX_NUM] = {0};
    int nzone2[MAX_NUM] = {0};
    int nzone3[MAX_NUM] = {0};
    int nzone4[MAX_NUM] = {0};
    int nzone5[MAX_NUM] = {0};
    int nzone6[MAX_NUM] = {0};
    int nzone7[MAX_NUM] = {0};
    int nzone8[MAX_NUM] = {0};
    int nzone9[MAX_NUM] = {0};
    
    newSudoku[0] = nzone1;
    newSudoku[1] = nzone2;
    newSudoku[2] = nzone3;
    newSudoku[3] = nzone4;
    newSudoku[4] = nzone5;
    newSudoku[5] = nzone6;
    newSudoku[6] = nzone7;
    newSudoku[7] = nzone8;
    newSudoku[8] = nzone9;
    
    
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
    
    int *sudoku2[9]; 
    
    int zone21[MAX_NUM] = {5,0,1,0,9,0,0,0,0};
    int zone22[MAX_NUM] = {0,0,0,3,0,6,0,9,0};
    int zone23[MAX_NUM] = {6,0,4,0,5,0,0,0,0};
    int zone24[MAX_NUM] = {4,0,0,0,0,0,7,0,0};
    int zone25[MAX_NUM] = {0,0,0,1,0,9,0,0,0};
    int zone26[MAX_NUM] = {0,0,9,0,0,0,0,0,6};
    int zone27[MAX_NUM] = {0,0,0,0,8,0,1,0,3};
    int zone28[MAX_NUM] = {0,2,0,5,0,7,0,0,0};
    int zone29[MAX_NUM] = {0,0,0,0,6,0,7,0,2};
    
    sudoku2[0] = zone21;
    sudoku2[1] = zone22;
    sudoku2[2] = zone23;
    sudoku2[3] = zone24;
    sudoku2[4] = zone25;
    sudoku2[5] = zone26;
    sudoku2[6] = zone27;
    sudoku2[7] = zone28;
    sudoku2[8] = zone29;
    
//    ===========================================================================
//  Testing checkAvailable Numbers by Row
    
//    int temp1[MAX_NUM] ={0};
//    printSudoku(goodSudoku);
//    checkAvailableNumbersByColumn(temp1,goodSudoku,8);
//    printLine(temp1);
    
// Testing available numbers of a sudoku:
    
//    printAvailableNumbers(sudoku, 0);
//    printf("\nthe selected number is: %d", pickAvailableNumber(sudoku, 0));
    
    
// Testing has unique Numbers
//    int test[MAX_NUM] = {0, 0, 3, 4, 5, 6, 7, 8, 9};
//    printf("the test has unique values: %s", hasUniqueNumbers(test)?"TRUE":"FALSE");
    
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
    
//    printf("Is a correct Sudoku ? %s",correctSudoku(sudoku)?"YES":"NO");
    
// ==========================================================
    
//    createSudoku(newSudoku);
    
//    printSudoku(unsolvedSudoku);
//    
//    int line[MAX_NUM] = {0};
//    checkAvailableNumbers(line, unsolvedSudoku,0,0);
    
//    ==========================================================
    printSudoku(intermediateSudoku);
    solveSudoku(intermediateSudoku);
    printSudoku(intermediateSudoku);

//    int*** grid = createGrid();
//    printf("Grid created.");
//    populateGrid(grid, intermediateSudoku);
//    printLine(grid[5][0]);
//    getRowFromGrid(grid,0);
    return (0);
}




