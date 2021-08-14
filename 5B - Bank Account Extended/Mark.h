/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/21
*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {

    public:
        int m_number;
        Mark();
        Mark(int num);
        int operator=(int& num);
        int operator+=(int num);
        operator int();
        operator double();
        operator char();
    };
    int operator+=(int &num, Mark &A);
}

#endif