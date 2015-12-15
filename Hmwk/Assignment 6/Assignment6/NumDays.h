/* 
 * File:   NumDays.h
 * Author: rcc
 * Created on November 19, 2015, 3:37 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
private:
    float hours;
    float days;
    void set_hours(float);
public:
    NumDays(float);
    void print();
    NumDays operator++(int);
    NumDays operator--(int);
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);
//    NumDays operator+(int);
//    NumDays operator-(int);

};

#endif	/* NUMDAYS_H */

