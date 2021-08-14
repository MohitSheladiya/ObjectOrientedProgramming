/* Citation and Sources...
Final Project Milestone
Module:	  TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/04/01
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "TriagePatient.h"

using namespace std;
namespace sdds {

    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket, fileIO()) {
        m_symptom = nullptr;
        nextTriageTicket = nextTriageTicket + 1;
    }

    char TriagePatient::type() const { return 'T'; }

    ostream& TriagePatient::csvWrite(ostream& os)const {
        Patient::csvWrite(os);
        os << ",";
        os << m_symptom;
        return os;
    }

    istream& TriagePatient::csvRead(istream& is) {
        string name;        

        Patient::csvRead(is);
        is.ignore(1000, ',');
        getline(is, name, '\n');
        delete[] m_symptom;
        m_symptom = nullptr;
        m_symptom = new char[name.length() + 1];
        strcpy(m_symptom, name.c_str());
        nextTriageTicket = number() + 1;
        return is;
    }

    ostream& TriagePatient::write(ostream& os)const {
        if (fileIO()) 
            csvWrite(os);
        else {
            os << "TRIAGE";
            os << endl;
            Patient::write(os);
            os << endl;
            os << "Symptoms: ";
            os << m_symptom << endl;
        }
        return os;
    }

    istream& TriagePatient::read(istream& is) {
        if (fileIO())
            csvRead(is);
        else {
            string name;
            delete[] m_symptom;
            Patient::read(is);
            cout << "Symptoms: ";
            getline(is, name, '\n');
            m_symptom = new char[name.length() + 1];
            strcpy(m_symptom, name.c_str());
        }
        return is;
    }

    TriagePatient::~TriagePatient() { delete[] m_symptom; }
}