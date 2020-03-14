/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.h
 * Author: j_a_m
 *
 * Created on March 13, 2020, 6:53 PM
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// declares a variable
//extern int var1;

// declares a function
void printLine(int* line);
void printSudoku(int** sudoku);
void shuffle(int* zone);
int hasUniqueNumbers(int* ptr);
void getRow(int* rowResult, int** sudoku, int rowNumber);
void getColumn(int* columnResult, int** sudoku, int columnNumber);

void shuffleSudoku(int** sudoku);
void createSudoku(int** sudoku);
void createSudoku2(int** sudoku);
int correctSudoku(int** sudoku);
void checkAvailableNumbersByZone(int* line, int** sudoku, int zone);
int quantityNumbersAvailable(int* line);
void printAvailableNumbers(int** sudoku, int zone);
int pickAvailableNumber(int** sudoku, int zone);
void checkAvailableNumbersByRow(int* line, int** sudoku, int row);
void checkAvailableNumbersByColumn(int* line, int** sudoku, int column);
void checkAvailableNumbers(int* line, int** sudoku, int rowNumber, int columnNumber);

#endif
