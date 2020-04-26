/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gridFunctions.h
 * Author: j_a_m
 *
 * Created on April 25, 2020, 10:13 PM
 */

#ifndef GRIDFUNCTIONS_H
#define GRIDFUNCTIONS_H

int*** createGrid();
void populateGrid(int*** grid, int** sudoku);
void getRowFromGrid(int*** grid, int row);

#endif /* GRIDFUNCTIONS_H */

