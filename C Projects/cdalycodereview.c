// 17/01/2023 Ciaran Daly 21381943
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int shipX, shipY; //x,y co-ordinates of the ship

int x = 0; // x for grid search
int y = 0; // y for grid search

void randomSearch(int gridSize); //task 2 fn

void gridSearch(int gridSize, int tries); // task 3 fn

void main() {
    int gridSize = 3; // grid size set to the final digit in student ID
    shipX = rand() % gridSize; // random number for co-ordinates of the ship
    shipY = rand() % gridSize;
    puts("------- Random Search -------\n");
    randomSearch(gridSize);
    puts("------- Grid Search -------\n");
    gridSearch(gridSize, 0);
}


void randomSearch(int gridSize) { // random search
    int gridX;
    int gridY;
    int found = 0; // setting found to false
    int tries = 0;

    while (!found) {
        tries++; //count no. of tries
        gridX = rand() % gridSize;
        gridY = rand() % gridSize;


        if (gridX == shipX && gridY == shipY) {
            printf("Ship found after  %d locations \n", tries);
            found = 1; //setting found to true
            }
        }
    printf("Ship Coordinate: X = %d , Y = %d\n", gridX, gridY);
    }

    void gridSearch(int gridSize, int tries) { //grid search
        if (x == shipX && y == shipY) {
            printf("Ship found after  %d locations \n", tries);
            printf("Ship Coordinate: X = %d , Y = %d\n", x, y);
        }
        else {
            x = tries % gridSize; //search through grid, modulus for x, division for y
            y = tries / gridSize;
            gridSearch(gridSize, tries + 1);
        }
}