/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/03/21
*/

#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>

namespace sdds {
	class Stats {
		double* m_numbers{ nullptr };
		char* m_filename{ nullptr };
		double m_empty = 0;
		unsigned m_accNum;
		unsigned m_columnWidth;
		unsigned m_noOfColumns;
		unsigned m_precision;
		void setFileName(const char* fname, bool isCopy = false);
		void setNoOfNums();
		void save(const char* fileName)const;
		void load();
		void setEmpty();
	public:
		Stats& operator=(const Stats& csvfile);
		double& operator[](unsigned idx);
		double operator[](unsigned idx)const;
		Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
		Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
		Stats(const Stats& csvfile);
		~Stats();
		operator bool()const;
		void sort(bool ascending);
		const char* name()const;
		unsigned size()const;
		unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
		std::ostream& view(std::ostream& ostr)const;
		std::istream& getFile(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& ostr, const Stats& file);
	std::istream& operator>>(std::istream& istr, Stats& file);
}
#endif // !SDDS_STATS_H__