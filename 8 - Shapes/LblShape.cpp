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
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds {

    char* LblShape::label() const { return m_label; }

    LblShape::LblShape() {
        if (m_label != nullptr) m_label = nullptr;
    }

    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }

    LblShape::LblShape(const char* c) {
        int l;
        l = strlen(c);
        m_label = new char[l + 1];
        strcpy(m_label, c);
        m_label[strlen(c)] = '\0';
    }

    void LblShape::getSpecs(istream& is) {
        int l;
        string str;

        getline(is, str, ',');
        l = str.length();

        if (m_label != nullptr) {
            delete[] m_label;
            m_label = nullptr;
        }

        m_label = new char[l + 1];
        strcpy(m_label, str.c_str());
        m_label[l] = '\0';
    }
}