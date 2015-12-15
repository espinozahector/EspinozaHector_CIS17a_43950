/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 12, 2015M
 * Purpose: Assignment 6
 */

#ifndef DAYOFYEAR2_H
#define	DAYOFYEAR2_H

class DayOfYear2 {
private:
    int day;
    std::string month;
    int cMonth;
    void set_day(std::string,std::string);
    int dPerMth[12];
    std::string Months[12];
public:
    void modify();
    DayOfYear2(std::string,std::string);
    DayOfYear2 operator++(int);
    DayOfYear2 operator--(int);
    void print();
};

#endif	/* DAYOFYEAR_H */

