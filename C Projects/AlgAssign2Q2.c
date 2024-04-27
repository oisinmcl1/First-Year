#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void mergeSort(int arrA[], int lb, int ub);
void merge (int arrA[], int lb, int mid, int ub);

int arrA[11] = {20, 7, 12, 10, 11, 16, 21, 10, 9, 6, 1};

int main() {
    merge(arrA, 0, 5, 10);
}

// must be called initially with lb = 0 and ub = size - 1
void mergeSort(int arrA[], int lb, int ub) {
int mid;
    if (lb < ub) {
        mid = ((lb + ub) / 2);
        mergeSort(arrA, lb, mid);
        mergeSort(arrA, mid + 1, ub);
        merge(arrA, lb, mid, ub);
    } 
}
void merge (int arrA[], int lb, int mid, int ub) {
    int i, j, k;
    int size = ub - lb + 1;
    int *arrC = (int*) malloc(size * sizeof(int));

    for (i = lb, j = mid + 1, k = 0; i <= mid && j <= ub; k++) {
       if (arrA[i] <= arrA[j]) {
           arrC[k] = arrA[i++];
        }
        else {
           arrC[k] = arrA[j++];
       }
    } // end for loop

    while (i <= mid) {
       arrC[k++] = arrA[i++];
    }
    while (j <= ub) {
       arrC[k++] = arrA[j++];
    }
    for (i = lb, k = 0; i <= ub; i++, k++) {
       arrA[i] = arrC[k];
    }

    for(int l = 0; l < 15; l++) {
        printf("\n%d\n", arrC[l]);
    }
}