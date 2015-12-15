/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

#include <bits/stdc++.h>
#include "PersonalInformation.h"
using namespace std;


void PersonalInformation::set_name(string n) {
    name=n;
}
void PersonalInformation::set_add(string a){
    address=a;
}
void PersonalInformation::set_age(string ag){
    bool valid;
    int temp;
    do{
        valid=true;
        for(int i=0;i<ag.length();i++){
            if(!isdigit(ag[i]))valid=false;
        }
        if(valid){
            temp=atoi(ag.c_str());
            valid = temp>0;
        }
        if(!valid){
            cout<<"Invalid age! Re-enter age: ";
            getline(cin, ag);
        }
    }while(!valid);
    age=temp;
}

void PersonalInformation::set_phne(string p){
    bool valid;
    do{
        valid=true;
        for(int i=0;i<p.length();i++){
            if(!isdigit(p[i]))valid=false;
        }
        if(p.length()!=10)valid=false;
        if(!valid){
            cout<<"ERROR: Invalid phone number!Re-enter phone number: ";
            getline(cin,p);
        }
    }while(!valid);
    phone=p;
}

void PersonalInformation::print(){
    cout<<"Personal Data: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Phone: "<<phone<<endl;
}