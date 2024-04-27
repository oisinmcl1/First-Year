// CT102 Algorithms 2023
// quicksort with 2 partitions

// To Do: 
// 1. Include libraries
// 2. Include main() and call quickSort function
// 3. Add code to time, count comparisons and swaps

#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define ARRAY_LIMIT 5000

int cnt_qs_calls = 0;
int mergeSortCalls = 0;
int swap_calls = 0;
int dataMove = 0;
int comparisons = 0;

void quickSort (int[], int, int);
int partition (int[], int, int);
int partition2 (int[], int, int);

void merge(int[], int, int, int);
void mergeSort(int[], int, int);

void swap (int *, int *);

void quickSort(int arrA[], int startval, int endval) {
	++cnt_qs_calls;

	if ( (endval - startval) < 1) {
		return;
	}
	else {
		int k = partition2(arrA, startval, endval); 
		//now sort the two sub-arrays
		quickSort(arrA, startval, k - 1);  //left partition
		quickSort(arrA, k + 1, endval);   //right partition
	}
}

// partition using nested while loops
int partition (int arrA[], int startval, int endval)
{
	int i = startval + 1;
	int k = endval;
	int pivot = arrA[startval];

	while (k >= i) {		
		while (arrA[i] <= pivot && i <= k) {
			i++;
            comparisons++;
		}
		while (arrA[k] > pivot && k >= i) {
			k--;
            comparisons++;
		}    
	    if (k > i){ //swap values at k and i
			swap(&arrA[i], &arrA[k]);
            swap_calls++;
		}       
	} 
	//out of this loop when k >= i not true
    swap(&arrA[startval], &arrA[k]);
    swap_calls++;

	return(k);
}

// better version of partition .. no nested loop
// pivot at startval as before
int partition2 (int arrA[], int startval, int endval)
{
	int k;
	int pivot = arrA[startval];
	int i = startval;
  
	for (k = startval + 1; k <= endval; k++) { // k keeps incrementing to the end
        comparisons++;
        if (arrA[k] <= pivot) {  
            i++;   // i only increments when there is a new value to add to the <= portion
            if (i != k) {  
				swap (&arrA[i], &arrA[k]);
			}
        }
    }
	swap (&arrA[i], &arrA[startval]);  // put pivot in correct location i
	return(i);
}

// call with  ... swap(&arrA[i], &arrA[j]) to swap the values at positions i and j
void swap(int* a, int* b)
{
    ++swap_calls;
    //++cnt_swap_calls;
	int temp = *a;
    *a = *b;
    *b = temp;
}



// Recursive implementation of mergesort algorithm
// Iterative version of merge
// CT102 2023

//mergeSort to sort values in an integer array 
void mergeSort(int A[], int lb, int ub)
{
    ++mergeSortCalls;
	int mid;

	if (lb < ub) {
		// mid = int((lb + ub) / 2);
        mid = ((lb + ub) / 2);
		mergeSort(A, lb, mid);
		mergeSort(A, mid + 1, ub);
		merge(A, lb, mid, ub);
	}

}

// merge two sorted portions of an integer array arrA[]: 
// portions are lb to mid and mid+1 to ub
void merge(int arrA[], int lb, int mid, int ub) {

	int i, j, k;
	int size = ub - lb + 1;
	int arrC[ARRAY_LIMIT];	//temporary array to hold sorted values

	i = lb;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= ub) {

        comparisons++;
		if (arrA[i] <= arrA[j]) {
			arrC[k] = arrA[i];
			i++;
            dataMove++;
		}
		else {
			arrC[k] = arrA[j];
			j++;
            dataMove++;
		}
		k++;
	} //end while

	// write out anything left in i part
	while (i <= mid) {
		arrC[k] = arrA[i];
		i++;
		k++;
        dataMove++;
	}
	// write out anything left in j part
	while (j <= ub) {
		arrC[k] = arrA[j];
		j++;
		k++;
        dataMove++;
	}

	//write back from arrC to arrA so correct values are in place for next merge
	i = lb;
	k = 0;
	while (i <= ub) {
		arrA[i] = arrC[k];
		i++;
		k++;
	}

}



int main() {

	int arrA[ARRAY_LIMIT];
	int i, size;
	// FILE* fptr;
	clock_t t;


	//get data from file and put in array arrA
	// fopen(&fp, "/Users/oisinmcl/Downloads/5000intsUnsorted(1).txt", "r");
    FILE* fptr = fopen("/Users/oisinmcl/Downloads/5000intsUnsorted(1).txt", "r");

	if (NULL == fptr) {
		fprintf(stderr, "Error opening file\n");
	}
	else {
		printf("Opening File ....\n");
		
		for (i = 0; !feof(fptr) && i < ARRAY_LIMIT; i++) {
			fscanf(fptr, "%d", &arrA[i]);
		}
	
		fclose(fptr);
		size = i;

        // printf("\n------------------------------------\nMerge Sort Sort\n");
        // clock_t t;
        // t = clock();
		// mergeSort(arrA, 0, size - 1);
        // double timeTaken = ((double)t) / CLOCKS_PER_SEC;
        // printf("\nTime Taken: %lf\n", timeTaken);
        // printf("Total Moves: %d\n", dataMove);
        // printf("Total Comparisons: %d\n", comparisons);
        // printf("Total Calls: %d\n", mergeSortCalls);
        // printf("\n------------------------------------\n\n");

        printf("\n------------------------------------\nQuick Sort\n");
        clock_t t;
        t = clock();
		quickSort (arrA, 0, size - 1);
        double timeTaken = ((double)t) / CLOCKS_PER_SEC;
        printf("\nTime Taken: %lf\n", timeTaken);
        printf("Total Swaps: %d\n", swap_calls);
        printf("Total Comparisons: %d\n", comparisons);
        printf("Total Calls: %d\n", cnt_qs_calls);
        printf("\n------------------------------------\n\n");

		// print or write out results to check
	
	
		// print out counts of function calls and time etc
	
	}  //close else

}