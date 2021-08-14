/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/02/05
*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {
    class Item {
        char m_itemName[31];
        int m_cal;
        int m_meal;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int cal, int meal);
        void display()const;
        bool isValid()const;
        int cal()const;
    };
}
#endif
