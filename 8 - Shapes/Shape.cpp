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
#include "Shape.h"

using namespace std;
namespace sdds {

    Shape::~Shape() {}

    ostream& operator<<(ostream& os, const Shape& A) {
        A.draw(os);
        return os;
    }

    istream& operator>>(istream& is, Shape& A) {
        A.getSpecs(is);
        return is;
    }
}