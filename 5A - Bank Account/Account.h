/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/16
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator ~()const;
        Account& operator=(int num);
        Account& operator=(Account& newobj);
        Account& operator+=(double bal);
        Account& operator-=(double bal);
        Account& operator<<(Account &A);
        Account& operator>>(Account &B);
        double getBalance()const;
        int getNumber()const;;

    };

    double operator+(const Account& a1, const Account& a2);
    double operator+=(double& a1, const Account& a2);

}
#endif // SDDS_ACCOUNT_H_