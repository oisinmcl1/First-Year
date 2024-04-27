/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 14/2/23
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

//Define a date struct with day, month, and year fields.
typedef struct {
    int day, month, year;
} date;

//Define a customer struct with name, accountNumber, balance, and lastTrans fields.
typedef struct {
    char name[50];
    int accountNumber;
    double balance;
    date lastTrans;
} customer;

//Function with customer struct pointer to get customer name and store it in the given customer struct.
void getCustomerName(customer* cptr) {
    printf("Enter customer name: ");
    fgets(cptr->name, sizeof(cptr->name), stdin);  // Use fgets to read a string from stdin and store it in cptr->name.
    cptr->name[strcspn(cptr->name, "\n")] = '\0';  // Remove the newline character at the end of the string.
}

//Function with customer struct pointer to get account number and store it in the given customer struct.
void getAccountNumber(customer* cptr) {
    printf("Enter account number: ");
    scanf("%d", &cptr->accountNumber);  //Use scanf to read an integer from stdin and store it in cptr->accountNumber.
    getchar();  //Consume the newline character left in stdin by scanf.
}

//Function to get last transaction date and store it in the given customer struct.
void getLastTransDate(customer* cptr) {
    printf("Enter date of last transaction (dd mm yyyy): ");
    scanf("%d %d %d", &cptr->lastTrans.day, &cptr->lastTrans.month, &cptr->lastTrans.year);  //Use scanf to read three integers from stdin and store them in the fields of cptr->lastTrans.
    getchar();  //Consume the newline character left in stdin by scanf.
}

//Function with customer struct pointer to get account balance and store it in the given customer struct.
void getBalance(customer* cptr) {
    printf("Enter balance: ");
    scanf("%lf", &cptr->balance);  //Use scanf to read a double from stdin and store it in cptr->balance.
    getchar();  //Consume the newline character left in stdin by scanf.
}

//Function with customer struct pointer to print out the contents of the given customer struct in a formatted table.
void printCustomer(customer* cptr) {
    printf("%25s\t%13d\t%12.2lf\t%02d/%02d/%04d\n", cptr->name, cptr->accountNumber, cptr->balance, cptr->lastTrans.day, cptr->lastTrans.month, cptr->lastTrans.year);  // Use printf to format and print out the contents of the given customer struct
}

int main() {
    //Initialising variables and customers struct.
    int i;
    char temp[100];
    customer customers[3];  //Declare an array of 3 customer structs.

    //Loop over the array and prompt the user for input to fill in each customer struct.
    for (i = 0; i < 3; i++) {
        printf("Customer %d:\n", i+1);
        getCustomerName(&customers[i]);
        getAccountNumber(&customers[i]);
        getLastTransDate(&customers[i]);
        getBalance(&customers[i]);
        printf("\n");
    }

    //Print out a header row for the table.
    printf("\n\n%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");

    //Loop over the array and print out the contents of each customer struct in the table format.
   for (i = 0; i < 3; i++) {
        printCustomer(&customers[i]);
    }
}
//Thank you.