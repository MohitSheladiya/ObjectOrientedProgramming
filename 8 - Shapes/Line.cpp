/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include "Line.h"

using namespace std;
namespace sdds {
    void Line::draw(ostream& os)const {
        if (label() != nullptr) {
            if (m_length > 0) {
                os << label() << endl;
                for (int i = 0; i < m_length; i++) os << "=";
            }
        }
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(3000, '\n');
    }

    Line::Line() :LblShape() { m_length = 0; }

    Line::Line(const char* c, int i) : LblShape(c) { m_length = i; }

    Line::~Line() {}
}