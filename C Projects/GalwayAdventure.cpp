/*
Oisin Mc Laughlin
22441106
21/6/23
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char description[100];
    int n, s, e, w, in, out;
} location;

location locations[40];
int numLocations = 0;
char locationsFile[] = "/Users/oisinmcl/Downloads/adventure_locations.txt";

FILE* openFileForReading(char* filename) {
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) 
        printf("Could not open %s\n", filename);
    return file_ptr;
}

bool readLocations() {
    FILE* file_ptr = openFileForReading(locationsFile);
    if (file_ptr == NULL)
        return false;

    numLocations = 0;
    int readHeaderLines = 0;
    char line[200];
    while (fgets(line, 99, file_ptr) != NULL) {
        if (readHeaderLines<2)
            readHeaderLines++;
        else {
            numLocations++;
            location l;
            int locNum;
            sscanf(line, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%[^\t]\n", &locNum, &l.n, &l.s, &l.e, &l.w, &l.in, &l.out, l.description);
            locations[numLocations] = l; // the 1st location is 1 (not 0) so we can use 0 to mean 'nothing' in adventure_locations.txt
        }
    }

    return true;
}

int main() {
    if (readLocations()) {
        printf("Successfully read %d locations from file\n", numLocations);
    }
}