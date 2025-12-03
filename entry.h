#ifndef ENTRY_H /* Header guard */
#define ENTRY_H

#define MAX_TEXT 101 /*100 character + null terminator*/


typedef struct {
    int day;
    int month;
    int year;
    char text[MAX_TEXT];
} Entry;

#endif