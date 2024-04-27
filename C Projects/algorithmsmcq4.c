#include <stdio.h>
#include <stdlib.h>

int main() {
    int arrA[8] = {36, 296, 34, 42, 4, 8, 29, 84};
    int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

    for (i = 0; i < 8; i++) {
        ++freq[arrA[i]/1 % 10];
    }
    for (i = 0; i < 10; i++) {
        printf("\n%d\n", freq[i]);
    }
}