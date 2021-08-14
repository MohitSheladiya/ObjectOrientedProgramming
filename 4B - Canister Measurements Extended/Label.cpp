/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream> 
#include <iomanip>
#include <cstring>
#include "Label.h"

using namespace std;

namespace sdds
{

    void Label::setFrameArg(const char* frameArg)
    {
        strcpy(m_frameArg, frameArg);
        m_frameArg[8] = '\0';
    }

    void Label::setName(const char* labelArg)
    {
        m_labelArg = nullptr;
        m_labelArg = new char[strlen(labelArg) + 1];
        strcpy(m_labelArg, labelArg);
    }

    void Label::setToDefault()
    {
        m_labelArg = nullptr;
        m_frameArg[0] = '\0';
    }

    Label::Label()
    {
        setToDefault();
        setFrameArg("+-+|+-+|");
    }

    Label::Label(const char* frameArg)
    {
        setToDefault();
        setFrameArg(frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        setToDefault();
        setName(content);
        setFrameArg(frameArg);
    }

    Label::~Label()
    {
        delete[] m_labelArg;
        m_labelArg = nullptr;
    }

    void Label::readLabel()
    {
        char readlabel[71];
        cin.getline(readlabel, 71);
        setName(readlabel);
    }

    std::ostream& Label::printLabel() const
    {
        /*
        if (m_labelArg != nullptr) {
            int c = 0;
            while (m_labelArg[c] != '\0') {
                c++;
            }
            c = c + 3;
            cout << m_frameArg[0] << setw(c) << setfill(m_frameArg[1]);
            cout << m_frameArg[2] << endl;
            cout << m_frameArg[7] << setw(c) << setfill(' ');
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[7] << ' ' << m_labelArg << ' ';
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[7] << setw(c) << setfill(' ');
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[6] << setw(c) << setfill(m_frameArg[5]);
            cout << m_frameArg[4] << endl;
        } */
        int l = 0;

        if (m_labelArg != '\0')
        {
            l = strlen(m_labelArg);

            cout << m_frameArg[0];
            for (int i = 0; i < l + 2; i++)
            {
                cout << m_frameArg[1];
            }
            cout << m_frameArg[2] << endl;
            cout << m_frameArg[7];
            for (int i = 0; i < l + 2; i++)
            {
                cout << " ";
            }
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[7] << " ";
            cout << m_labelArg << " ";
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[7];
            for (int i = 0; i < l + 2; i++)
            {
                cout << " ";
            }
            cout << m_frameArg[3] << endl;
            cout << m_frameArg[6];
            for (int i = 0; i < l + 2; i++)
            {
                cout << m_frameArg[5];
            }
            cout << m_frameArg[4];
        }
        return cout;
    }
}