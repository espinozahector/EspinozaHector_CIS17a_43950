/* 
 * File:   ShiftSupervisor.cpp
 * Author: rcc
 * Created on December 3, 2015, 9:52 AM
 */

#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include <iostream>
using namespace std;

ShiftSupervisor::ShiftSupervisor() : ProductionWorker(){
    annual = 0.0f;
    bonus = 0.0f;
}
ShiftSupervisor::ShiftSupervisor(string n, string num, string d, int s, 
                                 float r, float an, float bon) 
                                 : ProductionWorker(n,num,d,s,r){
    set_annual(an);
    set_bonus(bon);
}
void ShiftSupervisor::set_annual(float a){
    bool valid;
    do{
        valid=true;
        if(a<0){
            cout<<"ERROR: Annual can't be less than 0\n";
            valid=false;
        }
        if(!valid){
            cout<<"Input the Supervisor's annual Salary\n";
            cout<<"Salary: ";
            cin>>a;
        }
    }while(!valid);
    annual = a;
}
void ShiftSupervisor::set_bonus(float b){
    bool valid;
    do{
        valid=true;
        if(b<0){
            cout<<"ERROR: Bonus can't be less than 0\n";
            valid=false;
        }
        if(!valid){
            cout<<"Input the Supervisor's annual production bonus\n";
            cout<<"Bonus: ";
            cin>>b;
        }
    }while(!valid);
    bonus = b;
}
void ShiftSupervisor::printS(){
    cout<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Supervisor's annual Salary: $"<<annual<<endl;
    cout<<"Supervisor's annual Bonus: $"<<bonus<<endl;
}
    
    
