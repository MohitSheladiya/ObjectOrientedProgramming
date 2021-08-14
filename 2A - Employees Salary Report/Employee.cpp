/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/01/27
*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {

    int noOfEmployees;
    Employee* employees;
                
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

   
    bool load(Employee& employee) {
        
        bool ok = false;
        char name[128];
        int length;     // This is defined to get the length of name by using the strLen function

        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {  // All the conditions are checked in order to processed 
            
            
            length = strLen(name) + 1;             // length has the length of the name and +1 means the index is increased by 1 because it starts with 0
            employee.m_name = new char[length];    // employee.m_name has been given new length so that the '\n' can come
            strCpy(employee.m_name, name);         // string name is copied to employee.m_name 
            
            ok = true;
        }

        return ok;
        
    }
     
     bool load() {

        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE)) {

            noOfEmployees = noOfRecords();            // noOfEmployees is given the value which is returned by the noOfRecords function i.e. 14
            employees = new Employee[noOfEmployees];


            for (i = 0; i < noOfEmployees; i++)  {    // this loop will run "noOfEmployees" which is total number of inputs in the file  
            
                if (load(employees[i]) == false) {   // condition is to be checked in the "if" statement (load function from above is going to be executed here) 
                    break;
                }
            }

            if (i + 1 < noOfEmployees) { // if condition is satisfied then the "if" statement is going to be processed 
                cout << "Error: incorrect number of records read; the data is possibly corrupted.";
            }
            else {
                ok = true;
            }

            closeFile(); // At last the file is closed 
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

  

     void display() {
         
         cout << "Employee Salary report, sorted by employee number" << endl;
         cout << "no- Empno, Name, Salary" << endl;
         cout << "------------------------------------------------" << endl;
         sort();   // Data that is inputed is been sorted by the function "sort"

         for (int i = 0; i < noOfEmployees; i++) { // this loop will run "noOfEmployees" which is total number of inputs in the file i.e. 14
             cout << i + 1 << "- ";
             display(employees[i]);   // display function gets executed here 
         }

     }

     void display(Employee& displayDetails) {
         
         cout << displayDetails.m_empNo << ": " << displayDetails.m_name << ", " << displayDetails.m_salary << endl;  // The output screen is going to have outputin the following sequence  
     
     }

    

    void deallocateMemory() {   // This function is used to delocate the memory address of "employees"
        delete[] employees;         
        employees = nullptr;
    }


}