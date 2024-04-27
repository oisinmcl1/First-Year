/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 7/3/23
*/

#include <stdio.h>
#include <texting.h>
#include <stdlib.h>
#include <ctype.h>

char alltext[200000];
char oneline[1000];

//Initialising functions.
int wordcount(char *text);
int sentencount(char *text);
int syllcount(char *text);
int fleschcalc(int syll, int word, int senten);

int main() {
    int words, senten, syl = 0;

    //Two file pointers to swap between to calculate each fletch index of.
    FILE *fptr= fopen("/Users/oisinmcl/Downloads/article-green-eggs-and-ham.txt", "r");
    // FILE *fptr= fopen("/Users/oisinmcl/Downloads/article-irish-times.txt", "r");

    if (fptr == NULL){
        puts("\nError Opening File \n Exiting ........\n\n"); 
    }
    else {
        printf("\nFile opened successfully.\n\n"); 
    }

    alltext[0] = '\0'; // make sure this texting is empty
    
    while (fgets(oneline, 999, fptr)!=NULL) {
        // read the next line and append it (with \n intact)
        strcat(alltext, oneline);
    }
    // printf("\n%d\n", count);
    // printf("%s", alltext);

    //Calling all functions with parameters.
    wordcount(alltext);
    sentencount(alltext);
    syllcount(alltext);
    fleschcalc(syllcount, wordcount, sentencount);

    fclose(fptr);
    printf("\n\n");
}

int wordcount(char *text) {
    int wordcount = 0;

    //Anytime it hits a whitespace, incriment wordcount.
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            wordcount++;
        }
    }
    printf("\nWords: %d\n", wordcount+1);
    return(wordcount+1);
}

int sentencount(char *text) {
    int sentencount = 0;

    //Anytime it hits a '.' or '?' or '!', incriment sentencount.
    for(int i = 0; i < srelen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentencount++;
        }
    }
    printf("\nSentences: %d\n", sentencount);
    return(sentencount);
}

int syllcount(char *text) {
    int syllcount = 0;
    int length = strlen(text);
    int is_previous_vowel = 0;

    //Convert all to lower.
    for (int i = 0; i < length; i++) {
        char current_char = tolower(text[i]);

        //If all vowels and last character isn't a vowel, incriment syll count.
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u' || current_char == 'y') {
            if (!is_previous_vowel) {
                syllcount++;
                is_previous_vowel = 1;
            }
        } else {
            is_previous_vowel = 0;
        }
    }
    printf("\nSyllables: %d\n", syllcount);
    return syllcount;
}

int fleschcalc(int syll, int word, int senten) {
    //Calculating the value
    int flesch = (206.835 - 84.6 * (syll / word) - 1.015 * (word / senten));

    printf("\nFlesch Index: %d\n", flesch);
}
//I'm unsure why this isn't working.