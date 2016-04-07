/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 12, 2015M
 * Purpose: Assignment 6
 */

#include <iostream>
#include "Numbers.h"
using namespace std;


void Numbers::set_number(int x){
    bool valid;
    do{
        valid=true;
        if(x<0 || x>9999){
            valid=false;
            cout<<"ERROR: Invalid input\n";
            cout<<"Input any number\n";
            cin>>x;
            cin.ignore();
        }
    }while(!valid);
    number=x;
}
void Numbers::Display(){
    int temp=number;
    string worded;
    
    //Break off each number
    first=temp%10;
    sec=(temp%100)/10;
    third=(temp%1000)/100;
    four=temp/1000;
    
    switch(four){
        case 1:{
            thou="One-Thousand";
            break;
        }
        case 2:{
            thou="Two-Thousand";
            break;
        }
        case 3:{
            thou="Three-Thousand";
            break;
        }
        case 4:{
            thou="Four-Thousand";
            break;
        }
        case 5:{
            thou="Five-Thousand";
            break;
        }
        case 6:{
            thou="Six-Thousand";
            break;
        }
        case 7:{
            thou="Seven-Thousand";
            break;
        }
        case 8:{
            thou="Eight-Thousand";
            break;
        }
        case 9:{
            thou="Nine-Thousand";
            break;
        }
    }
    switch(third){
        case 1:{
            hun="One-Hundred";
            break;
        }
        case 2:{
            hun="Two-Hundred";
            break;
        }
        case 3:{
            hun="Three-Hundred";
            break;
        }
        case 4:{
            hun="Four-Hundred";
            break;
        }
        case 5:{
            hun="Five-Hundred";
            break;
        }
        case 6:{
            hun="Six-Hundred";
            break;
        }
        case 7:{
            hun="Seven-Hundred";
            break;
        }
        case 8:{
            hun="Eight-Hundred";
            break;
        }
        case 9:{
            hun="Nine-Hundred";
            break;
        }
    }
    switch(sec){
        case 0:{
            ten="";
            break;
        }
        case 1:{
            ten="Ten";
            break;
        }
        case 2:{
            ten="Twenty";
            break;
        }
        case 3:{
            ten="Thirty";
            break;
        }
        case 4:{
            ten="Forty";
            break;
        }
        case 5:{
            ten="Fifty";
            break;
        }
        case 6:{
            ten="Sixty";
            break;
        }
        case 7:{
            ten="Seventy";
            break;
        }
        case 8:{
            ten="Eighty";
            break;
        }
        case 9:{
            ten="Ninety";
            break;
        }
    }
    switch(first){
        case 0:{
            one="";
            break;
        }
        case 1:{
            one="One";
            break;
        }
        case 2:{
            one="Two";
            break;
        }
        case 3:{
            one="Three";
            break;
        }
        case 4:{
            one="Four";
            break;
        }
        case 5:{
            one="Five";
            break;
        }
        case 6:{
            one="Six";
            break;
        }
        case 7:{
            one="Seven";
            break;
        }
        case 8:{
            one="Eight";
            break;
        }
        case 9:{
            one="Nine";
            break;
        }
    }
    if(ten=="Ten" && one!="Zero"){
        switch(first){
            case 1:{
                ten="Eleven";
                one="";
                break;
            }
            case 2:{
                ten="Twelve";
                one="";
                break;
            }
            case 3:{
                ten="Thirteen";
                one="";
                break;
            }
            case 4:{
                ten="Fourteen";
                one="";
                break;
            }
            case 5:{
                ten="Fifteen";
                one="";
                break;
            }
            case 6:{
                ten="Sixteen";
                one="";
                break;
            }
            case 7:{
                ten="Seventeen";
                one="";
                break;
            }
            case 8:{
                ten="Eighteen";
                one="";
                break;
            }
            case 9:{
                ten="Nineteen";
                one="";
                break;
            }
        }
    }
    
    cout<<"Your number is "<<number<<endl;
    if(thou!=""){
        cout<<thou<<' ';
    }
    if(hun!="") {
        cout<<hun<<' ';
    }
    if(ten!=""){
        cout<<ten<<' ';
    }
    if(one!="") {
        cout<<one<<' ';
    }
    cout<<endl;
}