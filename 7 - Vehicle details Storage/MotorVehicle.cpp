/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          18/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
    MotorVehicle::MotorVehicle(const char licencePlate[], int year) {
        strcpy(m_vehicleAddress, "Factory");
        m_year = year;
        if (strlen(licencePlate) < sizeof(m_licencePlate)) {
            strcpy(m_licencePlate, licencePlate);
        }
    }

    MotorVehicle::~MotorVehicle() {}

    void MotorVehicle::moveTo(const char* address) {
        if (address != m_vehicleAddress) {
            cout << "|" << setw(8) << right << m_licencePlate << "| |";
            cout << setw(20) << right << m_vehicleAddress << " ---> ";
            cout << setw(20) << left << address << "|";
            cout << endl;
            if (strlen(address) < sizeof(m_vehicleAddress)) {
                strcpy(m_vehicleAddress, address);
            }
        }
    }

    ostream& MotorVehicle::write(ostream& os)const {
        os << "| " << m_year << " | " << m_licencePlate << " | " << m_vehicleAddress;
        return os;
    }

    istream& MotorVehicle::read(istream& in) {
        cout << "Built year: ";
        in >> m_year;
        cout << "License plate: ";
        in >> m_licencePlate;
        cout << "Current location: ";
        in >> m_vehicleAddress;
        return in;
    }

    ostream& operator<<(ostream& os, const MotorVehicle& A) {
        return A.write(os);
    }

    istream& operator>>(istream& in, MotorVehicle& A) {
        return A.read(in);
    }
}