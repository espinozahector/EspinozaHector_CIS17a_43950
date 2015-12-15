/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#include <bits/stdc++.h>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(int i,int q,float c){
    set_num(i);
    set_amnt(q);
    set_cost(c);
    set_ttl();
}
void Inventory::set_num(int i){
    while(i<1){
        cout<<"ERROR: Invalid Item Number. Input item number: ";
        cin>>i;
    }
    number=i;
}
void Inventory::set_amnt(int q){
    while(q<1){
        cout<<"ERROR: Invalid Quantity. Input quantity: ";
        cin>>q;
    }
    quantty=q;
}
void Inventory::set_cost(float c){
    while(c<1){
        cout<<"ERROR: Invalid cost. Input the cost: ";
        cin>>c;
    }
    cost=c;
}
void Inventory::set_ttl(){
    total=quantty*cost;
}
void Inventory::print(){
    cout<<fixed<<setprecision(2);
    cout<<"Item Number: "<<number<<endl;
    cout<<"Quantity:    "<<quantty<<endl;
    cout<<"Cost:       $"<<cost<<endl;
    cout<<"Total Cost: $"<<total<<endl;
}