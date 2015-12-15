/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#include "Date.h"
#include <iostream>
using namespace std;

void Date::set_day(int x){
    day=x;
}
void Date::set_month(int y){
    month=y;
}
void Date::set_year(int z){
    year=z;
}
void Date::display(){
    string month2;
        switch(month){
        case 1:{
            month2="January";
            break;
        }
        case 2:{
            month2="February";
            break;
        }
        case 3:{
            month2="March";
            break;
        }
        case 4:{
            month2="April";
            break;
        }
        case 5:{
            month2="May";
            break;
        }
        case 6:{
            month2="June";
            break;
        }
        case 7:{
            month2="July";
            break;
        }
        case 8:{
            month2="August";
            break;
        }
        case 9:{
            month2="September";
            break;
        }
        case 10:{
            month2="October";
            break;
        }
        case 11:{
            month2="November";
            break;
        }
        case 12:{
            month2="December";
            break;
        }
        default: {cout<<"ERROR: In the switch statment\n";}
    }
    cout<<month<<"/"<<day<<"/"<<year<<endl;
    cout<<month2<<" "<<day<<", "<<year<<endl;
    cout<<day<<" "<<month2<<" "<<year<<endl;
}
