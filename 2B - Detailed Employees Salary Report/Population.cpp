/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/01
*/

#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring>
using namespace std;

namespace sdds {

    int noOfCodes;
    Population* canada;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfCodes - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (canada[j].totalpop > canada[j + 1].totalpop) {
                    temp = canada[j];
                    canada[j] = canada[j + 1];
                    canada[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char data[]) {

        bool ok = false;
        int i = 0;
        const char* DATAFILE;
        DATAFILE = data;

        if (openFile(DATAFILE)) {
            noOfCodes = noOfRecords();            
            canada = new Population[noOfCodes];
            
            for (i = 0; i < noOfCodes; i++) {      
                ok = load(canada[i]);
                ok = true;
            }

            if (ok == 0) cout <<  "Error: incorrect number of records read; the data is possibly corrupted.";
            else ok = true;
            
            closeFile(); 
        }
        
        return ok;
    }

    bool load(Population& pop) {

        bool ok = false;     
        char str[128];
        int length;

        if (true) {
            ok = read(str);
            length = strlen(str) + 1;
            ok = ok && read(pop.totalpop);
            pop.postalcode = new char[length];
            strCpy(pop.postalcode, str);
        }
        return ok;
    }

    void strCpy(char* des, const char* src) {

        while ((*des++ = *src++) != '\0');

    }

    void display() {

        sort(); // Data that is inputed is been sorted by the function "sort"
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        int t = 0;

        for (int i = 0; i < noOfCodes; i++) { 
            cout << i + 1 << "-  ";
            display(canada[i]);   // display function gets executed here 
            t = t + canada[i].totalpop;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << t << endl;
    }

    void display(Population& displayDetails) {

        cout << displayDetails.postalcode << ": " << displayDetails.totalpop << endl;  // The output screen is going to have outputin the following sequence  

    }

    void deallocateMemory() {   // This function is used to delocate the memory address of "canada"
        delete[] canada;
        canada = nullptr;
    }

}
