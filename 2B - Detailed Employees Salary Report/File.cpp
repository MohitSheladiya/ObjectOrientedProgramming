/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/01
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Population.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char postal[]) {    
        return fscanf(fptr, "%[^,],", postal) == 1;

    }

    bool read(int& total) {   

        return fscanf(fptr, "%d\n", &total) == 1;
    }


}