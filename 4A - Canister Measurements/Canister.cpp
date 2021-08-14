/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/10
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>  
#include "Canister.h"
using namespace std;
namespace sdds {

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_hieght = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const{
		bool flag = false;
		if(m_contentVolume < 0.00001)
			flag = true;
		
		return flag;
	}

	bool Canister::hasSameContent(const Canister& C)const {
		bool flag = false;
		if (m_contentName != nullptr && C.m_contentName != nullptr && strcmp(m_contentName, C.m_contentName) == 0) 
			flag = true;
		
		return flag;
	}

	void Canister::setName(const char* Cstr) {
		int l;
		if (Cstr != nullptr && m_usable) {
			m_contentName = nullptr;
			m_contentName = new char[strlen(Cstr) + 1];
			l = strlen(Cstr);
			strncpy(m_contentName, Cstr, l);
			m_contentName[l] = '\0';
		}
		else {
			if (m_hieght < 10 && m_hieght > 40 && m_diameter < 10 && m_diameter > 30)
				setToDefault();
		}
	}

	Canister::Canister(){
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double hieght, double diameter, const char* contentName ) {
		setToDefault();
		if (hieght >= 10 && hieght <= 40 && diameter >= 10 && diameter <= 30) {
			m_hieght = hieght;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
		else m_usable = false;
	}

	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear() {
		if (m_usable == false) 
			setToDefault();
	}

	double Canister::capacity()const {
		double capacity = 0;
		double PI = 3.14159265;
		capacity = PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2);
		return capacity;
	}

	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (!contentName) 
			m_usable = false;
		else if (isEmpty()) 
			setName(contentName);
		else if (!hasSameContent(contentName)) 
			m_usable = false;
		
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		double total = 0;
		total = quantity + m_contentVolume;
		if (m_usable == true && quantity > 0 && total <= capacity())
			m_contentVolume += quantity;
		else m_usable = false;

		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.m_contentVolume > (capacity()-volume())) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0;
		}
		return *this;
	}

	ostream& Canister::display()const {
		cout.setf(ios::right);
		cout.width(7);
		cout << fixed << setprecision(1) << setfill(' ');
		cout << capacity();
		cout << "cc (" << m_hieght << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			return cout << " of Unusable content, discard!";
		}
		else {
			
			if (m_contentName != nullptr) {
				cout << " of ";
				cout.setf(ios::right);
				cout.width(7);
				cout << fixed << setprecision(1) << setfill(' ');
				cout << volume();
				cout << "cc   " << m_contentName;
				return cout;
			} else
			return cout;
		}
		  
	}

}