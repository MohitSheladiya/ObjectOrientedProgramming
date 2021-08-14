#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream> 
/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/14
*/

#include <iomanip> 
#include <cstring>
#include "LabelMaker.h"

using namespace std;

namespace sdds
{

    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels > 0)
        {
            m_multiLabel = nullptr;
            m_noOfLabels = noOfLabels;
            m_multiLabel = new Label[m_noOfLabels];
        }
    }

    LabelMaker::~LabelMaker()
    {
        delete[] m_multiLabel;
        m_multiLabel = nullptr;
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            m_multiLabel[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_multiLabel[i].printLabel();
            cout << endl;
        }
    }

}