/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include <stdio.h>
#include "LblShape.h"

using namespace std;
namespace sdds {
    class Line : public LblShape {
        int m_length;
    public:
        void draw(ostream& os) const;
        void getSpecs(istream& is);
        Line();
        Line(const char* c, int i);
        ~Line();
    };
}
#endif