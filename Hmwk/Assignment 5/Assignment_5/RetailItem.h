/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#ifndef RETAILITEM_H
#define	RETAILITEM_H

using namespace std;

class RetailItem {
    private:
        string info;
        int units;
        float price;
        void set_info(string);
        void set_unit(int);
        void set_cost(float);
    public:
        RetailItem(string,int,float);
        void print();
};

#endif	/* RETAILITEM_H */

