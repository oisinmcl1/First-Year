/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 28/02/2023
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#define MAXSTRING 100

//Initialising variables and arrays.
char sizedwords[100000][MAXSTRING];
int numwords = 0;
void readDictionary();
void hangman();
int randnumber = 0;
int randomnumber();

int main() {
    //Pointing to file pointer and checking if directory is correct.
    FILE *fptr = fopen("/Users/oisinmcl/Downloads/dictionary.txt", "r");

     if (fptr == NULL){
        puts("\nError Opening File \n Exiting ........"); 
    }
    else {
        printf("\nFile opened successfully.\n\n"); 
    }
    fclose (fptr);
    //Calling hangman function.
    hangman();
}

void readDictionary() {
    //Openning file again and setting pointer.
    FILE *fptr = fopen("/Users/oisinmcl/Downloads/dictionary.txt", "r");
    
    char txt[MAXSTRING]; // string for reading each line into
    int lines = 0;
    while (fgets(txt, MAXSTRING-1, fptr)!=NULL) {
        lines++;
        txt[strlen(txt)-1] = '\0'; // remove the \n which has also been read into the string!
        // printf("%s\n", txt);
        
        //Adding words greater than 4 and less than 7 to new array sizedwords and counting words.
        int len = strlen(txt);
        if (len > 3 && len < 7) {
            strcpy(sizedwords[numwords], txt);
            numwords++;
        }
    }
    //Printing and closing file.
    printf("Dictionary.txt contained %d lines.\n", lines);

    printf("\nThere are %d suitable words in the Dictionary.txt\n\n", numwords);

    fclose (fptr);
}

int randomnumber() {
    //Generating random number between 0 and max number of words in sizedwords.
    srand(time(NULL));
    randnumber = rand() % numwords;
    return randnumber;
}

void hangman() {
    //Calling function to read words from dictionary and select suitable words to add to the array.
    readDictionary();

    //Initialising variables.
    int rnum = randomnumber();
    int len = strlen(sizedwords[rnum]);
    char guess;
    char targetword[len];
    //Copying a random word from sizedwords as the target word.
    strcpy(targetword, sizedwords[rnum]);
    // targetword = sizedwords[rnum];
    char dashes[len]; 
    int numguesses = 0;
    int remainingdashes = len;

    // printf("%s\n", targetword);
    for(int i = 0; i < len; i++) {
        dashes[i] = '-';
    }
    printf("%s\n", dashes);
    //Allows user to guess.

    while(remainingdashes > 0) {
        printf("\nGuess %d: ", numguesses + 1);
        scanf("%c", &guess);
        //Check if letter is in target.
        for(int i = 0; i < len; i++) {
            if(targetword[i] == guess && dashes[i] != targetword[i]) {
                dashes[i] = guess;
                remainingdashes--;
            }
        }
        numguesses++;
        printf("\n%s\n", dashes);
    }
    printf("\nCongratulations the word was:\n%s\nYou guessed correctly in %d guesses.\n\n", dashes, numguesses);
}