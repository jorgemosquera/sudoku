#include "functions.h"
#include "arrayList.h"
#define MAX_NUM 9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void getRowFromGrid(int*** grid, int row){
    int line[MAX_NUM] = {0};
    int zone;
    int index;
    printLine(line);
    for(int column = 0; column< MAX_NUM; column++){
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        printLine(grid[zone][index]);
        for(int k = 0; k < MAX_NUM; k ++){
            line[k] = line[k] | grid[zone][index][k];
        }
        printLine(line);
    }
}

int*** createGrid() {
    int*** grid = (int***)malloc(MAX_NUM*sizeof(int*));
    if(grid == NULL){
        printf("Sorry, could not create grid");
        exit(-1);
    }
    for(int j = 0; j < MAX_NUM; j++) {
        grid[j] = (int**)malloc(MAX_NUM*sizeof(int*));
        if(grid[j] == NULL){
            printf("Sorry, could not create grid");
            exit(-1);
        }
        for(int i = 0 ; i < MAX_NUM; i++){
            grid[j][i] = (int*)calloc(MAX_NUM,sizeof(int));
            if(grid[j][i] == NULL){
                printf("Sorry, could not create grid");
                exit(-1);
        }
        }
    }    
    
    return grid;
}

void populateGrid(int*** grid, int** sudoku){
    for(int zone = 0 ; zone < MAX_NUM; zone++){
        for(int index = 0; index < MAX_NUM; index++) {
            int row = index/3 + (zone /3)*3;
            int column = index % 3 + (zone%3)*3;
            // If there is a Fixed number in the sudoku, create the grid for that slot.
            // remember that 0 is possible and 1 is not possible
            if(sudoku[zone][index] != 0){
                for(int k = 0; k < MAX_NUM; k++){
                    if(k != sudoku[zone][index] - 1){
                       grid[zone][index][k] = 1; 
                    } else {
                        grid[zone][index][k] = 0;
                    }
                }   
            } else {
                checkAvailableNumbers(grid[zone][index], sudoku, row, column);
            }
        }
    }
}