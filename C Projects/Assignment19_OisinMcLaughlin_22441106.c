/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 21/2/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

//Main structure.
typedef struct {
    char make[20];
    char model[20];
    int year;
} car;

//Declaring functions and car array.
car garage[10];
void readCars(char myfilePath[], int numCars);
void displayGarage(int numCars);
int checkYear(int numCars, int year);
       
int main() {
    //File pointer
    FILE* fptr;
    //Declaring file name
    char myfilePath[] = "/Users/oisinmcl/Downloads/carsYear.csv";
    //Calling each function with values as parameters.
    readCars(myfilePath, 10);
    displayGarage(10);
    //Initialising variable as calling function with their values
    int ans = checkYear(10, 2016);
    //Printing amount of cars with ans variable and 2016 as year.
    printf("\nThere are %d cars with year %d in the garage.\n\n", ans, 2016);
}

void readCars(char myfilePath[], int numCars) {
    //Openning file wit file path and pointing it to fptr.
    FILE *fptr= fopen(myfilePath, "r");
    //If file pointer doesn't exist, print unable to open.
    if (fptr == NULL) {
        printf("\nUnable to open file...\nClosing\n");
        }

    //Initialising variables.
    char line[101];
    int i = 0;
    
    //While not end of file pointer and i is less than number of cars.
    while (!feof(fptr) && i < numCars) {
        //Going through first line of file pointer.
        fgets(line, 101, fptr);
        //For the array full of cars.
        car c;
        //Creating variable token to parse values seperated by a comma.
        char* token = strtok(line, ",");
        //Copy string make from first value up to the comma.
        strcpy(c.make, token);
        
        //Delcaring token again for the model.
        token = strtok(NULL, ",");
        //Copy string model from first value up to the comma.
        strcpy(c.model, token);
        
        //Declaring token again for the year.
        token = strtok(NULL, ",");
        //Changing string to int and adding value in of year.
        c.year = atoi(token);
        //Garage at position i is equal to c for adding it to the new array.
        garage[i] = c;

        //Incriment i by 1.
        i++;
    }
    //Close file.
    fclose(fptr);
}

void displayGarage(int numCars) {
    //Print title.
    printf("\n----Cars In Garage----\n");

    //While i is less than num cars, incriment i.
    for(int i = 0; i < numCars; i++) {
        //Printing each car number, make, model and year.
        printf("\nCar: %d \nMake: %s \nModel: %s \nYear: %d\n", (i+1), garage[i].make, garage[i].model, garage[i].year);
    }
    //New line
    printf("\n");
}

int checkYear(int numCars, int year) {
    int count = 0;
    //While i is less than num cars, incriment i.
    for (int i = 0; i < numCars; i++) {
        //If year of garage at posotion i is equal to year parameter, add 1 to count.
        if (garage[i].year == year) {
            count++;
        }
    }
    //Return count.
    return count;
}
//Lab tudor changed my csv file to have make and model to be in their own column.
//Thank You.