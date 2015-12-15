/* 
 * File:   PreferredCustomer.h
 * Author: rcc
 * Created on December 3, 2015, 1:09 PM
 */

#ifndef PREFERREDCUSTOMER_H
#define	PREFERREDCUSTOMER_H
#include "CustomerData.h"

class PreferredCustomer : public CustomerData{
private:
    float buy;//purchasesAmount
    float disc;//discountLevel
    void set_values(float);
public:
    PreferredCustomer();
    PreferredCustomer(string,string,string,string,string,string,string,int,bool,float);
    void printing();

};

#endif	/* PREFERREDCUSTOMER_H */

