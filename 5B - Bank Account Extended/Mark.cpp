/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/21
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream> 
#include <iomanip>
#include <cstring>
#include "Mark.h"

using namespace std;

namespace sdds {
	
	Mark::Mark() {
		m_number = 0;
	}
	
	Mark::Mark(int num) {
		m_number = 0;
		if (int(num)) {
			m_number = num;
		}
	}

	Mark::operator int(){
		int num = 0;
		if (m_number <= 100 && m_number >= 0) {
			num = m_number;
		}
		return num;
	}

	Mark::operator double(){
		int num = 0;
		if (int(*this)) {
			if (m_number >= 0 && m_number < 50) {
				num = 0;
			}
			else if (m_number >= 50 && m_number < 60) {
				num = 1;
			}
			else if (m_number >= 60 && m_number < 70) {
				num = 2;
			}
			else if (m_number >= 70 && m_number < 80) {
				num = 3;
			}
			else if (m_number >= 80 && m_number <= 100) {
				num = 4;
			}
			else num = 0;
		}
		return num;
	}
	 
	Mark::operator char(){
		char grade;
		if (m_number >= 0 && m_number < 50) {
			grade = 'F';
		}
		else if (m_number >= 50 && m_number < 60) {
			grade = 'D';
		}
		else if (m_number >= 60 && m_number < 70) {
			grade = 'C';
		}
		else if (m_number >= 70 && m_number < 80) {
			grade = 'B';
		}
		else if (m_number >= 80 && m_number <= 100) {
			grade = 'A';
		}
		else grade = 'X';
		return grade;
	}

	int Mark::operator=(int& num) {
		if (int(num)) {
			m_number = num;
		}
		return m_number;
	}

	int Mark::operator+=(int num) {
		if (int(num)) {
			m_number += num;
		}
		return *this;
	}

	int operator+=(int& num, Mark& A) {
		if (int(A.m_number)) {
			num += A.Mark::operator int();
		}
		return num;
	}
}