/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#ifndef DATE_H
#define	DATE_H

class Date {
        int day,month,year;
        
    public:
        void set_day(int);
        void set_month(int);
        void set_year(int);
        void display();
};

#endif	/* DATE_H */

