/* 
 * File:   Computer.cpp
 * Author: rcc
 * 
 * Created on December 9, 2015, 2:03 PM
 */

#include "Computer.h"

Computer::Computer() : Player(){
    symbol = "C";
    bal = 1500;
    loc = 0;
    roll = 0;
}
void Computer::setmoney(int m){
    bal = m;
}
void Computer::setloc(int l){
    loc = l;
}
void Computer::setroll(int r){
    roll = r;
}
void Computer::setsym(std::string s){
    symbol = s;
}