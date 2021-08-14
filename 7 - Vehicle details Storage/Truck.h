/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          18/03/21
*/

#ifndef TRUCK_H_
#define TRUCK_H_
#include "MotorVehicle.h"
#include <iostream>
#include <string.h>

using namespace std;
namespace sdds {
    class Truck : public MotorVehicle {
        double m_maxW;
        double m_precision;
    public:
        Truck(const char licencePlate[], int year, double capacity, const char* currentAddress);
        ~Truck();
        bool addCargo(double cargo);
        bool unloadCargo();
        ostream& write(ostream& os)const;
        istream& read(istream& in);
    };
    ostream& operator<<(ostream& os, const Truck& A);
    istream& operator>>(istream& in, Truck& A);
}
#endif