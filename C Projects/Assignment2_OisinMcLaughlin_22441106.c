/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 4/10/22
*/

#include <stdio.h>

int main() {
    
    //Initiallising Variables
    int degF = 0;
    int degC = 0;
    
    //Requesting the users input in degrees Fahrenheit
    printf("Please enter your temperature in degrees Fahrenheit: ");
    
    //Taking the users input and assigning it to the degF variable
    scanf("%i", &degF);

    //Formula to change Fahrenheit to Celsius using input value and saving to degC variable
    degC = (degF - 32) * 5/9;

    //Printing converted temperture in degrees Celsius
    printf("Degrees Celsius = %i \n", degC);

    //Adding if and else statements to say "Too Hot" if temperature is over 32 degrees celsius
    //Adding another if statement to say "Too Cold" if temperature is under 0 degrees celsuius
    if (degC > 32) {
        printf("Too hot!\n");
    } else if (degC < 0) {
        printf("Too Cold!\n");
    }
}
//Thank you