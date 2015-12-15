/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on November 24, 2015
 * Purpose: Assignment 7
 */

//Library includes 
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "ShiftSupervisor.h"
#include "CustomerData.h"
#include "PersonData.h"
#include "PreferredCustomer.h"
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
    cout<<"Type 1 for problem 15.1"<<endl;
    cout<<"Type 2 for problem 15.2"<<endl;
    cout<<"Type 3 for problem 15.7"<<endl;
    cout<<"Type 4 for problem 15.8"<<endl;
    cout<<"Type anything else to exit"<<endl;
}
int getN(){
        int inN;
        cin>>inN;
        cin.ignore();
        return inN;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    //Declare Variables
    string name;
    string number;
    string hireD;
    int shift;
    float rate;
    
    //Get inputs
    cout<<"Input the Employee's name\n";
    cout<<"Name: ";
    getline(cin,name);
    
    cout<<"Input the Employee's number\n";
    cout<<"Employee number: ";
    getline(cin,number);
    
    cout<<"Input the Employee's hire date\n";
    cout<<"Hire date: ";
    getline(cin,hireD);
    
    cout<<"Input the Employee's shift 1.Day 2.Night\n";
    cout<<"Shift: ";
    cin>>shift;
    
    cout<<"Input the Employee's Hourly Pay Rate\n";
    cout<<"Pay Rate: ";
    cin>>rate;
    
    ProductionWorker work(name,number,hireD,shift,rate);
    
    work.print();
    work.display();
    cout<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    float annual;//annual salary
    float bonus; //annual production bonus

    string name; //Employee name
    string number; //Employee number
    string hireD; //Employee hire date
    int shift; //Day shift or night shift
    float rate; //Hourly pay rate
    
    
    //Get inputs
    cout<<"Input the Employee's name\n";
    cout<<"Name: ";
    getline(cin,name);
    
    cout<<"Input the Employee's number\n";
    cout<<"Employee number: ";
    getline(cin,number);
    
    cout<<"Input the Employee's hire date\n";
    cout<<"Hire date: ";
    getline(cin,hireD);
    
    cout<<"Input the Employee's shift 1.Day 2.Night\n";
    cout<<"Shift: ";
    cin>>shift;
    
    cout<<"Input the Employee's Hourly Pay Rate\n";
    cout<<"Pay Rate: ";
    cin>>rate;
    
    cout<<"Input the Supervisor's annual Salary\n";
    cout<<"Salary: $";
    cin>>annual;
    
    cout<<"Input the Supervisor's annual production bonus\n";
    cout<<"Bonus: $";
    cin>>bonus;
    
    ShiftSupervisor work(name,number,hireD,shift,rate,annual,bonus);
    
    cout<<"\n";
    cout<<"********************************************\n\n";
    work.print();
    work.display();
    work.printS();
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    string last;
    string first;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    
    cout<<"Input the Customer's Last Name\n";
    cout<<"Last Name: ";
    getline(cin,last);
    
    cout<<"Input the Customer's First Name\n";
    cout<<"First Name: ";
    getline(cin,first);
    
    cout<<"Input the Customer's Address\n";
    cout<<"Address: ";
    getline(cin,address);
    
    cout<<"Input the Customer's City\n";
    cout<<"City: ";
    getline(cin,city);
    
    cout<<"Input the Customer's State\n";
    cout<<"State: ";
    getline(cin,state);
    
    cout<<"Input the Customer's Zip\n";
    cout<<"Zip: ";
    getline(cin,zip);
    
    bool valid;
    do{
        valid=true;
        for(int i=0;i<zip.length();i++){
                if(!isdigit(zip[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a correct Zip code. Check to make sure they are all digits\n";
                    break;
                }
            }
        if(!valid){
            cout<<"Input the Customer's Zip\n";
            cout<<"Zip: ";
            getline(cin,zip);
        }
    }while(!valid);
    
    cout<<"Input the Customer's Phone number\n";
            cout<<"Phone: ";
            getline(cin,phone);
            
    do{
        valid=true;
        for(int i=0;i<phone.length();i++){
                if(!isdigit(phone[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a correct Phone number. Check to make sure they are all digits\n";
                    break;
                }
            }
        if(!valid){
            cout<<"Input the Customer's Phone number\n";
            cout<<"Phone: ";
            getline(cin,phone);
        }  
    }while(!valid);
        
    int num;
    bool mail;
    char ans;
    
    cout<<"Input the Customer's unique number\n";
    cout<<"Customer Number: ";
    cin>>num;
    
    do{
        cout<<"Does the Customer want to be on the mailing list?[Y]/[N]\n";
        cin>>ans;
        
        if(ans!='y' && ans!='Y' && ans!='n' && ans !='Y'){
            cout<<"ERROR: Invalid Input\n";
        }
    }while(ans!='y' && ans!='Y' && ans!='n' && ans !='Y');
    switch(ans){
        case 'Y':
        case 'y':{
            cout<<"Customer "<<num<<" is now on the mailing list\n";
            mail=true;
            break;
        }
        default:{
            mail=false;
            break;
        }
    }
    
    CustomerData data(last,first,address,city,state,zip,phone,num,mail);
    
    cout<<"\n********************************************\n";
    data.getName();
    cout<<"'s Information: \n";
    data.print();
    data.display();
    
    cout<<endl;
}
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    //FOR THE PERSON DATA CLASS
    string last;
    string first;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    
    //FOR THE CUSTOMER DATA CLASS
    int num;
    bool mail;
    char ans;
    
    //FOR THE PREFERRED CUSTOMER CLASS
    float buy;
    float perc;
    
    //Get inputs
    cout<<"Input the Customer's Last Name\n";
    cout<<"Last Name: ";
    getline(cin,last);
    
    cout<<"Input the Customer's First Name\n";
    cout<<"First Name: ";
    getline(cin,first);
    
    cout<<"Input the Customer's Address\n";
    cout<<"Address: ";
    getline(cin,address);
    
    cout<<"Input the Customer's City\n";
    cout<<"City: ";
    getline(cin,city);
    
    cout<<"Input the Customer's State\n";
    cout<<"State: ";
    getline(cin,state);
    
    cout<<"Input the Customer's Zip\n";
    cout<<"Zip: ";
    getline(cin,zip);
    
    bool valid;
    do{
        valid=true;
        for(int i=0;i<zip.length();i++){
                if(!isdigit(zip[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a correct Zip code. Check to make sure they are all digits\n";
                    break;
                }
            }
        if(!valid){
            cout<<"Input the Customer's Zip\n";
            cout<<"Zip: ";
            getline(cin,zip);
        }
    }while(!valid);
    
    cout<<"Input the Customer's Phone number\n";
            cout<<"Phone: ";
            getline(cin,phone);
            
    do{
        valid=true;
        for(int i=0;i<phone.length();i++){
                if(!isdigit(phone[i])){
                    valid=false;
                    cout<<"ERROR: You did not enter a correct Phone number. Check to make sure they are all digits\n";
                    break;
                }
            }
        if(!valid){
            cout<<"Input the Customer's Phone number\n";
            cout<<"Phone: ";
            getline(cin,phone);
        }  
    }while(!valid);
        
    
    //used for the customerdata class
    cout<<"Input the Customer's unique number\n";
    cout<<"Customer Number: ";
    cin>>num;
    
    do{
        cout<<"Does the Customer want to be on the mailing list?[Y]/[N]\n";
        cin>>ans;
        
        if(ans!='y' && ans!='Y' && ans!='n' && ans !='Y'){
            cout<<"ERROR: Invalid Input\n";
        }
    }while(ans!='y' && ans!='Y' && ans!='n' && ans !='Y');
    //Sets the bool to be on mail list to true or false
    switch(ans){
        case 'Y':
        case 'y':{
            cout<<"Customer "<<num<<" is now on the mailing list\n";
            mail=true;
            break;
        }
        default:{
            mail=false;
            break;
        }
    }
    //Used for the preferedCustomer class
    do{
        cout<<"Input how much the customer spent\n";
        cout<<"Spent: $";
        cin>>buy;
        if(buy<0){
            cout<<"ERROR: Invalid Input the spent amount can't be less than 0";
        }
    }while(buy<0);
        
        
    PreferredCustomer customer(last,first,address,city,state,zip,phone,num,mail,buy);
        
    cout<<"\n********************************************\n";
    customer.getName();
    cout<<"'s Information: \n";
    customer.print();
    customer.display();
    customer.printing();
    cout<<endl;
}
