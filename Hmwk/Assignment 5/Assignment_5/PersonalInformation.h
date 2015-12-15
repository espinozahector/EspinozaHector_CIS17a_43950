/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#ifndef PERSONALINFORMATION_H
#define	PERSONALINFORMATION_H

#include <bits/stdc++.h>
using namespace std;
class PersonalInformation {
    private:
        string name;
        string address;
        int age;
        string phone;
    public:
        void set_name(string);
        void set_add(string);
        void set_age(string);
        void set_phne(string);
        void print();
};

#endif	/* PERSONALINFORMATION_H */