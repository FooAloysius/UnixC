#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

int main (int argc, char *argv[]) {
    if (argc != 3) {
        printf("Number of parameter is is incorrect.");
        return 1;
    }

    int index, i;
    const char *filename;
    int count;
    index = atoi(argv[1]);
    filename = argv[2];

    FILE* f = fopen(filename, "r");
    if(!f && ferror(f)) {
        perror("Error opening the file.");
        return 1;
    }
    
    if(fscanf(f, "%d\n", &count) != 1) {
        fprintf(stderr, "Failed to read the entry count.\n");
        fclose(f);
        return 1;
    }

    if (index < 0 || index >= count) {
        fprintf(stderr, " Index out of range (0 to %d).\n", count - 1);
    }

    /* Allocate array of structs */
    Entry *entries = (Entry*)malloc(sizeof(Entry) * count);
    if (!entries) {
        perror("Malloc failed to allocate memory.");
        fclose(f);
        return 1;
    }

    /* Read entries*/ 
    for (i = 0; i < count; i++) {
        /* Read date */
        if (fscanf(f, "%d/%d/%d\n", &entries[i].day, &entries[i].month, &entries[i].year) != 3) {
            fprintf(stderr, " Error reading date for entry %d\n", i);
            free(entries);
            fclose(f);
            return 1;
        }

        /* Read text line */
        if (!fgets(entries[i].text, MAX_TEXT, f)) {
            fprintf(stderr, " Error reading the text from entry %d\n", i);
            free(entries);
            fclose(f);
            return 1;
        }

    }
    /* Remove the trailing nexline */
    entries[i].text[strcspn(entries[i].text, "\n")] = '\0'; /* scans the string*/

    fclose(f);
    /* print the selected entry in yyyy.mm.dd format */
    Entry e = entries[index];
    printf("%04d.%02d.%02d: %s\n", e.year, e.month, e.day, e.text);

    free(entries);
    return 0;
}