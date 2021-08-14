/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
#include <stdio.h>

using namespace std;
namespace sdds {
    class Shape {
    public:
        virtual ~Shape();
        virtual void draw(ostream&) const = 0;
        virtual void getSpecs(istream&) = 0;
    };
    std::istream& operator>>(istream& is, Shape& A);
    std::ostream& operator<<(ostream& os, const Shape& A);
}
#endif
