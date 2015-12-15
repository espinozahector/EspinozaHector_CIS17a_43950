/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 12, 2015M
 * Purpose: Assignment 6
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include "DayOfYear.h"
using namespace std;

void DayOfYear::set_day(string x){
    bool valid;
    int y;
    do{
        valid=true;
        for(int i=0;i<x.length();i++){
            if(!isdigit(x[i])){
                valid=false;
                cout<<"ERROR: Invalid input\n";
                break;
            }
        }
        if(valid){
            y=atoi(x.c_str());
            if(y<1 || y>365){
                valid=false;
                cout<<"ERROR: Invalid input\n";
            }
        }
        if(!valid){
            cout<<"Input any day of the year\n";
            getline(cin,x);
        }
    }while(!valid);
    day=y;
}
void DayOfYear::print(){
    int temp=day;
    cout<<"Day "<<day<<" would be ";
    if(day>=1 && day<=31){
        cout<<"January ";
        cout<<temp;
    }else if(day>31 && day<=59){
        cout<<"February ";
        cout<<temp-31;
    }else if(day>59 && day<=90){
        cout<<"March ";
        cout<<temp-59;
    }else if(day>90 && day<=120){
        cout<<"April ";
        cout<<temp-90;
    }else if(day>120 && day<=151){
        cout<<"May ";
        cout<<temp-120;
    }else if(day>151 && day<=181){
        cout<<"June ";
        cout<<temp-151;
    }else if(day>181 && day<=212){
        cout<<"July ";
        cout<<temp-181;
    }else if(day>212 && day<=243){
        cout<<"August ";
        cout<<temp-212;
    }else if(day>243 && day<=273){
        cout<<"September ";
        cout<<temp-243;
    }else if(day>273 && day<=304){
        cout<<"October ";
        cout<<temp-273;
    }else if(day>304 && day<=334){
        cout<<"November ";
        cout<<temp-304;
    }else if(day>334 && day<=365){
        cout<<"December ";
        cout<<temp-334;
    }else {cout<<"ERROR\n";}
}