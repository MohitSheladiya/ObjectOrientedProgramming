/* Citation and Sources...
Final Project Milestone
Module:	  PreTriage
Filename: PreTriage.cpp
Version 1.0
Author: Mohit Sheladiya
Student ID: 117979203
Date:   2021/04/05
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include "Menu.h"

using namespace std;
namespace sdds {

    PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage() {
        ofstream file;
        file.open(m_dataFilename);
        if (file.is_open()) {
            file << m_averCovidWait << ',' << m_averTriageWait << endl;
            cout << "Saving Average Wait Times,";
            cout << endl;
            cout << "   COVID Test: " << m_averCovidWait;
            cout << endl;
            cout << "   Triage: " << m_averTriageWait;
            cout << endl;
            cout << "Saving m_lineup...";
            for (int i = 0; i < m_lineupSize; i++) m_lineup[i]->csvWrite(file) << endl;
            for (int i = 0; i < m_lineupSize; i++) {
                cout << endl;
                cout << i + 1 << "- ";
                m_lineup[i]->csvWrite(cout);
            }
            file.close();
        }
        else cout << "Bad file, can't open" << endl;

        for (int i = 0; i < m_lineupSize; i++) delete m_lineup[i];
        delete[] m_dataFilename;
        cout << endl;
        cout << "done!" << endl;
    }

    void PreTriage::setAverageWaitTime(const Patient& p) {
        int ctime = getTime();
        int pttime = p.operator Time();
        if (p.type() == 'C') {
            int awtime = m_averCovidWait;
            m_averCovidWait = ((ctime - pttime) + (awtime * (p.number() - 1))) / p.number();
        }
        else if (p.type() == 'T') {
            int awtime = m_averTriageWait;
            m_averTriageWait = ((ctime - pttime) + (awtime * (p.number() - 1))) / p.number();
        }
    }

    const Time PreTriage::getWaitTime(const Patient& p) const {
        int a = 0;
        for (int i = 0; i < m_lineupSize; i++)
            if (m_lineup[i]->type() == p.type())
                a++;
        return Time(p) *= a;
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        int a = -1;
        for (int i = 0; i < maxNoOfPatients; i++)
            if (m_lineup[i]->type() == type) {
                a = i;
                i = maxNoOfPatients;
            }
        return a;
    }

    void PreTriage::removePatientFromLineup(int index) { removeDynamicElement(m_lineup, index, m_lineupSize); }

    void PreTriage::load() {
        string s;
        char c;
        ifstream file;
        file.open(m_dataFilename);
        cout << "Loading data..." << endl;
        if (file.is_open()) {
            getline(file, s, '\n');
            stringstream a(s);
            a >> m_averCovidWait >> c >> m_averTriageWait;
            a.ignore('\n');
            for (int i = 0; i < maxNoOfPatients; i++) {
                Patient* p = nullptr;
                if (file.fail() == false || file.eof() == false) {
                    getline(file, s, ',');
                    if (strcmp(s.c_str(), "C") == false) p = new CovidPatient();
                    else if (strcmp(s.c_str(), "T") == false) p = new TriagePatient();
                    if (p != nullptr) {
                        p->fileIO(true);
                        p->read(file);
                        p->fileIO(false);
                        m_lineup[i] = p;
                        m_lineupSize++;
                    }
                }
                else i = maxNoOfPatients;
            }
            int num = 0;
            while (getline(file, s, ',')) num++;

            if (num > 0) cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;

            if (m_lineupSize > 0) cout << m_lineupSize << " Records imported..." << endl << endl;
            else cout << "No data or bad data file!" << endl << endl;
            file.close();
        }
        else cout << "Error File Not Loading";
    }

    void PreTriage::admit() {
        int a;
        int i = 0;
        char c = 'a';
        m_pMenu >> a;
        switch (a) {
        case 0:
            break;
        case 1:
            c = 'C';
            if (indexOfFirstInLine(c) != -1) {
                i = indexOfFirstInLine(c);
                cout << '\n' << "******************************************" << endl;
                m_lineup[i]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(c)];
                cout << "******************************************";
                cout << endl << endl;
                setAverageWaitTime(*m_lineup[i]);
                removePatientFromLineup(i);
            }
            break;
        case 2:
            c = 'T';
            if (indexOfFirstInLine(c) != -1) {
                i = indexOfFirstInLine(c);
                cout << '\n' << "******************************************" << endl;
                m_lineup[i]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(c)];
                cout << "******************************************";
                cout << endl << endl;
                setAverageWaitTime(*m_lineup[i]);
                removePatientFromLineup(i);
            }
            break;
        }
    }

    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients) cout << "Line up full!" << endl;
        else {
            int a;
            m_pMenu >> a;
            switch (a) {
            case 0:
                break;
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                cin >> *m_lineup[m_lineupSize];
                cout << '\n' << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************";
                cout << endl << endl;
                m_lineupSize++;
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                cin >> *m_lineup[m_lineupSize];
                cout << '\n' << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************";
                cout << endl << endl;
                m_lineupSize++;
                break;
            }
        }
    }

    void PreTriage::run(void) {
        int a;
        bool flag = true;
        do {
            m_appMenu >> a;
            switch (a) {
            case 0:
                flag = false;
                break;
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            }
        } while (flag);
    }
}