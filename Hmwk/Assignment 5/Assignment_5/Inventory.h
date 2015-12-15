/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

using namespace std;

class Inventory {
private:
    int number;
    int quantty;
    float cost;
    float total;
public:
    Inventory();
    Inventory(int,int,float);
    void set_num(int);
    void set_amnt(int);
    void set_cost(float);
    void set_ttl();
    void print();
};

#endif	/* INVENTORY_H */

