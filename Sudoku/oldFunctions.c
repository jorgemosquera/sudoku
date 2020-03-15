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

void createFirstRow(int** sudoku){
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
//        printSudoku(sudoku);
    }
}

void createSecondRow(int** sudoku, int rowNumber){
//    createFirstZone(sudoku);
//    createSecondZone(sudoku);
//    createThirdZone(sudoku);
    while(createByZone(sudoku, rowNumber)){
        clearRow(sudoku, rowNumber);
    }
}

void createFirstZone(int** sudoku){
    printf("\nBeginning First Zone.");
    int zone;
    int index;
    int row = 0;
    int column = 0;
    
    //create secondRow row = 1
    //take zone 2 numbers
    
    numbers_t* zoneNumbers = createList();
    for(int i = 0; i < MAX_NUM/3 ; i++){
        appendNumber(&zoneNumbers,sudoku[2][i]);
    }
    displayList(zoneNumbers);
    
    // get row 2 empty slots
    int row2[MAX_NUM];
    getRow(row2, sudoku, 1);
    printf("\nThe values of the line are:");
    printLine(row2);

    numbers_t* emptySlots = createList();
    
    int counter = 0;
    int i = 0;
    while(counter < 6){
        if(row2[i]==0){
            appendNumber(&emptySlots, i);
        }
        i++;
        counter++; 
    }
    printf("\nThe empty slots are:");
    displayList(emptySlots);

    int randomSlot = 0;
    
    while(length(zoneNumbers)){
        //pick a random slot from zone1Numbers
        randomSlot = rand()%(length(emptySlots));
        printf("\nThe random Slot selected is %d", randomSlot);
        row = 1;
        column = getValue(emptySlots, randomSlot);
        printf("\nThe value selected is %d", column);
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        int selectedValue = 0;
        do {
            selectedValue = pickNumberFromList(&zoneNumbers);
            sudoku[zone][index] = selectedValue;
        } while (!correctSudoku(sudoku));
        
        removeByValue(&zoneNumbers, selectedValue);
        displayList(zoneNumbers);
        removeByIndex(&emptySlots, randomSlot);
        displayList(emptySlots);
        printSudoku(sudoku);
    }
}

void createSecondZone(int** sudoku){
    printf("\nBeginning Second Zone.");
    int zone;
    int index;
    int row = 0;
    int column = 0;
    
    //take zone 1 numbers
    numbers_t* zone1Numbers = createList();
    for (int i = 0; i < MAX_NUM / 3; i++) {
        appendNumber(&zone1Numbers, sudoku[1][i]);
    }
    printf("\nZone 1 numbers are:");
    displayList(zone1Numbers);
    
    // get row 2 empty slots
    int row2[MAX_NUM];
    getRow(row2, sudoku, 1);
    printf("\nThe values of the line are:");
    printLine(row2);
    
    numbers_t* emptySlots = createList();
    
    int counter = 0;
    int i = 0;
    while(counter < 6){
        if(row2[i]==0){
            appendNumber(&emptySlots, i);
                               
        }
        if(i==2){
            i = 6;
        }
        else {
            i++;
        }
        counter++; 
    }
    printf("\nThe empty slots are:");
    displayList(emptySlots);
    
    int randomSlot = 0;
    
    while(length(zone1Numbers)){
        //pick a random slot from zone1Numbers
        randomSlot = rand()%(length(emptySlots));
        printf("\nThe random Slot selected is %d", randomSlot);
        row = 1;
        column = getValue(emptySlots, randomSlot);
        printf("\nThe value selected is %d", column);
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        int selectedValue = 0;
        do {
            selectedValue = pickNumberFromList(&zone1Numbers);
            sudoku[zone][index] = selectedValue;
        } while (!correctSudoku(sudoku));
        
        removeByValue(&zone1Numbers, selectedValue);
        displayList(zone1Numbers);
        removeByIndex(&emptySlots, randomSlot);
        displayList(emptySlots);
        printSudoku(sudoku);
    }
}

void createThirdZone(int** sudoku){
    
    printf("\nBeginning Third Zone.");
    int zone;
    int index;
    int row = 0;
    int column = 0;
    
    //take zone 0 numbers
    numbers_t* zoneNumbers = createList();
    for (int i = 0; i < MAX_NUM / 3; i++) {
        appendNumber(&zoneNumbers, sudoku[0][i]);
    }
    
    printf("\nZone 0 numbers are:");
    displayList(zoneNumbers);
    
    // get row 1 empty slots
    int row2[MAX_NUM];
    getRow(row2, sudoku, 1);
    printf("\nThe values of the line are:");
    printLine(row2);
    
    numbers_t* emptySlots = createList();
    
    int counter = 0;
    int i = 3;
    while (counter < 6) {
        if (row2[i] == 0) {
            appendNumber(&emptySlots, i);
        }
        i++;
        counter++;
    }
    printf("\nThe empty slots are:");
    displayList(emptySlots);
    
    int randomSlot = 0;
    
    while(length(zoneNumbers)){
        //pick a random slot from zoneNumbers
        randomSlot = rand()%(length(emptySlots));
        printf("\nThe random Slot selected is %d", randomSlot);
        row = 1;
        column = getValue(emptySlots, randomSlot);
        printf("\nThe value selected is %d", column);
        zone = (row / 3)*3 + column / 3;
        index = (row % 3)*3 + column % 3;
        int selectedValue = 0;
        do {
            selectedValue = pickNumberFromList(&zoneNumbers);
            sudoku[zone][index] = selectedValue;
        } while (!correctSudoku(sudoku));
        
        removeByValue(&zoneNumbers, selectedValue);
        displayList(zoneNumbers);
        removeByIndex(&emptySlots, randomSlot);
        displayList(emptySlots);
        printSudoku(sudoku);
        
    }
}

int createByZone(int** sudoku, int rowNumber) {
    

    for (int x = 0; x < 3; x++) {

        int zone;
        int index;
        int columnNumber = 0;

        //take zone 1 numbers
        numbers_t* zoneNumbers = createList();
        for (int i = 0; i < MAX_NUM / 3; i++) {
            appendNumber(&zoneNumbers, sudoku[2 - x][i]);
        }
//        printf("\nZone %d contains the following numbers: ", x);
//        displayList(zoneNumbers);

        // get row 1 empty slots
        int row[MAX_NUM];
        getRow(row, sudoku, rowNumber);
//        printLine(row);
        numbers_t* emptySlots = createList();
        int counter = 0;
        int y = 0;
        if (x == 2) {
            y = 3;
        }
        while (counter < 6) {
            if (row[y] == 0) {
                appendNumber(&emptySlots, y);
            }
            if ((x == 1) && (y == 2)) {
                y = 6;
            } else {
                y++;
            }
            counter++;
        }
        
//        printf("\nThe empty slots for %d are: ", x);
//        displayList(emptySlots);

        int randomSlot = 0;

        while (length(zoneNumbers)) {
            if(length(emptySlots) == 0){
                return 1;
            }
            //pick a random slot from zone1Numbers
            randomSlot = rand() % (length(emptySlots));
//            printf("\nThe random Slot selected is %d", randomSlot);
            columnNumber = getValue(emptySlots, randomSlot);
//            printf("\nThe position of the random Slot is selected is %d", columnNumber);
            zone = (rowNumber / 3)*3 + columnNumber / 3;
            index = (rowNumber % 3)*3 + columnNumber % 3;
            int selectedValue = 0;
            int exitCounter = 0;
            do {
                if(exitCounter == 3){
                    return 1;
                }
                selectedValue = pickNumberFromList(&zoneNumbers);
//                printf("\nThe selected value is: %d", selectedValue);
                sudoku[zone][index] = selectedValue;
                
//                printf("\nexit counter %d", exitCounter);
                exitCounter++;
            } while (!correctSudoku(sudoku));

            removeByValue(&zoneNumbers, selectedValue);
//            displayList(zoneNumbers);
            removeByIndex(&emptySlots, randomSlot);
//            displayList(emptySlots);
//            printSudoku(sudoku);
        }

    }
    
    return 0;
}

void createSudoku1(int** sudoku){
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

