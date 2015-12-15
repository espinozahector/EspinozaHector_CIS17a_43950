/* 
 * File:   PersonData.h
 * Author: rcc
 * Created on December 3, 2015, 10:19 AM
 */

#ifndef PERSONDATA_H
#define	PERSONDATA_H


#include <iostream>
#include <string>
using namespace std;

class PersonData {
protected:
    string last;
    string first;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    void set_name(string,string);
    void set_home(string,string,string,string);
    void set_phone(string);
public: 
    PersonData();
    PersonData(string,string,string,string,string,string,string);
    void getName();
    void print();

};

#endif	/* PERSONDATA_H */

