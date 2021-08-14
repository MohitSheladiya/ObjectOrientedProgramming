/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          11/03/21
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;

namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[]m_textLines;
        m_textLines = nullptr;
        delete[]m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        m_filename = nullptr;
        if (isCopy != true) {
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
        else {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        string s;
        int i = 0;
        ifstream file;
        file.open(name());
        if (file.is_open() == true) {
            while (getline(file, s, '\n')) i++;
            if (i == 0)
                m_filename = nullptr;
            else 
                m_noOfLines = i++;
        }
        file.close();
    }

    void TextFile::loadText() {
        string s;
        int i = 0;
        if (m_filename != nullptr) {
            ifstream file;
            m_textLines = new Line[m_noOfLines];
            file.open(m_filename);
            if (file.is_open() == true) 
                while (getline(file, s)) {
                    m_textLines[i] = s.c_str();
                    i++;
                }
            m_noOfLines = i;
            file.close();
        }
    }

    void TextFile::saveAs(const char* fileName)const {
        ofstream file;
        file.open(fileName);
        if (file.is_open() == true) 
            for (unsigned i = 0; i < m_noOfLines; i++) 
                file << m_textLines[i] << endl;
        file.close();
    }

    TextFile::TextFile(unsigned pageSize) {
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_filename = nullptr;
        m_pageSize = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = 0;
        m_pageSize = pageSize;
        if (filename != nullptr) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& txtfile) {
        m_noOfLines = 0; 
        m_textLines = nullptr;
        m_filename = nullptr;
        m_pageSize = txtfile.m_pageSize;
        if (txtfile.m_filename != nullptr) {
            setFilename(txtfile.m_filename, true);
            txtfile.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& txtfile) {
        if (txtfile.m_textLines != nullptr) {
            if (m_textLines != nullptr) {
                delete[]m_textLines;
                m_textLines = nullptr;
                txtfile.saveAs(name());
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
    }

    std::ostream& TextFile::view(std::ostream& ostr)const {
        if (m_filename != nullptr) {
            if (m_noOfLines > 0) {
                unsigned a = 0;
                ostr << m_filename << endl;
                for (unsigned i = 0; i < strlen(m_filename); i++) {
                    ostr << '=';
                }
                ostr << endl;
                for (unsigned i = 0; i < m_noOfLines; i++) {
                    if (a == m_pageSize) {
                        a = 0;
                        ostr << "Hit ENTER to continue...";
                        cin.ignore();
                    }
                    ostr << m_textLines[i].m_value << endl;
                    a++;
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string s;
        istr >> s;
        cin.ignore();
        setFilename(s.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile::operator bool()const {
        bool flag = false;
        if (m_filename != nullptr) flag = true;
        return flag;
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    const char* TextFile::operator[](unsigned index)const {
        const char* a = nullptr;
        if (*this) a = m_textLines[index % m_noOfLines];
        return a;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }

}