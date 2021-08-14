/* Citation and Sources...
Final Project Milestone
Module:	  utils
Filename: utils.cpp
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/03/17
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
#include "IOAble.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(
        const char* prompt   // User entry prompt
    ) {
        int a;
        bool flag = false;
        if (prompt) {
            cout << prompt;
        }
        while (flag != true) {
            cin >> a;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(3000, '\n');
                cout << "Bad integer value, try again: ";
            }
            else if (char(cin.get()) != '\n') {
                cout << "Enter only an integer, try again: ";
                cin.ignore(2000, '\n');
            }
            else flag = true;
        }
        return a;
    }

    int getInt(
        int min,   // minimum acceptable value
        int max,   // maximum acceptable value
        const char* prompt,  // User entry prompt
        const char* errorMessage, // Invalid value error message
        bool showRangeAtError    // display the range if invalud value entered 
    ) {
        int a;
        a = getInt(prompt);
        while (a > max || a < min) {
            if (errorMessage) {
                cout << errorMessage;
            }
            if (showRangeAtError) {
                cout << "[" << min << " <= value <= " << max << "]" << ": ";
            }
            a = getInt();
        }
        return a;
    }

    char* getcstr(
        const char* prompt,   // User entry prompt
        std::istream& istr,  // the Stream to read from
        char delimiter   // Delimiter to mark the end of data
    ) {
        char* c = nullptr;
        string s;
        if (prompt != nullptr) {
            cout << prompt;
            getline(istr, s, delimiter);
            c = new char[s.length() + 1];
            strcpy(c, s.c_str());
        }
        return c;
    }

}