/* Citation and Sources...
Final Project Milestone
Module:	  CovidPatient
Filename: CovidPatient.h
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/04/01
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"

using namespace std;
namespace sdds {
    class CovidPatient : public Patient {
    public:
        CovidPatient();
        virtual char type() const;
        virtual istream& csvRead(istream& is);
        virtual ostream& csvWrite(ostream& os) const;
        virtual istream& read(istream& is);
        virtual ostream& write(ostream& os) const;
    };
}
#endif