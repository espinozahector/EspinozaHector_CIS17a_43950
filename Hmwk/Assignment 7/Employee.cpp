/* 
 * File:   Employee.cpp
 * Author: rcc
 * Created on December 1, 2015, 12:46 PM
 */

#include "Employee.h"
#include <iostream>


void Employee::set_name(string n){
    bool valid;
    do{
        valid=true;
        if(n==""){
            valid=false;
        }
        if(!valid){
            cout<<"Input your name\n";
            cout<<"Name: ";
            getline(cin,n);
        }
    }while(!valid);
    name = n;
}
void Employee::set_number(string num){
    bool valid;
    do{
        valid=true;
        if(valid){
            for(int i=0;i<num.length();i++){
                if(!isdigit(num[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a number. Check to make sure they are all digits\n";
                    break;
                }
            }
        }
        if(!valid){
            cout<<"Input the Employee's number\n";
            cout<<"Number: ";
            getline(cin,num);
        }
    }while(!valid);

    number = num;
}
void Employee::set_hireD(string h){
    hire = h;
}
Employee::Employee(){
    name;
    number;
    hire;
}
Employee::Employee(string name,string number,string hire){
    set_name(name);
    set_number(number);
    set_hireD(hire);
}

string Employee::getName() const{
    return name;
}

string Employee::getNum() const{
    return number;
}

string Employee::getDate() const{
    return hire;
}
void Employee::print(){
    cout<<"Name: "<<name;
    cout<<"\nNumber: "<<number;
    cout<<"\nHire: "<<hire<<endl;
}