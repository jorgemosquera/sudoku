/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arrayList.h"
#include <stdio.h>
#include <stdlib.h>



numbers_t* createList(){
    numbers_t* head = NULL;
    return head;
}

numbers_t* createNode(int number){
    numbers_t* record = (numbers_t*)malloc(sizeof(numbers_t));
    record->value = number;
    record->next = NULL;
    return record;
}

void appendNumber(numbers_t** head, int number){
    numbers_t* new_node = createNode(number);
    if(*head == NULL){
        *head = new_node;
    } 
    else {
        numbers_t* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}

void displayList(numbers_t* head){
    numbers_t* current = head;
    printf("\n");
    while(current != NULL){
        printf("%d ",current->value);
        current = current->next;
    }
}

int length(numbers_t* head){
    int length = 0;
    numbers_t* current = head;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

int pickNumberFromList(numbers_t** head){
    int lengthNumber = length(*head);
    int random = rand()%lengthNumber;
    return getValue(*head, random);
}

int getValue(numbers_t* head, int index){
    numbers_t* current = head;
    int counter = 0;
    while(counter < index){
        if(current == NULL){
            printf("\nIndex out of range.");
            exit(1);           
        } else {
            current = current->next;
            counter++;
        }
    }
    return current->value;
    
}

void removeFirst(numbers_t** head) {
    numbers_t* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeLast(numbers_t** head){
    numbers_t* current = *head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    numbers_t* temp = current->next;
    current->next = NULL;
    free(temp);
}

void removeByIndex(numbers_t** head, int index){
    numbers_t* current = *head;
    int counter = 0;
    if (index == 0){
        removeFirst(head);
    } else {
        while (counter < index-1){
            current = current->next;
            counter++;
        }
        numbers_t* temp = current->next;
        if(temp->next== NULL){
            current->next = NULL;
        } else {
            current->next = temp->next;
        }
        
        free(temp);
    }
}

void removeByValue(numbers_t** head, int value){
    numbers_t* current = *head;
    int counter = 0;
    if(current->value ==  value){
        removeFirst(head);
    } else {
        while(current->next->value != value){
            
           current = current->next;
                        
        }
        numbers_t* temp = current->next;
        if(temp->next== NULL){
            current->next = NULL;
        } else {
            current->next = temp->next;
        }
        
        free(temp);
    }
}






