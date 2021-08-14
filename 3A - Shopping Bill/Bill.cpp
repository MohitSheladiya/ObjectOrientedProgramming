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
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		bool valid = false;
		if (m_title != nullptr && m_items != nullptr) {
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

	double Bill::totalTax()const {
		double taxsum = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			taxsum = taxsum + m_items[i].tax();
		}
		return taxsum;
	}

	double Bill::totalPrice()const {
		double totalsum = 0;
		for (int j = 0; j < m_noOfItems; j++) {
			totalsum = totalsum + m_items[j].price();
		}
		return totalsum;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;

		if (isValid() != true) {
			cout << "| ";
			cout << left << setfill(' ') << setw(36) << m_title;
			cout << " |";
			cout << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		if (!isValid() == true) {
			cout << "|                Total Tax: ";
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax();
			cout << " |";
			cout << endl;

			cout << "|              Total Price: ";
			cout.setf(ios::right);
			cout.width(10);
			cout << totalPrice();
			cout << " |";
			cout << endl;

			cout << "|          Total After Tax: ";
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout << " |";
			cout << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems < 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strcpy(m_title, title);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool check = false;
		if(m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded = m_itemsAdded + 1;
			check = true;
		}
		return check;
	}

	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate(){
		delete[] m_items;
		m_items = nullptr;
	}
}