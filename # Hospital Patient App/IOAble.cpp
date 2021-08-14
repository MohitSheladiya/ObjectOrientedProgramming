/* Citation and Sources...
Final Project Milestone
Module:	  IOAble
Filename: IOAble.cpp
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/21
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include "Time.h"
#include "utils.h"
#include "IOAble.h"

using namespace std;
namespace sdds {
    IOAble::~IOAble() {}

    ostream& IOAble::csvWrite(std::ostream& a)const { return a; }

    istream& IOAble::csvRead(std::istream& a) { return a; }

    ostream& IOAble::write(std::ostream& a)const { return a; }

    istream& IOAble::read(std::istream& a) { return a; }

    istream& operator>>(istream& istr, IOAble& A) { return A.read(istr); }

    ostream& operator<<(ostream& ostr, IOAble& A) { return A.write(ostr); }
}