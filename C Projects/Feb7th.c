#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num = rand() % 101;
    int count = 0;
    int guess = 0;
    printf("\n\n\n************\n**** %d ****\n************\n\n\n", num);

    printf("\nNumber generated between 0 and 100\nBegin guessing...\n");

    while(guess != num) {
        printf("Guess: ");
        scanf("%d", &guess);
        
        printf("\nWrong Answer\n");
        if(guess > num) {
            printf("Try Lower!\n");
            }
        if(guess < num) {
            printf("Try Higher!\n");
            }
        count++;
        printf("\n");
        }
    printf("\nCongratulations\nYou guessed correctly in %d guesses\n\n", count);
}