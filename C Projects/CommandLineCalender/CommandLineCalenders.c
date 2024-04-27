/*
Oisin Mc Laughlin
22441106
14/3/23
*/

#include <stdio.h>
#include <stdlib.h>

//Initialising functions.
int is_leap(int year);
int new_years_day(int year);
int no_of_days(int year, int month);
int first_day(int year, int month);
void print_month(int firstday, int noofdays);

int main(int argc, char *argv[]) {
    //Setting command line arguments as variables.
    int year = atoi(argv[1]);
    int startmonth = atoi(argv[2]);
    int endmonth = atoi(argv[3]);	
    
    //Printing command line arguments that was entered and returning.
    printf("\nYear entered: %d\nStart month entered: %d\nEnd month entered: %d\n", year, startmonth, endmonth);

    for (int i = startmonth; i <= endmonth; i++) {
        printf("\nYear: %d    Month: %d\n", year, i);
        print_month(first_day(year, i), no_of_days(year, i));
    }
}

int is_leap(int year) {
    //If year modulus 400 is equal to 0 return 1.
	if (year % 400 == 0)
		return 1;
	if (year % 100 == 0)
    //If year modulus 100 is equal to year return 0.
		return 0;
	if (year % 4 == 0)
    //If year modulus 4 is equal to 0 return 1.
		return 1;
    //return 0.
    return 0;
}

int new_years_day(int year) {
    int daynumber = 1;
    //i = 1900, while i is less than year, add 365 + 1 or 0 depending on what is_leap returns to daynumber.
    for (int i = 1900; i < year; i++) {
        daynumber += 365 + is_leap(i);
    }
    //Return daynumber modulus 7.
    return daynumber % 7;
}

int no_of_days(int year, int month) {
    //If month is equal to 9 or 4 or 6 or 11, return 30.
    if (month == 9 || month == 4 || month == 6 || month == 11) {
        return 30;
    }
    //If month is equal to 2, return 31.
	if (month != 2) {
        return 31;
    }
    //Return 28 + either 1 or 0 depending on what is_leap returns.
	return (28 + is_leap(year));
}

int first_day(int year, int month) {
    //Calculates day of week of 1st of any month after Jan 1900.
	int daynumber = new_years_day(year); // Day of week of Jan 1 this year.
    //Loop for each elapsed month this year
	for (int i = 1; i < month; i++) {
        daynumber += no_of_days(year, i); //Add days in each elapsed month.
    }
	return daynumber % 7;
}

void print_month(int firstday, int noofdays) {
	 //Print out the header row.
    printf("\n  Sun Mon Tue Wed Thu Fri Sat\n");
    
    //Print out the first row with blank spaces for days before the 1st of the month.
    for (int i = 0; i < firstday; i++) {
        printf("    ");
    }
    
    // Print out the days of the month
    for (int i = 1; i <= noofdays; i++) {
        // If the day is a single digit, add an extra space before it for formatting purposes
        if (i < 10) {
            printf(" ");
        }
        printf(" %d ", i);
        
        // If the current day is the last day of a week, start a new row
        if ((i + firstday) % 7 == 0) {
            printf("\n");
        }
    }
    
    // If the last day of the month is not a Saturday, add blank spaces to the last row
    if ((noofdays + firstday - 1) % 7 != 6) {
        for (int i = 0; i < 7 - (noofdays + firstday - 1) % 7; i++) {
            printf("    ");
        }
    }
    // Print a newline character at the end to separate the output from the next line
    printf("\n");
}
//Thank you.