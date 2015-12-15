/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 3, 2015, 4:41 PM
 * Purpose: Assignment 5
 */

//system libraries
#include <bits/stdc++.h>
using namespace std;

//user libraries
#include "Date.h"
#include "PersonalInformation.h"
#include "RetailItem.h"
#include "Inventory.h"

//global constants

//function prototypes
void problem1();
void problem2();
void setData(PersonalInformation *);
void problem3();
void problem4();
void problem5();

//execution
int main(int argc, char** argv) {
    //Declare inputs
    int choice;
    bool again=true;
    
    do{
        cout<<"1. Chapter 13.1\n2. Chapter 13.4\n3. Chapter 13.5\n4. Chapter 13.6\n5. Exit\nYour Choice: ";
        cin>>choice;
        cin.ignore();
        cout<<endl;
        
        //validation
        if(choice>5 || choice<1){
            cout<<"ERROR: Invalid input\n";
        }else{
            switch(choice){   //menu choice
                case 1: problem1(); break;
                case 2: problem2(); break;
                case 3: problem3(); break;
                case 4: problem4(); break;
                case 5: again=false; break;
                default:{
                    cout<<"ERROR: error in the switch statment\n";
                    return 1;
                }
            }
        }
    }while(again);
    
    return 0;
}
void problem1(){
    cout<<"Problem 1"<<endl;
    Date d;
    int day=0,month=0,year=0;
    
    do{
        cout<<"Input day\n";
        cin>>day;
        if(day<1 || day>31){
            cout<<"Invalid Input\n";
        }
    }while(day<1 || day>31);
    
    do{
        cout<<"Input the month\n";
        cin>>month;
        if(month<1 || month>12){
            cout<<"Invalid Input\n";
        }
    }while(month<1 || month>12);
    
    cout<<"Input the year\n";
    cin>>year;
    
    //Set the values
    d.set_day(day);
    d.set_month(month);
    d.set_year(year);
    
    //Display
    cout<<"Display\n";
    d.display();
    cout<<endl;
}

void problem2(){
    cout<<"Problem 2"<<endl;
    
    //dynamic array of class
    PersonalInformation *info=new PersonalInformation[3];
    
    //sets all data
    setData(info);
    //print all the personal information
    for(int i=0;i<3;i++){
        info[i].print();
        cout<<endl;
    }
    delete []info;
}

void setData(PersonalInformation *pi){
    //Declare variables
    string name;
    string address;
    string age;
    string phone;
    bool first=true;

    for(int i=0;i<3;i++){
        if(first){
            cout<<"Input your name: ";
            getline(cin,name);
            pi[i].set_name(name);
            cout<<"Input your address: ";
            getline(cin,address);
            pi[i].set_add(address);
            cout<<"Input your age: ";
            getline(cin,age);
            pi[i].set_age(age);
            cout<<"Input your phone number: ";
            getline(cin,phone);
            pi[i].set_phne(phone);
            first=false;
            cout<<endl;
        }else {
            cout<<"Input your friend's/family member's name\n";
            getline(cin,name);
            pi[i].set_name(name);
            cout<<"Input your friend's/family member's address: ";
            getline(cin,address);
            pi[i].set_add(address);
            cout<<"Input your friend's/family member's age: ";
            getline(cin,age);
            pi[i].set_age(age);
            cout<<"Input your friend's/family member's phone number: ";
            getline(cin,phone);
            pi[i].set_phne(phone);
            cout<<endl;
        }
    }
}

void problem3(){
    cout<<"Problem 3"<<endl;
    
    //Declare Variables
    string info;
    int unit;
    float cost;
    
    info="Jacket";
    unit=12;
    cost=59.95;
    RetailItem jacket(info,unit,cost);
    
    info="Designer Jeans";
    unit=40;
    cost=34.95;
    RetailItem jeans(info,unit,cost);
    
    info="Shirt";
    unit=20;
    cost=24.95;
    RetailItem shirt(info,unit,cost);
    
    jacket.print();
    jeans.print();
    shirt.print();
}

void problem4(){
    cout<<"Problem 4"<<endl;
    //Declare Variables
    int number;
    int quant;
    float cost;
    
    cout<<"Input the item number: ";
    cin>>number;
    cin.ignore();
    cout<<"Input the cost of the item: $";
    cin>>cost;
    cin.ignore();
    cout<<"Input how many are being purchased: ";
    cin>>quant;
    cin.ignore();
    
    Inventory item(number,quant,cost);
    item.print();
    cout<<endl;
}