/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 31/1/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

int main() {
    //Pointing to file and openning dogs.txt file as read.
    FILE *fptr = fopen("/Users/oisinmcl/Downloads/dogs.txt", "r");

    //If file pointer is not equal to null:
    if (fptr != NULL) {
        //Seek to end of file.
        fseek(fptr, 0, SEEK_END);
        //Initialise variable with size of file.
        int len = ftell(fptr);
        //Print file size.
        printf("\nSize of dog.txt: %d bytes.\n\n\n", len);
    }
    //Otherwise, file hasn't openned sucessfully.
    else {
        printf("\nError Opening File\nExiting ........\n");
    }
    //Close file.
    fclose(fptr);

    //Open file dogs.txt file as read and write.
    fopen("/Users/oisinmcl/Downloads/dogs.txt", "r+");
    //Seek end and go back 3 characters to replace "pug".
    fseek(fptr, -3, SEEK_END);
    //Place "Boxer" text at this location.
    fputs("Boxer", fptr);
    //Printing saying file updated.
    printf("Dogs.txt updated.\n\n\n");
    //Close file.
    fclose(fptr);

    //New file pointer to point to countries.txt.
    FILE *fptrtwo = fopen("/Users/oisinmcl/Downloads/countries.txt", "r");
    //Initialise variables.
    char country[50];
    int population;
    int i = 0;
    int j = 0;
    char line[101];

    //While not end of file:
    while (!feof(fptrtwo)) {
        //Get line length.
        fgets(line, 101, fptrtwo);
        //While the line is not equal to a tab.   
        while (line[i] != '\t') {
            //Update country with that line.
            country[j] = line[i];
            //Increase i and j.
            i++;
            j++;
        }
        //Add end of string character to country.
        country[j] = '\0';
        //Increase i again to go to next line.
        i++;
        //Set j back to 0 to go through each character again.
        j = 0;
        //After the tab, set population equal to the int of the characters.
        population = atoi(&line[i]);

        //Print out each countrt and population.
        printf("Country: %s\t\n", country);
        printf("Population: %i\t\n\n", population);
        //Set i and j to 0 again and repeat.
        i = 0;
        j = 0;
    }
    //Close file.
    fclose(fptrtwo);

    //Open file as append.
    fopen("/Users/oisinmcl/Downloads/countries.txt", "a");

    //Add Oman and it's population to the end of file.
    fprintf(fptrtwo, "Oman\t 4520000000");
    //Print countries updated.
    printf("\nCountries.txt updated.\n\n");
    //Close file.
    fclose(fptrtwo);
}
//Thank you.