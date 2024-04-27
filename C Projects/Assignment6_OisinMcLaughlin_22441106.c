/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 1/11/22
*/

#include <stdio.h>

int main() {

    int ratings[21];
    float average = 0;
    int total = 0;
    int ratingfrequency[5] = {0,0,0,0,0};
    float onesp = 0;
    float twosp = 0;
    float threesp = 0;
    float foursp = 0;
    float fivesp = 0;

    for (int i = 0; i < 21; i++) {
        printf("Enter the rating of movie: %d : ", i+1);
        scanf("%d", &ratings[i]);
        if (ratings[i] == 1) {
            ratingfrequency[0] += 1;
        }
        else if (ratings[i] == 2) {
            ratingfrequency[1] += 1;
        }
        else if (ratings[i] == 3) {
            ratingfrequency[2] += 1;
        }
        else if (ratings[i] == 4) {
            ratingfrequency[3] += 1;
        }
        else if (ratings[i] == 5) {
            ratingfrequency[4] += 1;
        }
        total = total + ratings[i];
    }
    average = total / 21;
    printf("Average rating is %.1f\n", average);
    
    printf("Rating Frequency:\n");
    for (int j = 0; j < 5; j++) {
        //printf("%d Star: %d\n", (j+1), ratingfrequency[j]);
        printf("%d Star: ", (j+1));
        for (int h = 0; h < ratingfrequency[j]; h++) {
            printf("*");
        }
        printf(" %d\n", ratingfrequency[j]);
    }
    
    printf("Rating Percent:\n");
    onesp = (((float)ratingfrequency[0] / 21)*100);
    printf("One Star Percent: %.2f%%\n", onesp);
    twosp = (((float)ratingfrequency[1] / 21)*100);
    printf("Two Stars Percent: %.2f%%\n", twosp);
    threesp = (((float)ratingfrequency[2] / 21)*100);
    printf("Three Stars Percent: %.2f%%\n", threesp);
    foursp = (((float)ratingfrequency[3] / 21)*100);
    printf("Four Stars Percent: %.2f%%\n", foursp);
    fivesp = (((float)ratingfrequency[4] / 21)*100);
    printf("Five Star Percent: %.2f%%\n", fivesp);
}
//I got permission from Karl Mason to resubmit this project before Friday the 11th of November due to a doctors note.