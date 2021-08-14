/* Citation and Sources...
Final Project Milestone 1
Module:	  Time
Filename: Time.cpp
Version 2.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/30
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = 0;
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		unsigned h, m;
		h = (m_min / 60);
		m = (m_min - (60 * h));

		ostr << setw(2) << setfill('0') << h << ":";
		ostr << setw(2) << setfill('0') << m;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int h = 0, m = 0;
		char c = 'c';
		bool flag = false;
		istr >> h;
		istr >> c;
		istr >> m;
		if (c == ':') {
			if (h < 0 || m < 0)	flag = true;
			else m_min = (h * 60) + m;
		}
		else flag = true;
		if (flag == true) istr.setstate(ios::failbit);
		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		bool flag;
		int a;
		if (m_min < D.m_min) {
			flag = true;
			a = 1;
			while (flag == true) {
				if ((m_min + (60 * 24 * a) < D.m_min))
					a++;
				else
					flag = false;
			}
			m_min += (60 * 24 * a);
			m_min -= D.m_min;
		}
		else {
			m_min -= D.m_min;
		}
		return *this;
	}

	Time Time::operator-(const Time& D)const {
		Time A;
		bool flag;
		int a;
		if (m_min < D.m_min) {
			flag = true;
			a = 1;
			while (flag == true) {
				if ((m_min + (60 * 24 * a) < D.m_min))
					a++;
				else
					flag = false;
			}
			A.m_min = (m_min + (60 * 24 * a)) - D.m_min;
		}
		else {
			A.m_min = m_min - D.m_min;
		}
		return A;
	}

	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const {
		Time A;
		A.m_min = m_min + D.m_min;
		return A;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val) {
		m_min *= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const {
		Time A(this->m_min * val);
		return A;
	}

	Time& Time::operator /= (unsigned int val) {
		m_min /= val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const {
		Time A(this->m_min / val);
		return A;
	}

	Time::operator unsigned int()const {
		return m_min;
	}

	Time::operator int()const {
		return (int)m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D) {
		return D.read(istr);
	}
}