/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 7/2/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>
//Size for each array.
#define size 6

//Initialising each function and creating an array for each one or variable if needed,
//as well as changing the pointer to point to the each variable or array and not the address of it.
void printDoubleArray(double* dp, int len);
double array1[size] = {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
double* dp = array1;

void swapIntegerValues(int* i1, int* i2);
int x = 3;
int y = 5;

void squareIntArray(int* i1, int len);
int array2[size] = {2, 4, 6, 8, 10, 12};
int* iarray = array2;

void printIntegerArrayBackwards(int* arr, int len);
int array3[size] = {3, 6, 9, 12, 15, 18};
int* barray = array3;

void randomIntArray(int* arr, int len, int max);
int array4[size] = {4, 8, 12, 16, 20, 24};
int* rarray = array4;

int main() {
    printf("\n");
    //Calling printDoubleArray with dp variable and 6 as size.
    printDoubleArray(dp, size);

    //Initialising i1 and i2 and pointing it to the address of x and y variables.
    int* i1 = &x;
    int* i2 = &y;
    //Calling swapIntegerValues function with i1 and i2 as parameters.
    swapIntegerValues(i1, i2);

    //Calling squareIntArray function with iarray and size as parameters.
    squareIntArray(iarray, size);

    //Calling printIntegerArrayBackwards function with barray and size as parameters.
    printIntegerArrayBackwards(barray, size);

    //Calling randomIntArray function with rarray, size and 20 as parameters.
    randomIntArray(rarray, size, 20);

    //Skipping line to make output look cleaner.
    printf("\n\n");
}

void printDoubleArray(double* dp, int len) {
    //Printing title of function.
    printf("\n1. Double Array\n");
    //For loop that will print out each value at position i in dp array to 2 decimal places,
    //while i is less than length, then increasing value of i by 1.
    for (int i=0; i < len; i++) {
        printf("%.2lf\t", dp[i]);
    }
    //Skipping line to make output look cleaner.
    printf("\n");
}

void swapIntegerValues(int* i1, int* i2) {
    //Storing values to use to swap.
    int* v1 = i1;
    int* v2 = i2;

    //Printing title of function.
    printf("\n2. Integer Swap\n");
    //Changing pointer and printing the i1 and i2 values.
    printf("First Int: %d\tSecond Int: %d\n", *i1, *i2);
    //Swapping values of i1 to i2's value and vice versa.
    i1 = v2;
    i2 = v1;
    //Changing pointer and printing i1 and i2 values.
    printf("First Int: %d\tSecond Int: %d\n", *i1, *i2);
}

void squareIntArray(int* i1, int len) {
    //Printing title of function.
    printf("\n3. Square Values\n");
    //Variable to store squared values.
    int square;

    //For loop to square each value at position i starting at 0 while i is less than length,
    //as well as printing at position i then increasing value of i by 1.
    for (int i=0; i < len; i++) {
        square = (i1[i] * i1[i]);
        printf("%d\t", square);
    }
    //Skipping line to make output look cleaner.
    printf("\n");
}

void printIntegerArrayBackwards(int* arr, int len) {
    //Printing title of function.
    printf("\n4. Backwards Array\n");
    //For loop that sets i to 1 less than length, while i is greater than -1, print position i of array,
    //then decrease value of i by 1.
    for (int i=(len-1); i > -1; i--) {
        printf("%d\t", arr[i]);
    }
    //Skipping line to make output look cleaner.
    printf("\n");
}

void randomIntArray(int* arr, int len, int max) {
    //Printing title of function.
    printf("\n5. Random Array\n");
    //To create random values each time code is run.
    long lt = time(NULL);
    srand(lt);
    //For loop that sets i to 0, while i is less than length, position i of array is equal to,
    //a number between max value and 0, print each value and increase i by 1.
    for (int i=0; i < len; i++) {
        arr[i] = (rand() % max);
        printf("%d\t", arr[i]);
    }
    //Skipping line to make output look cleaner.
    printf("\n");
}
//Thank you.