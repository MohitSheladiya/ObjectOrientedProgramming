/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/01/27
*/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {

    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    
    void sort();
    bool load(Employee& employee);
    bool load();

    void display();
    void display(Employee& displayDetails);
  
    void deallocateMemory();

}
#endif // SDDS_EMPLOYEE_H_