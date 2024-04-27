/*
Name: Oisin Mc Laughlin
Date: 26/4/23
Paper: CT103 Sem 2 21/22
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <time.h>
#include <math.h>

//Section A

// Question 2
// (a)
void convertTime(int mins);
// (b)
int arrayCheck(int nums[], int l);

// Question 4
// (b)
void checkIn(int room, int floor);
// (c)
void checkout();
// (d)
void nextDay();

//Section B

//Question 6
//(a)
int randnum();


int main() {
    // Section A

    // Question 1
    
    // (a)
    /*
    // int ans = 6;
    // for (int i = 3; i < 8; i++) {
    //     ans *= i;
    // }
    // printf("ans = %d.\n", ans);

    int ans = 6;
    int i = 3;

    while (i < 8) {
        ans *= i;
        i++;
    }
    printf("ans = %d.\n", ans);
    */

    // (b)
    /*
    float arrA[50] = {12.5, 13.6, 18.9, 14.7};

    for (int i = 0; i < 4; i++) {
        arrA[i] += 2;
        printf("Element %d: %0.2f\n", i+1, arrA[i]);
    }
    */

    // (c)
    /*
    int age = 0;
    
    do {
        printf("\nPlease enter age: ");
        scanf("%d", &age);

        if (age < 17) {
            printf("\nUser is too young to drive.\n");
        }
    }
    while (age < 17);

    printf("\nUser is old enough to drive.\n");
    */


    // Question 2

    // (a)
    // convertTime(12000);

    // (b)
    /*
    int nums[8] = {5, 7, 10, 13, 15, 20};
    int ans = arrayCheck(nums, 6);
    printf("\nDivisible by 5: %d\n", ans);
    */

    
    // Question 3

    // (b)
    /*
    float height = 152.4;
    float* fpt = &height;
    float grow = 5.2;

    *fpt += grow;
    printf("\nIncreased Height: %0.2f\n\n", *fpt);
    */

    // (c)
    /*
    int array[12];

    long lt = time(NULL);
    srand(lt);

    for (int i = 0; i < 10; i++) {
        array[i] = (rand() % 101 + 100);
    }

    int *ptr = array;

    for (int i = 0; i < 10; i++) {
        printf("Address of element %d: %p\n" ,i+1 , &array[i]);
        printf("Address of pointer %d: %x\n\n" ,i+1 , ptr);
        ptr++;
    }
    */


    // Question 4

    // (a)
    /*
    for (int i = 0; i < 3; i++) {
        checkIn(0, i);
    }
    for (int i = 0; i < 7; i++) {
        printf("\nDay %d.\n", i+1);
        checkOut();
        nextDay();
    }
    */


    // Question 5

    /*
    // (a)
    FILE* fptr = fopen("/Users/oisinmcl/Desktop/C Projects/CT103 Exams/sales.txt", "r");
    if (fptr == NULL) {
        printf("\nError: Could not open file\n");
    }
    char line[101];

    while (!feof(fptr)) {
        fgets(line, 101, fptr);
        puts(line);
    }
    fclose(fptr);

    // (b)
    fopen("/Users/oisinmcl/Desktop/C Projects/CT103 Exams/sales.txt", "a");
    if (fptr == NULL) {
        printf("\nError: Could not open file\n");
    }
    fputs("watches\t41\n", fptr);
    printf("\nSale of 41 Watches added to file.\n");
    fclose(fptr);

    //(c)
    fopen("/Users/oisinmcl/Desktop/C Projects/CT103 Exams/sales.txt", "r");
    if (fptr == NULL) {
        printf("\nError: Could not open file\n");
    }
    fseek(fptr, 0L, SEEK_END);
    printf("\nFile size: %ld bytes\n", ftell(fptr));
    fclose(fptr);
    */



    // Section B

    // Question 6

    // (b)
    int freq[13] = {0};

    for (int i = 0; i < 500; i++) {
        int dice1 = randnum();
        int dice2 = randnum();
        int sum = (dice1 + dice2);

        freq[sum]++;
    }

    printf("\nResults:\n\n");
    for (int i = 2; i <= 12; i++) {
        printf("\n%d :  ", i);
        for (int j = 0; j < freq[i]; j++) {
            printf("*");
        }
    }
    printf("\n\n");
}



// Q4 (b)
/*
typedef struct guest {
    char first_name[30];
    int max_nights;
    int nights_stayed;
    int checked_in;
} guest;

guest hotel[10][10];
*/


// Question 2

// (a)
/*
void convertTime(int mins) {
    int hours = 0;
    int days = 0;
    int weeks = 0;

    hours = floor(mins / 60);
    days = floor(hours / 24);
    weeks = floor(days / 7);

    printf("\nMinutes: %d\n\nHours: %d\nDays: %d\nWeeks: %d\n", mins, hours, days, weeks);
}
*/

// (b)
/*
int arrayCheck(int nums[], int l) {
    int count = 0;

    for (int i = 0; i < l; i++) {
        if ((nums[i] % 5) == 0) {
            count++;
        }
    }
    return count;
}
*/


// Question 4
// (b)
/*
void checkIn(int room, int floor) {
    char name[30];
    int nights = 0;

    printf("\nEnter first name: ");
    scanf("%s", &name);

    printf("\nEnter number of nights staying: ");
    scanf("%s", &nights);

    strcpy(hotel[floor][room].first_name, name);
    hotel[floor][room].max_nights = nights;
    hotel[floor][room].nights_stayed = 0;
    hotel[floor][room].checked_in = 1;

    printf("\nGuest %s checked into room %d on floor %d.\n", name, room, floor);
}

// (c)
void checkout() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((hotel[i][j].checked_in == 1) && (hotel[i][j].nights_stayed >= hotel[i][j].max_nights)) {
                hotel[i][j].checked_in = 0;
                printf("\nGuest %s checked out of room %d on floor %d.\n", hotel[i][j].first_name, j, i);
            }
        }
    }
}

// (d)
void nextDay() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (hotel[i][j].checked_in == 1) {
                printf("\nRoom %d on floor %d is occupied.\n", j, i);
                hotel[i][j].nights_stayed++;
            }
        }
    }
}
*/


// Section B

// Question 6

// (a)
int randnum() {
    long lt = time(NULL);
    srand(lt);

    int dice = ((rand() % 6) + 1);

    return (dice);
}

// help.