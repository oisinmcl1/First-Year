/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 18/10/22
*/

#include <stdio.h>

int main() {
    int children[999];
    int age = 1;
    int i = 0;
    int amtchildren = 0;
    float avgage = 0;
    int totalage = 0;
    int oldest = 0;
    int youngest = 1000;

    while (age>0) {
        printf("Please enter age of child %d: ", i+1);
        scanf("%d", &children[i]);
        age = children[i];
        

        if (age<0) {
            printf("Terminating Loop\n");
            break;
        }
        if (age >= 18) {
            printf("Age entered is not a child");
        }
        
        else{
            i++;
            amtchildren = amtchildren + 1;
            totalage = totalage + age;
            if (age > oldest) {
                oldest = age;
            }
            if (age < youngest) {
                youngest = age;
            }
}
    }
    printf("Total number of children is: %i\n", amtchildren);

    avgage = totalage / amtchildren;
    printf("Average age is: %0.1f\n", avgage);

    printf("Oldest child: %i\n", oldest);
    printf("Youngest child: %i\n", youngest);
}