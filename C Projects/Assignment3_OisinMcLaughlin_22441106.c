/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 11/10/22
*/

#include <stdio.h>

int main() {
    //Creating variables to store total sales of each week
    float w1 = 0;
    float w2 = 0;
    float w3 = 0;
    float w4 = 0;
    float w5 = 0;
    
    //User welcome message
    printf("Welcome to the shoe shop total weekly sales report\n");
    
    //Requesting the user to input each week's sales and adding them to each variable
    printf("Please enter the total weekly sales for Week 1: €");
    scanf("%f", &w1);
    printf("Please enter the total weekly sales for Week 2: €");
    scanf("%f", &w2);
    printf("Please enter the total weekly sales for Week 3: €");
    scanf("%f", &w3);
    printf("Please enter the total weekly sales for Week 4: €");
    scanf("%f", &w4);
    printf("Please enter the total weekly sales for Week 5: €");
    scanf("%f", &w5);
    
    //Calculating the average and printing it
    float average = ((w1 + w2 + w3 + w4 + w5) / 5);
    printf("Average weekly sales over 5 Weeks: €%f\n", average);
    
    //Checking sales to see if they're within certain ranges and telling user what we consider their sales
    if (average < 13000) {
        printf("Sales are low\n");
    } else if (average >= 13000 && average <= 20000){
        printf("Sales are normal\n");
    } else if (average > 20000){
        printf("Sales are high\n");
    }

    //Calculating the average spend per customer and printing it
    float customeravg = (average / (230));
    printf("Average spend per customer: €%f\n", customeravg);

    return 0;
}
//Thank you