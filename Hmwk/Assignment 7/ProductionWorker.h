/* 
 * File:   ProductionWorker.h
 * Author: rcc
 * Created on December 1, 2015, 1:56 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker : public Employee {
private:
    int shift;
    float rate;
    void set_shift(int);
    void set_rate(float);
public:
    ProductionWorker();
    ProductionWorker(string,string,string,int,float);
    int getshift()const {return shift;}
    float getrate()const {return rate;}
    void display();

};

#endif	/* PRODUCTIONWORKER_H */

