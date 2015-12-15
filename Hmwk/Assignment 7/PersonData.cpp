/* 
 * File:   PersonData.cpp
 * Author: rcc
 * 
 * Created on December 3, 2015, 10:19 AM
 */

#include "PersonData.h"

PersonData::PersonData(){
    
}
PersonData::PersonData(string l, string f, string a, string c, string s, string z, string p){
    set_name(l,f);
    set_home(a,c,s,z);
    set_phone(p);
}
void PersonData::set_name(string l, string f){
    last = l;
    first = f;
}
void PersonData::set_home(string a, string c, string s, string z){
    city = c;
    state =address = a;
    city = c;
    state = s;
    zip = z;
}
void PersonData::set_phone(string p){
    phone = p;
}
void PersonData::getName(){
    cout<<last<<", "<<first;
}
void PersonData::print(){
    cout<<"********************************************\n\n";
    cout<<"Last Name: "<<last<<endl;
    cout<<"First Name: "<<first<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"State: "<<state<<endl;
    cout<<"Zip: "<<zip<<endl;
    cout<<"Phone Number: "<<phone<<endl;
}