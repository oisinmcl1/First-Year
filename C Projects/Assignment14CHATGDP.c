#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shipX, shipY;

void randomSearch(int gridSize) {
    int x, y, numTries = 0;
    srand(time(NULL));
    do {
        x = rand() % gridSize;
        y = rand() % gridSize;
        numTries++;
    } while (x != shipX || y != shipY);
    printf("Found ship at location (%d, %d) after %d tries.\n", x, y, numTries);
}

void gridSearch(int gridSize, int numTries) {
    if (numTries >= gridSize * gridSize) {
        printf("Ship not found.\n");
        return;
    }
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            if (x == shipX && y == shipY) {
                printf("Found ship at location (%d, %d) after %d tries.\n", x, y, numTries);
                return;
            }
            numTries++;
        }
    }
    gridSearch(gridSize, numTries);
}

int main() {
    srand(time(NULL));
    shipX = rand() % 12;
    shipY = rand() % 12;
    randomSearch(12);
    gridSearch(12, 0);
    return 0;
}
