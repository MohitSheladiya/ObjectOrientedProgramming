/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          18/03/21
*/

#ifndef MotorVehicle_H_
#define MotorVehicle_H_
#include <iostream>
#include <string.h>

const int PLATE = 9;
const int ADDRESS = 64;

using namespace std;
namespace sdds {
    class MotorVehicle {
        char m_licencePlate[PLATE];
        char m_vehicleAddress[ADDRESS];
        int m_year;
    public:
        MotorVehicle(const char licencePlate[], int year);
        ~MotorVehicle();
        void moveTo(const char* address);
        ostream& write(ostream& os)const;
        istream& read(istream& in);
    };
    ostream& operator<<(ostream& os, const MotorVehicle& A);
    istream& operator>>(istream& in, MotorVehicle& A);
}
#endif