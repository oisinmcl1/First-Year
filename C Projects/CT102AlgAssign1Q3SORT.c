#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LIMIT 1500

void bubbleSort(int arrA[], int size); 
void insertionSort(int arrA[], int size);
void selectionSort(int arrA[], int size);
void countSortRange(int arrA[], int size, int minVal, int maxVal);

int main() {

    int arrA[ARRAY_LIMIT];
	
	int i, size;
    int minimum, maximum = 0;
	
	FILE *fptr = fopen("/Users/oisinmcl/Downloads/5000intsSorted.txt", "r");
	
	if (fptr == NULL) {
		puts("\n\nError Opening File \n Exiting ........");
	}
	else {
		// printf("\n\nOpening File ....\n");
		
		for (i = 0; !feof(fptr) && i < ARRAY_LIMIT; i++) {
			fscanf(fptr, "%d", &arrA[i]);
		}
	
		fclose(fptr);
		size = i;
    }

    for(int j = 0; j < size; j++) {
        if (arrA[j] < minimum) {
            minimum = arrA[j];
        }
        if (arrA[j] > maximum) {
            maximum = arrA[j];
        }
    }
    // printf("\nMin: %d\nMax: %d\n", minimum, maximum);

    // bubbleSort(arrA, size); 
    // insertionSort(arrA, size);
    // selectionSort(arrA, size);
    countSortRange(arrA, size, minimum, maximum);

    printf("\n\n");
    // for (int j = 0; j < size; j++) {
    //     printf("%d\t", arrA[j]);
    // }
    // printf("\n\n");
}

//Bubble Sort
void bubbleSort(int arrA[], int size) {
	clock_t time = clock();
    double timeTaken;

    int i, k, temp;
    int swaps = 0, compar = 0;

	for (k = 0; k < size; k++) {
        compar++;
		for (i = 0; i < size - 1 - k; i++) {
            compar++;
            compar++;
			if (arrA[i] > arrA[i+1]) {
				//out of order so swap
				temp = arrA[i];
  				arrA[i] = arrA[i + 1];
				arrA[i + 1] = temp;
                swaps++;
			} 
		} //end inner i for 
	} //end outer k for 

    timeTaken = clock() - time;
    printf("\nBubble Sort of SORTED INTS: Time taken is %lf seconds\n", timeTaken/CLOCKS_PER_SEC);
    printf("\nBubble Sort of SORTED INTS Swaps: %d\n", swaps);
    printf("\nBubble Sort of SORTED INTS Comparrisons: %d\n\n", compar);
}

// Selection Sort: integer array arrA [] of size
void selectionSort(int arrA[], int size) {
    clock_t time = clock();
    double timeTaken;   

	int i, j, min, temp;
    int swaps, compar;

	for (i = 0; i < size - 1; i++) {
		min = i;
        compar++;
		//find next smallest
		for (j = min + 1; j < size; j++) {
            compar++;
			if (arrA[min] > arrA[j]) {
				min = j;
			}
		} // end j for loop

		//swap values at locations i and min, if i != min
		if (i != min) {			
			temp = arrA[i];
			arrA[i] = arrA[min];
			arrA[min] = temp;
            swaps++;
		}
	} //end outer i for loop

    timeTaken = clock() - time;
    printf("\nSelection Sort of SORTED INTS: Time taken is %lf seconds\n", timeTaken/CLOCKS_PER_SEC);
    printf("\nSelection Sort of SORTED INTS Swaps: %d\n", swaps);
    printf("\nSelection Sort of SORTED INTS Comparrisons: %d\n", compar);
}

// Insertion Sort: integer array arrA [] of size
void insertionSort(int arrA[], int size) {
    clock_t time = clock();
    double timeTaken;

	int i, j, curr;
    int swaps, compar;
	
	for(i = 1; i < size; i++) {
		curr  = arrA[i];
	
		for(j = i - 1; j >= 0 && curr < arrA[j]; j--) {   //compare
			//make room ...
            compar++;
			arrA[j + 1] = arrA[j];
		}  
	
		if (i != j + 1) // if not at the correct position already
			arrA[j + 1] = curr;
            swaps++;

	} // end outer i for

    timeTaken = clock() - time;
    printf("\nInsertion Sort of SORTED INTS: Time taken is %lf seconds\n", timeTaken/CLOCKS_PER_SEC);
    printf("\nInsertion Sort of SORTED INTS Swaps: %d\n", swaps);
    printf("\nInsertion Sort of SORTED INTS Comparrisons: %d\n", compar);
} //return

void countSortRange(int arrA[], int size, int minVal, int maxVal) {
    clock_t time = clock();
    double timeTaken;

	int i, value, count;
	int freqSize = maxVal - minVal + 1;
    int swaps, compar;

	int* freq = (int*)malloc(freqSize * sizeof(int));   //create freq[]
	int* arrB = (int*)malloc(size * sizeof(int));       //create arrB[] same size as arrA[]

	// initialise freq[]
	for (i = 0; i < freqSize; i++) {
		freq[i] = 0;
	}

	// count frequencies
	for (i = 0; i < size; i++) {
		++freq[arrA[i] - minVal];
	}

	// get <= in freq[]
	for (i = 1; i < freqSize; i++) {
		freq[i] = freq[i] + freq[i - 1];
	}

	// place values from arrA[] into arrB[]; update freq[]
	for (i = 0; i < size; i++) {
		value = arrA[i];			        //value to sort
		count = freq[value - minVal];		//<= freq of value
		arrB[count - 1] = value; 	        //place value in arrB
		--freq[value - minVal];				//decrement freq[]
        swaps++;
	} //get next value in arrA[]

	//write back sorted values to arrA[] now that sorting finished
	for (i = 0; i < size; i++) {
		arrA[i] = arrB[i];
	}
	free(freq);

    timeTaken = clock() - time;
    printf("\nCount Sort of SORTED INTS: Time taken is %lf seconds\n", timeTaken/CLOCKS_PER_SEC);
    printf("\nCount Sort of SORTED INTS Swaps: %d\n", swaps);
    printf("\nCount Sort of SORTED INTS Comparrisons: %d\n", compar);
}