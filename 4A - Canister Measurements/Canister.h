/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/10
*/

#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
    class Canister {
        char* m_contentName;
        double m_diameter; // in centimeters 
        double m_hieght;   // in centimeters
        double m_contentVolume;  // in CCs
        bool m_usable;
        void setToDefault();
        void setName(const char* Cstr);
        bool isEmpty()const;
        bool hasSameContent(const Canister& C)const;
    public:
        Canister();
        Canister(const char* contentName);
        Canister(double hieght, double diameter, const char* contentName = nullptr);
        ~Canister();
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister& C);
        double volume()const;
        std::ostream& display()const;
        double capacity()const;
        void clear();
    };
}

#endif // !SDDS_BOX_H