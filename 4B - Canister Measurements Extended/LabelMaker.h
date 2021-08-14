/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/14
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds {
    class LabelMaker {
        int m_noOfLabels;
        Label* m_multiLabel;
    public:
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels();
    };
}
#endif