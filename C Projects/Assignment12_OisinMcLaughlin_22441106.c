#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main() {
       int iarray[5] = { 10,2,9,7,1 };
       int temp;
       int len = 5, pass, i, j;
       
       for (pass = 0; pass < len; pass++) {
              for (i = 0; i < len - pass - 1; i++) {
                     if (iarray[i] > iarray[i + 1]) {
                            temp = iarray[i];
                            iarray[i] = iarray[i + 1];
                            iarray[i + 1] = temp;
                     }
                     for (j = 0; j < len; j++) {
                            printf("%3d", iarray[j]);
                     printf("\n");
                     }
              }
       }
}