/* Citation and Sources...
Final Project Milestone
Module:	  IOAble
Filename: IOAble.h
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/21
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
namespace sdds {
    class IOAble {
    public:
        virtual ~IOAble();
        virtual ostream& csvWrite(ostream& a)const;
        virtual istream& csvRead(istream& a);
        virtual ostream& write(ostream& a)const;
        virtual istream& read(istream& a);
    };
    ostream& operator<<(ostream& ostr, IOAble& A);
    istream& operator>>(istream& istr, IOAble& A);
}
#endif