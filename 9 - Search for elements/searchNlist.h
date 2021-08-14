/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/04/01
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "ReadWrite.h"

using namespace std;
namespace sdds {

    template<typename Temp, typename A>
    bool search(Collection<Temp>& obj, Temp list[], int num, A key) {
        bool flag = false;
        for (int i = 0; i < num; i++)
            if (list[i] == key) {
                obj.add(list[i]);
                flag = true;
            }
        return flag;
    }

    template<typename Temp>
    void listArrayElements(const char* head, const Temp obj[], int num) {
        cout << head;
        cout << endl;
        for (int i = 0; i < num; i++) cout << i + 1 << ": " << obj[i] << endl;
    }
}
#endif