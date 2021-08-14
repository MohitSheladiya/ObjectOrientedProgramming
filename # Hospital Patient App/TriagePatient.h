/* Citation and Sources...
Final Project Milestone
Module:	  TriagePatient
Filename: TriagePatient.h
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/04/01
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Patient.h"

using namespace std;
namespace sdds {
    class TriagePatient : public Patient {
        char* m_symptom;
    public:
        TriagePatient();
        virtual char type() const;
        virtual ostream& csvWrite(ostream& os) const;
        virtual istream& csvRead(istream& is);
        virtual ostream& write(ostream& os) const;
        virtual istream& read(istream& is);
        ~TriagePatient();
    };
}
#endif