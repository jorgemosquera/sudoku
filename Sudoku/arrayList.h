/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrayList.h
 * Author: j_a_m
 *
 * Created on March 13, 2020, 9:30 PM
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct node {
    int value;
    struct node *next;
} numbers_t;

// declares a variable
//extern int var1;

// declares a function
numbers_t* createList();
numbers_t* createNode(int number);
void appendNumber(numbers_t** head, int number);
void displayList(numbers_t* head);
int length(numbers_t* head);
int getValue(numbers_t* head, int index);
void removeFirst(numbers_t** head);
void removeLast(numbers_t** head);
void removeByIndex(numbers_t** head, int index);
void removeByValue(numbers_t** head, int value);
int pickNumberFromList(numbers_t** head);



#endif

