/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Food.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strncpy(m_itemName, name, 30);
		m_itemName[30] = '\0';
	}

	void Item::setEmpty() {
		m_cal = 0.;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, int cal, int meal) {
		setEmpty();
		if (name != nullptr && cal > 0 && cal <= 3000) {
			setName(name);
			m_cal = cal;
			m_meal = meal;
		}
	}

	int Item::cal()const {
		return m_cal;
	}

	bool Item::isValid()const {
		if (m_cal > 0 && m_cal <= 3000 && m_itemName != NULL && m_meal > 0 && m_meal < 5) {
			return true;
		}
		else
			return false;
	}

	void Item::display()const {
		bool a = isValid();

		if (a) {
			cout << "| ";
			cout << left << setfill('.') << setw(30) << m_itemName;
			cout << " | ";
			cout.setf(ios::right);
			cout.width(4);
			cout << fixed << setfill(' ');
			cout << m_cal;
			cout << " | ";
			if (m_meal == 1) {
				cout << "Breakfast ";
			} else if (m_meal == 2) {
				cout << "Lunch     ";
			} else if (m_meal == 3) {
				cout << "Dinner    ";
			} else if (m_meal == 4) {
				cout << "Snack     ";
			}
			else {
				cout << "          ";
			}

			cout << " |";
			cout << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |";
			cout << endl;
		}
	}

}