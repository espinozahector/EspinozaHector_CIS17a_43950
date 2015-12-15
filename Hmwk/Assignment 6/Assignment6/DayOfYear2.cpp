/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 12, 2015M
 * Purpose: Assignment 6
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "DayOfYear2.h"
using namespace std;
DayOfYear2 DayOfYear2::operator++(int){
    day++;
    if(day>dPerMth[cMonth]){
        day=1;
        cMonth++;
        if(cMonth>11){
            cMonth=0;
            day=dPerMth[cMonth];
        }
    }
    return *this;
}
DayOfYear2 DayOfYear2::operator--(int){
    day--;
    if(day<dPerMth[cMonth]){
        cMonth--;
        day=dPerMth[cMonth];
        if(cMonth<1){ 
            cMonth=11;
            day=dPerMth[cMonth];
        }
    }
    return *this;
}
DayOfYear2::DayOfYear2(std::string d, std::string m){
    int temp2[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string temp[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(int i=0;i<12;i++){
        Months[i]=temp[i];
        dPerMth[i]=temp2[i];
    }
    set_day(d,m);
}
void DayOfYear2::modify(){
    int answ;
    cout<<"1. Add a day\n2. Subtract a day\n";
    cout<<"Input your choice\n";
    cin>>answ;
    switch (answ){
        case 1: {
            day++;
            if(day>dPerMth[cMonth]){
                day=1;
                cMonth++;
                if(cMonth>11){
                    day=dPerMth[cMonth];
                    cMonth=0;
                }
            }
            break;
        }
        case 2: {
            day++;
            if(day<dPerMth[cMonth]){
                day=1;
                cMonth++;
                if(cMonth>11){
                    day=dPerMth[cMonth];
                    cMonth=0;
                }
            }
            break;
        }
        default: {
            cout<<"Error: In the switch statment\n";
            break;
        }
    }
}
void DayOfYear2::set_day(std::string d,std::string m){
    bool valid;
    int mDay;
    do{
        valid=true;
        if(m!="January" && m!="February" && m!="March" && m!="April" 
           && m!="May" && m!="June" && m!="July" && m!="August" && m!="September" 
           && m!="October" && m!="November" && m!="December"){
            valid=false;
            cout<"ERROR: You did not enter a valid month. Check for spelling and Capitalization\n";
        }
        if(valid){
            for(int i=0;i<d.length();i++){
                if(!isdigit(d[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day. Check to make sure they are all digits\n";
                    break;
                }
            }
        }
        if(valid){
            mDay=atoi(d.c_str());
            if(m=="January"){
                if(mDay<1 || mDay>dPerMth[0]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=0;
            }else if(m=="February"){
                if(mDay<1 || mDay>dPerMth[1]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=1;
            }else if(m=="March"){
                if(mDay<1 || mDay>dPerMth[2]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=2;
            }else if(m=="April"){
                if(mDay<1 || mDay>dPerMth[3]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=3;
            }else if(m=="May"){
                if(mDay<1 || mDay>dPerMth[4]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=4;
            }else if(m=="June"){
                if(mDay<1 || mDay>dPerMth[5]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=5;
            }else if(m=="July"){
                if(mDay<1 || mDay>dPerMth[6]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=6;
            }else if(m=="August"){
                if(mDay<1 || mDay>dPerMth[7]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=7;
            }else if(m=="September"){
                if(mDay<1 || mDay>dPerMth[8]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=8;
            }else if(m=="October"){
                if(mDay<1 || mDay>dPerMth[9]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=9;
            }else if(m=="November"){
                if(mDay<1 || mDay>dPerMth[10]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=10;
            }else if(m=="December"){
                if(mDay<1 || mDay>dPerMth[11]){
                    valid=false;
                    cout<<"ERROR: You did not enter a valid day\n";
                }else cMonth=11;
            }
        }
        if(!valid){
            cout<<"Input month and day\n";
            cout<<"Month: ";
            getline(cin,m);
            cout<<"Day: ";
            getline(cin,d);
        }
    }while(!valid);
    month=m;
    day=mDay;
}
void DayOfYear2::print(){
    cout<<"Your month is "<<Months[cMonth]<<" "<<day<<endl;
}