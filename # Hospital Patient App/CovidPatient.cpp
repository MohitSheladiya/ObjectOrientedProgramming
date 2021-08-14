/* Citation and Sources...
Final Project Milestone
Module:	  CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"

using namespace std;
namespace sdds {

    int nextCovidTicket = 1;

    CovidPatient::CovidPatient() : Patient(nextCovidTicket, fileIO()) { nextCovidTicket = nextCovidTicket + 1; }

    char CovidPatient::type() const { return 'C'; }

    istream& CovidPatient::csvRead(istream& is) {
        Patient::csvRead(is);
        is.ignore(2000, '\n');
        nextCovidTicket = number() + 1;
        return is;
    }
    
    ostream& CovidPatient::csvWrite(ostream& os)const {
        Patient::csvWrite(os);
        return os;
    }

    istream& CovidPatient::read(istream& is) {
        if (fileIO() == true)
            csvRead(is);
        else
            Patient::read(is);
        return is;
    }

    ostream& CovidPatient::write(ostream& os)const {
        if (fileIO() == true) 
            Patient::csvWrite(os);
        else {
            os << "COVID TEST";
            os << endl;
            Patient::write(os);
            os << endl;
        }
        return os;
    }
}