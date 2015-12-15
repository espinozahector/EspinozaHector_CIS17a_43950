/* 
 * File:   PreferredCustomer.cpp
 * Author: rcc
 * Created on December 3, 2015, 1:09 PM
 */

#include "PreferredCustomer.h"
#include <iomanip>

PreferredCustomer::PreferredCustomer(){
    buy=0.0f;
    disc=0.0f;
}
PreferredCustomer::PreferredCustomer
(string l, string f, string a, string c, string s, string z, string p, 
        int num, bool mai, float by) : CustomerData(l,f,a,c,s,z,p,num,mai){
    set_values(by);
}
void PreferredCustomer::set_values(float by){
    buy = by;
    if(buy>=500){
        disc=.05;
    }
    if(buy>=1000){
        disc=.06;
    }
    if(buy>=1500){
        disc=.07;
    }
    if(buy>=2000){
        disc=.1;
    }
}
void PreferredCustomer::printing(){
    cout<<fixed<<setprecision(2);
    cout<<"The Customer spent: $"<<buy<<endl;
    cout<<"The customer now gets a "<<disc<<" discount on all future purchases."<<endl;
}