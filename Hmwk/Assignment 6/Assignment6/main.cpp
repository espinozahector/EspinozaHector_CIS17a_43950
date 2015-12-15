/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 12, 2015M
 * Purpose: Assignment 6
 */

//Library includes 
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries
#include "Numbers.h"
#include "DayOfYear.h"
#include "DayOfYear2.h"
#include "NumDays.h"

//Global Constants

//Function Prototypes 
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=4);
    return 0;
}
void Menu(){
    cout<<"Menu for the Assignment 5"<<endl;
    cout<<"Type 1 for problem 14.1"<<endl;
    cout<<"Type 2 for problem 14.2"<<endl;
    cout<<"Type 3 for problem 14.3"<<endl;
    cout<<"Type 4 for problem 14.4"<<endl;
    cout<<"Type anything else to exit"<<endl;
}
int getN(){
        int inN;
        cin>>inN;
        cin.ignore();
        return inN;
}
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    //Declare Variables
    int num;
    Numbers n;
    //Get inputs
    cout<<"Input any number\n";
    cin>>num;
    cin.ignore();
    //set the number and display the month
    n.set_number(num);
    n.Display();
    cout<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    //Declare Variables
    string day;
    DayOfYear d;
    //Get input
    cout<<"Input any day of the year\n";
    getline(cin,day);
    
    d.set_day(day);
    d.print();
    cout<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        //Declare variables
        string month;
        string day;
        int answ;
        char choice;
        
        //Get inputs
        cout<<"Input month: ";
        getline(cin,month);
        cout<<"Input day: ";
        getline(cin,day);
        
        DayOfYear2 date(day,month);
        date.print();
        
        //Determine if the user wants to add or subtract a day
        do{
            cout<<"Would you like to add 1 day or subtract 1 day?(Y or N)\n";
            cin>>choice;
            
            if(choice!='Y' && choice !='y' && choice!='N' && choice !='n'){
                cout<<"ERROR: Invalid Input. Input Y for yes, or N for no\n";
            }
        }while(choice!='Y' && choice !='y' && choice!='N' && choice !='n');
        if(choice=='Y' || choice=='y'){
            do{
                cout<<"1. Add a Day\n2. Subtract a day\nInput your answer: ";
                cin>>answ;
                if(answ != 1 && answ!=2){
                    cout<<"ERROR: Invalid Input. Must be a 1 or a 2.\n";
                }
            }while(answ != 1 && answ!=2);
        }
        switch(answ){
            case 1:{ 
                //Add a day
                date++;
                break;
            }
            case 2:{
                //Subtract a day
                date--;
                break;
            }
            default:{
                cout<<"ERROR: bad switch statement\n";
                break;
            }
        }
        date.print();
        cout<<endl;
}
void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
//4. NumDays Class 
//Design a class called NumDays. The class’s purpose is to store a value that represents a 
//number of work hours and convert it to a number of days. For example, 8 hours would 
//be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would 
//be converted to 2.25 days. The class should have a constructor that accepts a number 
//of hours, as well as member functions for storing and retrieving the hours and days. 

//The class should also have the following overloaded operators: 
//+ Addition operator. When two NumDays objects are added together, the over-
//loaded + operator should return the sum of the two objects’ hours members. 
//− Subtraction operator. When one NumDays object is subtracted from another, 
//the overloaded − operator should return the difference of the two objects’ hours 
//members. 
//
//++ Prefix and postfix increment operators. These operators should increment the 
//number of hours stored in the object. When incremented, the number of days 
//should be automatically recalculated. 
//−− Prefix and postfix decrement operators. These operators should decrement the 
//number of hours stored in the object. When decremented, the number of days 
//should be automatically recalculated.
        float hours;
        int answ;
        int choice;
        cout<<"Input number of hours: ";
        cin>>hours;
        cin.ignore();
        
        NumDays days(hours);
        days.print();
        do{
            cout<<"1. Add another object\n2. Increment the number of hours\n3. Decrement the number of hours\n";
            cin>>answ;   
            if(answ != 1 && answ!=2 && answ!=3){
                cout<<"ERROR: Invalid Input. Must be a 1 or a 2.\n";
            }
        }while(answ != 1 && answ!=2 && answ!=3);
        
        switch(answ){
            case 1:{ 
                cout<<"Input number of hours: ";
                cin>>hours;
                cin.ignore();
                
                NumDays days2(hours);
                days2.print();
                
                cout<<"1. return the sum of the two objects’ hours members.\n2. return the difference of the two objects’ hours\n";
                cin>>choice;
                
                switch(choice){
                    case 1:{
                        //add the two hours together
                        days+days2;
                        break;
                    }
                    case 2:{
                        //find the different of the two hours
                        days-days2;
                        break;
                    }
                    default:{
                        cout<<"ERROR: in the switch statement\n";
                        break;
                    }
                }
                break;
            }
            case 2:{
                //Increment the number of hours
                days++;
                days.print();
                break;
            }
            case 3:{
                //decrement the number of hours
                days--;
                days.print();
                break;
            }
            default:{
                cout<<"ERROR: bad switch statement\n";
                break;
            }
        }
        
        cout<<endl;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}