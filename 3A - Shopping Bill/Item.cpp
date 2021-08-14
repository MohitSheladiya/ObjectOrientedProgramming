/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Item.h"

using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strncpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
		//for (int i = 0; i < 20; i++) {
		//	if (name != NULL) {
		//	m_itemName[i] = name[i];
       	//	}
		//}
	}

	void Item::setEmpty() {
		m_price = 0.00;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		setEmpty();
		if (name != nullptr && price > 0) {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		double taxrate = 0;
		if (m_taxed) {
			taxrate = (m_price * 0.13);
		}
		else {
			taxrate = 0;
		}
		return taxrate;
	}

	bool Item::isValid()const {
		if (m_price != 0 && m_itemName != NULL) {
			return true;
		}
		else
			return false;
	}

	void Item::display()const {
		bool a = isValid();
		
		if (a) {
			cout << "| ";
			cout << left << setfill('.') << setw(20) << m_itemName;
			cout << " | ";
			cout.setf(ios::right);
			cout.width(7);
			cout << fixed << setprecision(2) << setfill(' ');
			cout << m_price;
			cout << " | ";
			if (m_taxed == true) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |";
			cout << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |";
			cout << endl;
		}
	}

}