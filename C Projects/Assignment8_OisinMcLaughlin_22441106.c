/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 8/11/22
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    //Initialising car manufacturers variable.
    char manufacturers[5][50];

    //Printing asking user to enter manufacturers.
    printf("Enter car manufacturers:\n");
    //Loop to add each car manufacturer to the manufacturers array between 1 and 5 (0-4).
    for (int i = 0; i < 5; i++) {
        printf("\n%d: ", i+1);
        scanf("%s", &manufacturers[i]);
    }
    
    //First loop to go through each manufacturer in the array assigning it to k and getting the length of them.
    for (int k = 0; k < 5; k++) {
        int len = strlen(manufacturers[k]);
        //Second loop to go through each letter of the manufacturer, if letter is uppercase, print the letter.
        for (int p = 0; p < len; p++){
            if (isupper((manufacturers[k][p]))) {
                printf("Upper Case: %c\n", manufacturers[k][p]);
        }       
                //Setting each letter to uppercase at end of the loop.
                manufacturers[k][p] = toupper(manufacturers[k][p]); 
        } 
    }

    //Printing final list.
    printf("Final List:\n");
    //Printing each manufacturer in manufacturers array now already set to uppercase.
    for (int j = 0; j < 5; j++) {
        puts(manufacturers[j]);
    }
}
//Thank you