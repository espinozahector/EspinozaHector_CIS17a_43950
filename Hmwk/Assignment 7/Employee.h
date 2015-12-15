/* 
 * File:   Employee.h
 * Author: rcc
 * Created on December 1, 2015, 12:46 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string number;
    string hire;
    void set_name(string);
    void set_number(string);
    void set_hireD(string);
public: 
    Employee();
    Employee(string,string,string);
    string getName()const;
    string getNum()const;
    string getDate()const;
    void print();
    

};

#endif	/* EMPLOYEE_H */

