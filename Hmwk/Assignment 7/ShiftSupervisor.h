/* 
 * File:   ShiftSupervisor.h
 * Author: rcc
 *
 * Created on December 3, 2015, 9:52 AM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H
#include "ProductionWorker.h"

class ShiftSupervisor : public ProductionWorker{
private:
    float annual;
    float bonus;
    void set_annual(float);
    void set_bonus(float);
public:
    ShiftSupervisor();
    ShiftSupervisor(string,string,string,int,float,float,float);
    float getAnnual()const { return annual;}
    float getBonus()const { return bonus;}
    void printS();

};

#endif	/* SHIFTSUPERVISOR_H */

