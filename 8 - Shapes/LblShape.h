/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include <stdio.h>
#include "Shape.h"

using namespace std;
namespace sdds {
    class LblShape : public Shape {
        char* m_label = nullptr;
    protected:
        char* label() const;
    public:
        LblShape();
        LblShape(const char* c);
        virtual ~LblShape();
        void getSpecs(istream& is);
        void operator=(const LblShape& A) = delete;
        LblShape(const LblShape& A) = delete;
        virtual void draw(ostream& os) const = 0;
    };
}
#endif