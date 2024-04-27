/*
Oisin Mc Laughlin
22441106
14/3/23
*/

#include <stdio.h>
#include <stdlib.h>

int is_leap(int year);
int new_years_day(int year);
int no_of_days(int year, int month);
int first_day(int year, int month);
void print_month(int firstday, int noofdays);

int main(int argc, char *argv[]) {
	// the user should supply 3 arguments:
	// 1: year number
	// 2: start month number
	// 3: end month number
}

int is_leap(int year) {
	if (year % 400 == 0)
		return 1;
	if (year % 100 == 0)
		return 0;
	if (year % 4 == 0)
		return 1;
	return 0;
}

int new_years_day(int year) {
	// return day of the week (0-6, where Sun=0) that new year's day falls on for the given year
}

int no_of_days(int year, int month) {
	// return number of days in the given month in the given year
}

int first_day(int year, int month) {
	// return day of the week (0-6) that the 1st of the given month falls on, in the given year
}

void print_month(int firstday, int noofdays) {
	printf("\n Sun Mon Tue Wed Thu Fri Sat\n");
	// print out a calendar given the day of the week (0-6)of its firstday
	// and the no of days in total
}