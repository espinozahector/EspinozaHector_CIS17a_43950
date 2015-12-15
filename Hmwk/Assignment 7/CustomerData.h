/* 
 * File:   CustomerData.h
 * Author: rcc
 *
 * Created on December 3, 2015, 10:44 AM
 */

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData{
private:
    int custNum;//customerNumber
    bool mail; //mailingList
    void set_num(int);
    void set_mail(bool);
public:
    CustomerData();
    CustomerData(string,string,string,string,string,string,string,int,bool);
    void display();
    
};

#endif	/* CUSTOMERDATA_H */
