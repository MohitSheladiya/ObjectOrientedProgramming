/* Citation and Sources...
Final Project Milestone
Module:	  Patient
Filename: Patient.cpp
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/29
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <ios>
#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"
#include "Patient.h"

using namespace std;
namespace sdds {
	Patient::Patient(int ticket, bool flag) : m_ticket(ticket) {
		m_name = nullptr;
		m_num = 0;
		m_flag = flag;
	}

	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO()const { return m_flag; }

	void Patient::fileIO(bool flag) { m_flag = flag; }

	bool Patient::operator==(char c)const {
		return type() == c;
	}

	bool Patient::operator==(const Patient& P)const {
		return (type() == P.type());
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	int Patient::number()const {
		return m_ticket.number();
	}

	Patient::operator Time() const {
		return m_ticket.operator sdds::Time();
	}

	ostream& Patient::csvWrite(ostream& os)const {
		os << type() << ',';
		for (unsigned i = 0; i < strlen(m_name); i++) os << m_name[i];
		os << ',';
		os << m_num << ',';
		m_ticket.csvWrite(os);
		return os;
	}

	istream& Patient::csvRead(istream& is) {
		string str;
		getline(is, str, ',');
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[str.length() + 1];
		strcpy(m_name, str.c_str());
		is >> m_num;
		is.ignore(3000, ',');
		m_ticket.csvRead(is);
		return is;
	}

	ostream& Patient::write(ostream& os)const {
		m_ticket.write(os);
		os << endl;
		if ((strlen(m_name) + 1) > 25)
			for (int i = 0; i < 25; i++) os << m_name[i];
		else os << m_name;
		os << ", OHIP: " << m_num;
		return os;
	}

	istream& Patient::read(istream& is) {
		string name;
		cout << "Name: ";
		getline(is, name, '\n');
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[name.length() + 1];
		strcpy(m_name, name.c_str());
		cout << "OHIP: ";
		m_num = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
		return is;
	}
}
