/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          18/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
    Truck::Truck(const char licencePlate[], int year, double capacity, const char* currentAddress) : MotorVehicle(licencePlate, year) {
        m_maxW = capacity;
        m_precision = 0;
        MotorVehicle::moveTo(currentAddress);
    }

    Truck::~Truck() {}

    bool Truck::addCargo(double cargo) {
        double w = m_precision + cargo;
        bool b = false;
        if (m_precision != m_maxW) {
            if (w <= m_maxW) {
                m_precision += cargo;
                b = true;
            } else {
                m_precision = m_maxW;
                b = true;
            }
        }
        return b;
    }

    bool Truck::unloadCargo() {
        bool b = false;
        if (m_precision != 0) {
            m_precision = 0;
            b = true;
        }
        return b;
    }

    ostream& Truck::write(ostream& os)const {
        MotorVehicle::write(os);
        os << " | " << m_precision;
        os << "/" << m_maxW;
        return os;
    }

    istream& Truck::read(istream& in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> this->m_maxW;
        cout << "Cargo: ";
        in >> this->m_precision;
        return in;
    }

    ostream& operator<<(ostream& os, const Truck& A) {
        return A.write(os);
    }

    istream& operator>>(istream& in, Truck& A) {
        return A.read(in);
    }
}