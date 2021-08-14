/* Citation and Sources...
Final Project Milestone
Module:	  Patient
Filename: Patient.h
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/29
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

using namespace std;
namespace sdds {
	class Patient : public IOAble {
		char* m_name = nullptr;
		int m_num = 0;
		Ticket m_ticket = 0;
		bool m_flag = false;
	public:
		Patient(int ticket, bool flag);
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool flag);
		bool operator==(char c)const;
		bool operator==(const Patient& P)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		ostream& csvWrite(ostream& os)const;
		istream& csvRead(istream& is);
		ostream& write(ostream& os)const;
		istream& read(istream& is);
	};
}
#endif