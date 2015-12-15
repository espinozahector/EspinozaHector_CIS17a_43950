/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#include <iostream>
#include "RetailItem.h"
using namespace std;

void RetailItem::set_info(string d){
    info=d;
}
void RetailItem::set_unit(int u){
    units=u;
}
void RetailItem::set_cost(float p){
    price=p;
}
RetailItem::RetailItem(string d,int u, float p){
    set_info(d);
    set_unit(u);
    set_cost(p);
}
void RetailItem::print(){
    cout<<"Description: "<<info<<endl;
    cout<<"Units:       "<<units<<endl;
    cout<<"Price:       "<<price<<endl<<endl;
}