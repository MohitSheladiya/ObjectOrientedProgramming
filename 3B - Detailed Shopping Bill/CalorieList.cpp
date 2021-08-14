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
#include "CalorieList.h"
using namespace std;
namespace sdds {

	void CalorieList::setEmpty() {
		m_items = nullptr;
	}

	bool CalorieList::isValid()const {
		bool valid = false;
		if (m_items != nullptr) {
			for (int k = 0; k < m_noOfItems && valid != true; k++) {
				if (!m_items[k].isValid()) {
					valid = true;
				}
				else {
					valid = false;
				}
			}
		}
		return valid;
	}

	int CalorieList::totalCal()const {
		double totalsum = 0;
		for (int j = 0; j < m_noOfItems; j++) {
			totalsum = totalsum + m_items[j].cal();
		}
		return totalsum;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;

		if (isValid() != true) {
			cout << "|  ";
			cout << left << setfill(' ') << setw(50) << "Daily Calorie Consumption";
			cout << "|";
			cout << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;

		if (!isValid() == true) {
			cout << "|    Total Calories for today: ";
			cout.setf(ios::right);
			cout.width(8);
			cout << totalCal();
			cout << " |            |";
			cout << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int noOfItems) {
		if (noOfItems < 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int cal, int meal) {
		bool check = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, cal, meal);
			m_itemsAdded = m_itemsAdded + 1;
			check = true;
		}
		return check;
	}

	void CalorieList::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}