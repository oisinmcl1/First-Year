/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 22/11/22
*/

#include <stdio.h>
#include <math.h>

//Initialising the functions and variables.
float volume(float length, float width, float height);
float poolvolume = 0;
void mass(float poolvolume);
int barrels(float poolvolume);
int amtbarrels = 0;

int main() {
    //Setting poolvolume variable to call volume function with last 3 digits of student number and printing.
    poolvolume = volume(1, 1, 6);
    printf("Volume of pool is %0.2f\n", poolvolume);
    //Setting amtbarrels variable to call barrels function with poolvolume as parameter and printing.
    amtbarrels = barrels(poolvolume);
    printf("Barrels required is %d\n", amtbarrels);
    //Calling mass function with poolvolume variable as parameter.
    mass(poolvolume);
}

//Volume function with 3 parameters, multiplies the 3 parameters and returns the value.
float volume(float length, float width, float height) {
    float volume = (length * width * height);
    return volume;
}

//Mass function with poolvolume as parameter, takes parameter and multiplies by 1000 then prints it.
void mass(float poolvolume) {
    float poolmass = (poolvolume * 1000);
    printf("Mass of pool is %0.2f\n", poolmass);
}

//Barrels function with pool volume parameter, takes parameter by divides by 0.48 then rounds up, returns value.
int barrels(float poolvolume) {
    int barrels = ceil((poolvolume / 0.48));
    return barrels;
}
//Thank you.