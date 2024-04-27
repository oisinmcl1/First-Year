/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 29/11/22
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialising Functions and Variables.
int setPasscode(int n);
int randpass = 0;
void randomPasscodeSearch(int passcode, int maxpasscode);
int orderedPasscodeSearch(int passcode, int maxpasscode);

int main() {
    /*
    Generating passcode by calling setPasscode function with the max number that was asked.
    Printing the generated passcode.
    Calling randomPasscodeSearch function with passcode generated and the max number.
    Calling orderedPasscodeSearch function with passcode generated and the max number.
    Repeating for each number asked including last 3 digits of student number.
    */
    int passcode1 = 0;
    passcode1 = setPasscode(9);
    printf("\n");
    printf("Max passcode size: %d\n", 9);
    printf("Password: %d\n", passcode1);
    randomPasscodeSearch(passcode1, 9);
    orderedPasscodeSearch(passcode1, 9);
    printf("\n");

    int passcode2 = 0;
    passcode2 = setPasscode(99);
    printf("Max passcode size: %d\n", 99);
    printf("Password: %d\n", passcode2);
    randomPasscodeSearch(passcode2, 99);
    orderedPasscodeSearch(passcode2, 99);
    printf("\n");

    int passcode3 = 0;
    passcode3 = setPasscode(999);
    printf("Max passcode size: %d\n", 999);
    printf("Password: %d\n", passcode3);
    randomPasscodeSearch(passcode3, 999);
    orderedPasscodeSearch(passcode3, 999);
    printf("\n");

    int passcode4 = 0;
    passcode4 = setPasscode(9999);
    printf("Max passcode size: %d\n", 9999);
    printf("Password: %d\n", passcode4);
    randomPasscodeSearch(passcode4, 9999);
    orderedPasscodeSearch(passcode4, 9999);
    printf("\n");

    int studentno = 116;
    printf("Max passcode size: %d\n", 999);
    printf("Password: %d\n", studentno);
    randomPasscodeSearch(studentno, 999);
    orderedPasscodeSearch(studentno, 999);
    printf("\n");
}

int setPasscode(int n) {
    //Generating random number between 0 and n and returning it.
    long lt = time(NULL);
    srand(lt);
    randpass = (rand() % n);
    return randpass;
}

void randomPasscodeSearch(int passcode, int maxpasscode) {
    //Initialising variables.
    int i = 0;
    int passguess = -1;
    //While guessed password (random number generated between 0 and max number), add 1 to i for attempts, repeat.
    while (!(passguess == passcode)) {
        i++;
        passguess = (rand() % maxpasscode);
    }
    //Printing out guessed password and attempts
    printf("Password found from random: %d\n", passguess);
    printf("Found after %d random attempts\n", i+1);
}

int orderedPasscodeSearch(int passcode, int maxpasscode) {
    int i = 0;
    //While i is less than or equal to max number, if i is equal to passcode, stop the loop and print, otherwise add 1 to i, repeat.
    while (i <= maxpasscode) {
        if (i == passcode) {
            break;
        }
        else {
            i++;
        }
    }
    //Printing out guessed password and attempts.
    printf("Password found from ordered: %d\n", i);
    printf("Found after %d ordered attempts\n", i+1);
}
//Thank you.