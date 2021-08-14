/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream> 
#include <iomanip>
#include <cstring>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            if (m_number > 0)
                cout << m_number;
            else cout << " NEW ";
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool()const {
        if (m_number != -1)
            return true;
        else
            return false;
    }

    Account::operator int()const {
        return m_number;
    }

    Account::operator double()const {
        return m_balance;
    }

    bool Account::operator ~()const {
        if (m_number == 0) 
            return true;
        else
            return false;
    }

    Account& Account::operator=(int num) {
        if(num < 10000 || num > 99999)
            setEmpty();
        else if (m_number == 0)
            m_number = num;
        
        return *this;
    }

    Account& Account::operator=(Account& newobj) {
        if (m_number != -1) {
            if (newobj.m_number > 9999 && newobj.m_number < 100000) {
                m_balance = newobj.m_balance;
                newobj.m_balance = 0.0;
                m_number = newobj.m_number;
                newobj.m_number = 0.0;
            }
        }
        return *this;
    }

    Account& Account::operator+=(double bal) {
        if (m_number > 9999 && m_number < 100000 && bal > 0 && m_balance > 0)
            m_balance += bal;
        return *this;
    }

    Account& Account::operator-=(double bal) {
        if (m_number > 9999 && m_number < 100000 && bal > 0 && m_balance >= bal)
            m_balance -= bal;
        return *this;
    }

    Account& Account::operator<<(Account& A) {
        if (this->m_number != A.m_number) {
            this->m_balance += A.m_balance;
            A.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& B) {
        if (this->m_number != B.m_number) {
            B.m_balance += this->m_balance;
            this->m_balance = 0.0;
        }
        return *this;
    }

    double Account::getBalance()const {
        return m_balance;
    }

    int Account::getNumber()const {
        return m_number;
    }

    double operator+(const Account& a1, const Account& a2) {
        double sum = 0.0;
        if (a1.getNumber() > 9999 && a1.getNumber() < 100000 && a2.getNumber() > 9999 && a2.getNumber() < 100000) {
            if(a1.getBalance() > 0 && a2.getBalance() > 0)
            sum = a1.getBalance() + a2.getBalance();
        }
        return sum;
    }

    double operator+=(double& a1, const Account& a2) {
        a1 += a2.getBalance();
        return a1;
    }

}