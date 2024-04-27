/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 17/1/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

//Initialising global variables.
int shipX;
int shipY;
int gridsize = 6;

//Initialising functions.
void randomSearch(int gsize);
void gridSearch(int gsize, int ltries);

int main() {
    //Randomising ships x and y between 0 and 5.
    long lt = time(NULL);
    srand(lt);
    shipX = (rand() % 6);
    shipY = (rand() % 6);
    
    //Printing ships locations.
    printf("\n");
    printf("Ship X Location: %d\n", shipX);
    printf("Ship Y Location: %d\n", shipY);
    printf("(%d, %d)\n", shipX, shipY);

    //Calling Random Search and Grid Search functions with their parameters.
    printf("\n");
    printf("Random Search\n");
    randomSearch(gridsize);
    printf("\n");
    printf("Grid Search\n");
    gridSearch(gridsize, 0);
    printf("\n");
    return 0;
}

void randomSearch(int gsize) {
    //Initialising i as well as random x and y variables as -1.
    int i = 0;
    int randX = -1;
    int randY = -1;

    //While random x location or random y location (random number generated between 0 and 5), add 1 to i for attempts, repeat.
    while ((!(randX == shipX)) || (!(randY == shipY))) {
        i++;
        randX = (rand() % (gsize-1));
        randY = (rand() % (gsize-1));
    }

    //Once x and y are found, printing where it is as well as the amount of attempts it took.
    printf("Location found from random: (%d, %d)\n", randX, randY);
    printf("Found after %d random attempts\n", i+1);
}

void gridSearch(int gsize, int ltries) {
    //Initialising variables, x as location tries modulus grid size and y as location tries divided by grid size.
    int searchX = (ltries % gsize);
    int searchY = (ltries / gsize);

    //If searched x and searched y is the same as ship x and ship y, print location found and the amount of attempts.
    if ((searchX == shipX) && (searchY == shipY)) {
        printf("Location found from search: (%d, %d)\n", searchX, searchY);
        printf("Found after %d search attempts\n", ltries);
    }
    //Otherwise call function again with same grid size and tried locations + 1.
    else {
        gridSearch(gridsize, (ltries+1));
    }

    /*for (int searchX = 0; searchX < gsize; searchX++) {
        for (int searchY = 0; searchY < gsize; searchY++) {
            if (searchX == shipX && searchY == shipY) {
                printf("Found ship at location (%d, %d)\n", searchX, searchY);
                printf("Found after %d search attempts\n", ltries);
                return;
            }
            ltries++;
        }
    }
    gridSearch(gsize, ltries);*/
}