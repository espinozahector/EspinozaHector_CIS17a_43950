/* 
 * File:   NumDays.cpp
 * Author: rcc
 * Created on November 19, 2015, 3:37 PM
 */

#include "NumDays.h"
#include <iostream>
using namespace std;

NumDays NumDays::operator -(const NumDays& a){
    if(hours<a.hours){
        cout<<"The difference of the two objects’ hours members is "<<a.hours-hours<<endl;
    }
    else if(a.hours<hours){
        cout<<"The difference of the two objects’ hours members is "<<hours-a.hours<<endl;
    }
    else {
        cout<<"The difference of the two objects’ hours members is "<<hours-a.hours<<endl;
    }
    return *this;
}
NumDays NumDays::operator +(const NumDays& a){
    float total=0;
    total=hours +a.hours;
    
    cout<<"The sum of the two objects’ hours members is "<<total<<endl;
    return *this;
}
NumDays NumDays::operator --(int){
    float temp;
    do{
        cout<<"Input the new number of hours worked\n";
        cin>>temp;
        if(temp>hours){
            cout<<"ERROR: Input must be less than "<<hours<<endl;
        }
    }while(temp>hours);
    hours=temp;
    return *this;
}
NumDays NumDays::operator ++(int){
    float temp;
    do{
        cout<<"Input the new number of hours worked\n";
        cin>>temp;
        if(temp<hours){
            cout<<"ERROR: Input must be larger than "<<hours<<endl;
        }
    }while(temp<hours);
    hours=temp;
    return *this;
}
NumDays::NumDays(float x){
    set_hours(x);
}
void NumDays::set_hours(float x){
    bool valid=true;
    do{
        valid=true;
        if(valid){
            if(x<1){
                cout<<"ERROR: Hours can not be less than 1\n";
                valid=false;
            }
        }
        if(!valid){
            cout<<"Input the number of hours\nhours: ";
            cin>>x;
        }
    }while(!valid);
    
    hours=x;
}
void NumDays::print(){
    days = hours/8;
    cout<<"Hours: "<<hours<<endl;
    cout<<"Days:  "<<days<<endl;
}



