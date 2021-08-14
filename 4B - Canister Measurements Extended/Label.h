/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/14
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds
{
    class Label
    {
        char* m_labelArg;
        char m_frameArg[9];
    public:
        void setFrameArg(const char* frameArg);
        void setName(const char* labelArg);
        void setToDefault();
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel() const;
    };
}
#endif