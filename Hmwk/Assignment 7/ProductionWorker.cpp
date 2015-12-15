/* 
 * File:   ProductionWorker.cpp
 * Author: rcc
 * Created on December 1, 2015, 1:56 PM
 */

#include "ProductionWorker.h"
#include <iostream>
#include <iomanip>
using namespace std;

ProductionWorker::ProductionWorker() : Employee(){
    shift =0;
    rate=0.0f;
}
ProductionWorker::ProductionWorker(string n, string num, string d,int s, float r) : Employee(n,num,d){
    set_shift(s);
    set_rate(r);

}
void ProductionWorker::set_rate(float r){
    bool valid;
    do{
        valid=true;
        if(r<0){
            cout<<"ERROR: Rate can't be less than 0\n";
            valid=false;
        }
        if(!valid){
            cout<<"Input the Hourly Pay Rate\n";
            cout<<"Pay Rate: ";
            cin>>r;
        }
    }while(!valid);
    rate=r;
}
void ProductionWorker::set_shift(int s){
    bool valid;
    do{
        valid=true;
        if(s !=1 && s!=2){
            cout<<"ERROR: Shift must be 1 or 2\n";
            valid=false;
        }
        if(!valid){
            cout<<"Input the shift 1. Day 2. Night\n";
            cout<<"Shift: ";
            cin>>s;
        }
    }while(!valid);
    shift = s;
}
void ProductionWorker::display(){
    cout<<"Shift: ";
    switch(shift){
        case 1:{
            cout<<"Day Shift\n";
            break;
        }
        case 2:{
            cout<<"Night Shift\n";
            break;
        }
        default:{
            cout<<"Bad switch statement\n";
            break;
        }
    }
    cout<< fixed << setprecision(2);
    cout<<"Hourly Pay Rate: "<<rate<<endl;
}