/* 
 * File:   main.c
 * Author: j_a_m
 *
 * Created on February 2, 2020, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 9

void printSudoku(int *sudoku[]);

/*
 * 
 */
int main() {
    
    int numbers[MAX_NUM];
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
    
    int zone1[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone2[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone3[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone4[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone5[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone6[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone7[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone8[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int zone9[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int *sudoku[9];
    sudoku[0] = zone1;
    sudoku[1] = zone2;
    sudoku[2] = zone3;
    sudoku[3] = zone4;
    sudoku[4] = zone5;
    sudoku[5] = zone6;
    sudoku[6] = zone7;
    sudoku[7] = zone8;
    sudoku[8] = zone9;
    
    
    printSudoku(sudoku);

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