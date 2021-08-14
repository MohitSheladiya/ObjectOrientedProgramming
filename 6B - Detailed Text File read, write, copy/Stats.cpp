/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Some parts of the functions here are taken from my LAB part because of the similarity between the two

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Stats.h"
#include <cstring>
using namespace std;

namespace sdds {

	void Stats::setEmpty() {
		m_accNum = 0;
		delete[] m_numbers;
		m_numbers = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}

	void Stats::setFileName(const char* fname, bool isCopy) {
		delete[] m_filename;
		m_filename = nullptr;
		if (isCopy != true) {
			m_filename = new char[strlen(fname) + 1];
			strcpy(m_filename, fname);
		}
		else {
			m_filename = new char[strlen(fname) + 3];
			strcpy(m_filename, "C_");
			strcat(m_filename, fname);
		}
	}

	void Stats::sort(bool ascending)
	{
		double a = 0.0;
		if (!ascending) {
			for (unsigned int i = 0; i < m_accNum; i++)
				for (unsigned int j = i + 1; j < m_accNum; j++)
					if (m_numbers[i] < m_numbers[j]) {
						a = m_numbers[i];
						m_numbers[i] = m_numbers[j];
						m_numbers[j] = a;
					}
		}
		else {
			for (unsigned int i = 0; i < m_accNum; i++)
				for (unsigned int j = i + 1; j < m_accNum; j++)
					if (m_numbers[i] > m_numbers[j]) {
						a = m_numbers[i];
						m_numbers[i] = m_numbers[j];
						m_numbers[j] = a;
					}
		}
	}

	void Stats::load() {
		int i = 0;
		if (m_filename != nullptr) {
			delete[] m_numbers;
			m_numbers = nullptr;
			m_numbers = new double[m_accNum];
			ifstream file;
			file.open(m_filename);
			while (file >> m_numbers[i]) {
				file.ignore(1000, ',');
				i++;
			}
			m_accNum = i;
			file.close();
		}
	}

	void Stats::save(const char* fileName) const {
		ofstream file;
		file.open(fileName);
		unsigned i = 0;
		int precision = 4;
		if (m_precision != 0) {
			precision = m_precision;
		}
		for (i = 0; i < m_accNum; i++) {
			if ((i + 1) < m_accNum) {
				file << fixed << setprecision(4) << m_numbers[i] << ",";
			} else {
				file << setprecision(precision) << m_numbers[i];
			}
		}
		file.close();
	}

	void Stats::setNoOfNums() {
		ifstream file;
		file.open(m_filename);
		if (file.is_open())	{
			string s;
			while (getline(file, s, ',')) m_accNum++;
		} else {
			setEmpty();
		}
	}

	std::ostream& Stats::view(std::ostream& ostr) const {
		if (m_filename != nullptr) {
			unsigned a = 0;
			unsigned i = 0;
			ostr << m_filename << endl;
			ostr << setw(strlen(name())) << setfill('=') << '=' << endl;
			ostr << endl;
			ostr << setfill(' ');
			while (a < m_accNum) {
				for (i = 0; i < m_noOfColumns && a < m_accNum; i++, a++) {
					ostr << fixed << setw(m_columnWidth) << setprecision(m_precision) << m_numbers[a];
				}
				ostr << endl;
			}
			ostr << "Total of " << a << " listed!" << endl;
		}
		return ostr;
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		m_filename = nullptr;
		m_numbers = nullptr;
		m_accNum = 0;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
	}

	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_accNum = 0;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		if (filename != nullptr) {
			setFileName(filename);
			setNoOfNums();
			load();
		}
	}

	Stats::Stats(const Stats& csvfile) {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_accNum = 0;
		m_columnWidth = csvfile.m_columnWidth;
		m_noOfColumns = csvfile.m_noOfColumns;
		m_precision = csvfile.m_precision;
		if (csvfile.m_filename != nullptr) {
			setFileName(csvfile.m_filename, true);
			csvfile.save(m_filename);
			setNoOfNums();
			load();
		}
	}

	Stats& Stats::operator=(const Stats& csvfile) {
		m_columnWidth = csvfile.m_columnWidth;
		m_noOfColumns = csvfile.m_noOfColumns;
		m_precision = csvfile.m_precision;
		if (csvfile.m_numbers != nullptr) {
			if (m_numbers != nullptr) {
				delete[] m_numbers;
				m_numbers = nullptr;
				csvfile.save(m_filename);
				setNoOfNums();
				load();
			}
		}
		return *this;
	}

	Stats::~Stats() {
		delete[] m_filename;
		delete[] m_numbers;
	}

	Stats::operator bool() const {
		bool flag = false;
		if (m_numbers != nullptr)
			flag = true;
		return flag;
	}

	const char* Stats::name() const {
		return m_filename;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
		int a1 = 0;
		unsigned a2 = 0;
		unsigned i = 0;
		if (m_filename != nullptr) {
			ostr << endl;
			while (i < m_accNum) {
				for (i = 0; i < m_accNum; i++) {
					if (m_numbers[i] <= max && m_numbers[i] >= min) {
						a1++;
						a2++;
						ostr << fixed << setw(m_columnWidth) << setprecision(m_precision) << m_numbers[i];
						if (a2 == m_noOfColumns) {
							ostr << endl;
							a2 = 0;
						}
					}
				}
				ostr << endl;
			}
			ostr << "Total of " << a1 << " numbers are between -12345 and 31343" << endl;
		}
		return a1;
	}

	double& Stats::operator[](unsigned idx) {
		double* a = &m_empty;
		if (*this)
			if (m_numbers != nullptr)
				a = &m_numbers[idx % m_accNum];
		return *a;
	}

	double Stats::operator[](unsigned idx) const {
		const double* a = &m_empty;
		if (*this)
			if (m_numbers != nullptr)
				a = &m_numbers[idx % m_accNum];
		return *a;
	}

	std::istream& Stats::getFile(std::istream& istr) {
		string s;
		istr >> s;
		setFileName(s.c_str());
		setNoOfNums();
		load();
		return istr;
	}

	unsigned Stats::size() const {
		return m_accNum;
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& file) {
		file.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Stats& file) {
		file.getFile(istr);
		return istr;
	}

}