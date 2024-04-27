/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 24/1/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

int main() {
    printf("\nPart 1\n\n");
    //Pointing to file and openning file as read.
    FILE *fptr = fopen("/Users/oisinmcl/Downloads/SampleData.txt", "r");

    char c = fgetc(fptr);
    //To check if file point and directory is correct using if and else statements.
    if (fptr == NULL){
        puts("Error Opening File \n Exiting ........"); 
    }
    else {
        printf("Everything works fine.\n\n"); 
        //While not end of file, print all characters in file.
        while (c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
    }
    //Closing file, end of first part.
    fclose(fptr);
    printf("-------------------------------------------------------------------------------\n");

    printf("\n\nPart 2\n\n");
    //Openning file again as read.
    fopen("/Users/oisinmcl/Downloads/SampleData.txt", "r");
    //Skipping first line of txt file which contains no data being used.
    char line[101];
    fgets(line, 101, fptr);

    //Initialising all varaibles.
    int day;
    int month;
    int year;
    char region[80];
    char rep[80];
    char item[80];
    float units;
    float unitcost;
    float total;
    float totalorder;
    float avgorder;
    int counter = 0;

    //While not equal to end of file, scan each date in and everything seperated by a tab and add to variable.
    while (!feof(fptr)) {
        fscanf(fptr, "%d/", &day);
        fscanf(fptr, "%d/", &month);
        fscanf(fptr, "%d\t", &year);
        fscanf(fptr, "%s\t", region);
        fscanf(fptr, "%s\t", rep);
        fscanf(fptr, "%s\t", item);
        fscanf(fptr, "%f\t", &units);
        fscanf(fptr, "%f\t", &unitcost);
        fscanf(fptr, "%f\n", &total);

    //Print each variable out.
        printf("Date: %d/%d/%d\t", day, month, year);
        printf("Region: %s\t", region);
        printf("Rep: %s\t", rep);
        printf("Item: %s\t", item);
        printf("Units: %f\t", units);
        printf("Unit Cost: %f\t", unitcost);
        printf("Total: %f\t\n", total);

    //Calculating total income and incrementing counter for average.
        totalorder += total;
        counter++;
    }
    //Calculating average order and printing total income and average order value.
    avgorder = (totalorder / counter);
    printf("\nTotal income from all orders: €%f\n", totalorder);
    printf("Average order value: €%f\n", avgorder);

    //Closing file again, end of part 2.
    fclose(fptr);
    printf("-------------------------------------------------------------------------------\n");

    printf("\n\nPart 3\n\n");
    //Openning file again but as append this time.
    fopen("/Users/oisinmcl/Downloads/SampleData.txt", "a");

    //Calculating unit cost for data to append
    float Punitcost = (19.99*06);
    //Appending data to end of file (has updated on my computer's file).
    fprintf(fptr, "24/1/23\t Galway\t Mc Laughlin\t Pen\t 06\t 19.99\t %f\n", Punitcost);
    //Printing data successfully added and closing file.
    printf("Data successfully added to file.\n\n");

    fclose(fptr);
}
//Thank you.