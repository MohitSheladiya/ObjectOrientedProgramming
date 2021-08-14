/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          25/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds {
    Rectangle::Rectangle() :LblShape() {
        m_width = 0;
        m_height = 0;
    }

    Rectangle::Rectangle(const char* c, int w, int h) : LblShape(c) {
        int l;
        m_width = w;
        m_height = h;

        l = strlen(label());
        if (m_width < l + 2 || m_height < 3) {
            m_width = 0;
            m_height = 0;
        }
    }

    Rectangle::~Rectangle(){}

    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(3000, ',');
        is >> m_height;
        is.ignore(3000, '\n');
    }

    void Rectangle::draw(ostream& os)const {
        int l = strlen(label());
        if (m_width > 0) {
            if (m_height > 0) {
                os << "+";
                for (int i = 0; i < m_width - 2; i++) os << "-";
                os << "+";
                os << endl;

                os << "|";
                os << left << label();
                for (int i = 0; i < (m_width - 2) - l; i++) os << " ";
                os << "|";
                os << endl;

                for (int i = 0; i < m_height - 3; i++) {
                    os << "|";
                    for (int j = 0; j < m_width - 2; j++) os << " ";
                    os << "|" << endl;
                }

                os << "+";
                for (int i = 0; i < m_width - 2; i++) os << "-";
                os << "+";
            }
        }
    }

}