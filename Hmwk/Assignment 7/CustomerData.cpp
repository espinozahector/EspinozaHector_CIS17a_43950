/* 
 * File:   CustomerData.cpp
 * Author: rcc
 * Created on December 3, 2015, 10:44 AM
 */

#include "CustomerData.h"

CustomerData::CustomerData() : PersonData(){
    custNum = 0;
    mail = false;
}
CustomerData::CustomerData(string l, string f, string a, string c, string s, string z, string p, int num, bool mai) : PersonData(l,f,a,c,s,z,p){
    set_num(num);
    set_mail(mai);
}
void CustomerData::set_num(int num){
    custNum = num;
}
void CustomerData::set_mail(bool mai){
    mail = mai;
}
void CustomerData::display(){
    cout<<"The customer's Number is "<<custNum<<endl;
    if(mail == true){
        cout<<"The customer wishes to be on a mailing list\n";
    }else if(mail == false){
        cout<<"The customer does not wish to be on a mailing list\n";
    }
}