/*
Oisin Mc Laughlin
22441106
21/6/23
28/6/23
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Main structure with description of each location and their resulting directions.
typedef struct {
    char description[100];
    int n, s, e, w, in, out;
} location;

//Structure for items.
typedef struct {
    char name[50];
    int itemloc;
    char description[100];
} item;

//Variables and file directory.
location locations[40];
item items[40];
int numLocations = 0;
int numItems = 0;
char locationsFile[] = "/Users/oisinmcl/Downloads/adventure_locations.txt";

//Opening file and setting pointer, checking if file pointer is set correctly.
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
    //While not end if line
    while (fgets(line, 99, file_ptr) != NULL) {
        //If header lines is less than 2, incriment header lines.
        if (readHeaderLines<2)
            readHeaderLines++;
        //Else, incriment numlocations and scan in other locations to each part of the structure.
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

//This function here is just a reworked code from the function above.
//It reads in the name, location number and description from the text file and adds it to the structure.
bool readInventory() {
    FILE* file_ptr = openFileForReading("/Users/oisinmcl/Downloads/adventure_objects.txt");
    if (file_ptr == NULL)
        return false;

    numItems = 0;
    int readHeaderLines = 0;
    char line[200];
    //While not end if line
    while (fgets(line, 99, file_ptr) != NULL) {
        //If header lines is less than 2, incriment header lines.
        if (readHeaderLines<2)
            readHeaderLines++;
        //Else, incriment numlocations and scan in other locations to each part of the structure.
        else {
            item l;
            sscanf(line, "%[^\t]\t%d\t%[^\t]\n", l.name, &l.itemloc, l.description);
            // printf("%s",l.description);
            items[numItems] = l; // the 1st location is 1 (not 0) so we can use 0 to mean 'nothing' in adventure_locations.txt
            numItems++;
        }
    }
    return true;
}

int main() {
    //Declaring variables.
    char input[50];
    int curr = 1;
    char inventory[100];
    int invcount = 0;
    int j = 0;

    if (readLocations()) {
        printf("Successfully read %d locations from file\n", numLocations);
    }
    if (readInventory()) {
        printf("Successfully read %d items from file\n", numItems);
    }
    //Printing welcome message.
    printf("\nWelcome to the Galway Adventure. Type 'help' for help.\n\n");

    // for (int i = 1; i < 10; i++) {
    //         printf("%s",locations[i].description);
    // }
    // printf("\n");

    //While input is not "quit", keep looping.
    while ((strcmp(input, "quit") != 0)) {
        //Printing current location
        printf("%s\n", locations[curr].description);

        //Scan the user's input.
        scanf("%s", &input);
        //If user input is "help", display help message.
        if (strcmp(input, "help") == 0) {
            printf("\nI know these commands:\nn, s, e, w, in, out, look, help, take, inventory, drop, quit\n\n");
        }

        //If user input is "n" and n is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "n") == 0)) {
            if (locations[curr].n == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].n);
            }
        }

        //If user input is "s" and s is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "s") == 0)) {
            if (locations[curr].s == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].s);
            }
        }

        //If user input is "e" and e is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "e") == 0)) {
            if (locations[curr].e == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].e);
            }
        }

        //If user input is "w" and w is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "w") == 0)) {
            if (locations[curr].w == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].w);
            }
        }

        //If user input is "in" and in is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "in") == 0)) {
            if (locations[curr].in == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].in);
            }
        }

        //If user input is "out" and out is not 0, set curr to the location of n on current location.
        if ((strcmp(input, "out") == 0)) {
            if (locations[curr].out == 0) {
                printf("Cannot move this way\n");
            }
            else {
                (curr = locations[curr].out);
            }
        }

        //If user input is "look", display current location.
        if ((strcmp(input, "look") == 0)) {
            printf("%s\n", locations[curr].description);
            for (int k = 0; k < 10; k++) {
                if (items[j].itemloc == curr) {
                    printf("\nItem in location:\n%s\n\nDescription:\n%s\n\n", items[k].name, items[k].description);
                }
            }
        }
        //If user input is "inventory":
        if (strcmp(input, "inventory") == 0) {
            //Print out the items that have location number set to -1.
            printf("\nItems in Inventory:\n");
            for(int i = 0; i < 40; i++) {
                // printf("\nitem = %s %d\n", items[i].name, items[i].itemloc);
                if (items[i].itemloc == -1) {
                    printf("%s\n", items[i].name);
                }
            }
            printf("\n");
        }
        //Checks if there is any items in the location and prints them.
        for (j = 0; j < 10; j++) {
            if (items[j].itemloc == curr) {
                printf("\nItem in location:\n%s\n\nDescription:\n%s\n\n", items[j].name, items[j].description);
            }
        }

        //If user input is "take".
        if (strcmp(input, "take") == 0) {
            printf("Take what> ");
            //scanf leaves in \n so thats why there is two gets. It wouldn't work otherwise :(
            gets(input);
            gets(input);
            
            printf("\nSearch for %s\n", input);

            //For loop to check if item is there, if so set item location number to -1.
            for (j = 0; j < 40; j++) {
                // printf("\nitem = %s\n", items[j].name);
                if (strcmp(input, items[j].name) == 0) {
                    printf("\nYou took %s\n\n", items[j].name);
                    items[j].itemloc = -1;
                    //-1 means in inventory.
                    }
                }
            //Adding item to inventory.
            if (strcmp(input, items[j].name) == 0) {
                invcount++;
                inventory[invcount] = items[j].name;
                printf("\nItem added to inventory\n\n");
            }
        }

        //If user input is "drop".
        if (strcmp(input, "drop") == 0) {
            printf("Drop what> ");
            //Same issue again :(
            gets(input);
            gets(input);

            //If input is the same as in inventory and item location is -1.
            for (j = 0; j < 10; j++) {
                if (strcmp(input, items[j].name) == 0 && items[j].itemloc == -1) {
                    //Set item location to wherever current location is.
                    printf("\nYou dropped %s\n\n", items[j].name);
                    items[j].itemloc = curr;
                    //-1 means in inventory.
                }
            }
        }
        printf("\n----------------------------------------------------\n\n");
    }
}
//Thank you.
//Final assignment finished, I really appreciate the help from lab tudors throughout the year!