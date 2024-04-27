/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 25/10/22
*/

#include <stdio.h>

int main() {
    //Initializing Variables
    float daily[50];
    float total = 0;
    float avg = 0;
    int additional = 0;

    //For loop taking asking for inputs, and adding them to the array
    for (int i = 0; i < 7; i++) {
        printf("Enter the total sales for day: %d €", i+1);
        scanf("%f", &daily[i]);
        total = total + daily[i];
    }
    //Getting average and printing it as well as total
    avg = total / 7;
    printf("Total sales for the week is €%.2f\n", total);
    printf("Average daily sales is €%.2f\n", avg);

    //Asking how many additional days and adding it to variable
    printf("How many additional days would you like to record? ");
    scanf("%d", &additional);

    //Until additional amount of days is reached, asking for more inputs and adding onto array
    int j = 7;
    while (j<(additional+7)) {
        printf("Enter the total sales for the day: %d €", j+1);
        scanf("%f", &daily[j]);
        total = total + daily[j];
        j=j+1;
    }
    //Getting new average and printing new average along with new total
    avg = total / j;
    printf("Updated total sales is €%.2f\n", total);
    printf("Updated average sales is €%.2f\n", avg);

    //Printing each variable recorded in the array
    for (int k = 0; k < (additional+7); k++) {
        printf("Sales for day: %d €%.2f\n", k+1, daily[k]);
    }
}
//Thank you