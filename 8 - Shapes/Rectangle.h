/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include <stdio.h>
#include "LblShape.h"

using namespace std;
namespace sdds {
    class Rectangle : public LblShape {
        int m_width;
        int m_height;
    public:
        void draw(ostream& os) const;
        void getSpecs(istream& is);
        Rectangle();
        Rectangle(const char* c, int w, int h);
        ~Rectangle();
    };
}
#endif