/* 
 * File:   House.cpp
 * Author: rcc
 * 
 * Created on October 13, 2015, 1:08 PM
 */
#include <iostream>
using namespace std;

#include "House.h"

 void House::setName(string n){
     name=n;
 }
 void House::setBuy(int b){
     buy=b;
 }
 void House::setRent(int r){
     rent=r;
 }
 string House::getName() const{
     return name;
 }
 int House::getBuy() const{
     return buy;
 }
 int House::getRent() const{
     return rent;
 }
 void House::print(){
     cout<<"Name: "<<name<<endl;
     cout<<"Cost: "<<buy<<endl;
     cout<<"Rent: "<<rent<<endl;
 }


