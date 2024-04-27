// CT102 Algorithms
// Reading integers from a file in to an array
// Writing integers from an array in to a file


#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LIMIT 1500


// testing functions in main() with data read from file
int main() {

	int arrA[ARRAY_LIMIT];
	
	int i, size;
	
	//FILE *fptr, *outfp;

	FILE *fptr = fopen("/Users/oisinmcl/Downloads/1000Ints.txtt", "r");
	//fopen_s(&fptr, "C:\\Users\\unsortedArray.txt", "r"); //make sure you have the correct directory and specified correctly
	
	if (fptr == NULL) {
		puts("Error Opening File \n Exiting ........");
		return(1);
	}
	else {
		printf("Opening File ....\n");
		
		for (i = 0; !feof(fptr) && i < ARRAY_LIMIT; i++) {
			fscanf_s(fptr, "%d", &arrA[i]);
		}
	
		fclose(fptr);
		size = i - 1;

		// do some work


		//write array data TO file and print out to check

		fopen_s(&outfp, "C:/Users/sortedArray2023.txt", "w");

		if (outfp == NULL) {
			puts("Error Opening File \n Exiting ........");
			return(1);
		}
		else {
			printf("\n Printing out Sorted array and writing to file:: ");
			for (i = 0; i < size; i++) {
				fprintf(outfp, "%d\n", arrA[i]);
				printf("\n %d", arrA[i]);
			}

			fclose(outfp);
		}
		

	} //close else
	return(1);
}