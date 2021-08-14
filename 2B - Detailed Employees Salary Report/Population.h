/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/01
*/


#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct Population {
        char* postalcode; 
        int totalpop;
    };

    void sort();
    bool load(const char data[]);
    bool load(Population& pop);
    void display();
    void display(Population& displayDetails);
    void deallocateMemory();
    void strCpy(char* des, const char* src);

}
#endif // SDDS_POPULATION_H_