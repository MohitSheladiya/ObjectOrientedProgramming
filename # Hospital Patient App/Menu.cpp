/* Citation and Sources...
Final Project Milestone 2
Module:	  Menu
Filename: Menu.cpp
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/21
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
#include "Menu.h"
#include "IOAble.h"
using namespace std;
namespace sdds {

    Menu::Menu(const char* MenuContent, int NoOfSelections) {
        m_noOfSel = NoOfSelections;
        m_text = nullptr;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
    }

    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }

    int& Menu::operator>>(int& Selection) {
        int a;
        bool flag = false;
        display();
        while (!flag) {
            cin >> a;
            if (a <= m_noOfSel && a >= 0) {
                Selection = a;
                flag = true;
            }
            else {
                cout << "Invalid option [0 <= value <= 3]: ";
            }
            if (cin.fail() == true) {
                flag = false;
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "Bad integer value, try again: ";
            }
        }
        return Selection;
    }

    void Menu::display()const {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
        cout << "> ";
    }

}