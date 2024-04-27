/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 6/12/22
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum STATUS {overcapacity, operational, closed};
char warehouses[5];

struct warehouse {
    char city[20];
    int capacity;
    char status[20];
};

int main() {
    printf("Hello World\n");
}