/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/01/27
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Employee.h"

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


    bool read(int& number) {   // This function is defined to get employee number of the employee from the file
  
        if (fscanf(fptr, "%d,", &number) == 1) {
            return true;
        } else {
            return false;
        }
    }
    

    bool read(double& salary) { // This function is defined to get employee salary of the employee from the file
    
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true;
        } else {
            return false;
        }
   
    }


    bool read(char* name) {    // This function is defined to get name of the employee from the file
   
        if (fscanf(fptr, "%[^\n]\n", name) == 1) {
            return true;
        } else {
            return false;
        }
   
    }
    
}