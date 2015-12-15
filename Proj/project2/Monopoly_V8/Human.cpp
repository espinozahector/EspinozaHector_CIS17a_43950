/* 
 * File:   Human.cpp
 * Author: Hector Espinoza
 * Created on December 8, 2015, 3:57 PM
 */

#include "Human.h"

Human::Human() : Player(){
    bal = 1500;
    loc = 0;
    roll = 0;
    symbol = "P";
}
void Human::setmoney(int m){
    bal = m;
}
void Human::setloc(int l){
    loc = l;
}
void Human::setroll(int r){
    roll = r;
}
void Human::setsym(std::string s){
    symbol = s;
}


