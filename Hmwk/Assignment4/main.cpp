/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 8, 2015
 * Purpose: Assignment 4
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;
//User Libraries
#include "SpeakersBureau.h"
#include "Accounts.h"
#include "Budget.h"
#include "Drinks.h"
#include "Movie.h"

//Global constants

//Function Prototypes
void prob1();
void prob2();
void prob3();
void getInfo();
void compare();
void prob4();
void prob5();

//Execution Begins here!
int main(int argc, char** argv) {
    bool runagn = false;
    int choice;
    do{
        do{
            cout<<"1. Problem 1 \n2. Problem 2 \n3. Problem 3 \n4. Problem 4\n5. Problem 5\n6. Exit\n";
            cin>>choice;
            if(choice<1 || choice>6){
                cout<<"ERROR: Invalid input\n";
            }
        }while(choice<1 || choice>6);
        switch(choice){
            case 1: {
                cout<<"Problem 1\n";
                prob1();
                break;
            }
            case 2: {
                cout<<"Problem 2\n";
                prob2();
                break;
            }
            case 3: {
                cout<<"Problem 3\n";
                prob3();
                break;
            }
            case 4: {
                cout<<"Problem 4\n";
                prob4();
                break;
            }
            case 5: {
                cout<<"Problem 5\n";
                prob5();
                break;
            }
            case 6: {
                cout<<"Bye bye!!!";
                runagn=true;
                break;
            }
            default: {
                cout<<"Error: In the switch statment\n";
            }
        }
    }while(runagn==false);
    return 0;
}
void prob1(){
    cout<<"Gaddis Seventh Edition Chapter 11 Problem 9: Speakers Bureau\n\n";
    
    int n;//number of speakers
    int answ;
    int chngSpk;
    bool again=true;
    
    cout<<"How many speakers?\n";
    cin>>n;
    cin.ignore();
    cout<<endl;
    Speaker *s=new Speaker[n];
    
    for(int i=0;i<n;i++){
        cout<<"Speaker name: ";
        getline(cin,s[i].name);
        cout<<s[i].name<<"'s phone number: ";
        getline(cin,s[i].phone);
        cout<<s[i].name<<"'s Topic: ";
        getline(cin,s[i].topic);
        cout<<s[i].name<<"'s fee: ";
        cin>>s[i].fee;
        cin.ignore();
    }
    
    do{
        cout<<endl<<"Speakers:"<<endl;
            for(int i=0;i<n;i++){
            cout<<i+1<<". "<<s[i].name<<endl;
        }
        cout<<endl;
        do{
            cout<<"1. Change data for a speaker\n2. Display a speakers data\n3. Exit\n";
            cin>>answ;
            cin.ignore();
            if(answ<1 || answ>3){
                cout<<"Error: Your input was not 1,2 or 3\n";
            }
        }while(answ<1 || answ>3);
        switch(answ){
            case 1: {
                do{
                    cout<<endl<<"Speakers:"<<endl;
                    for(int i=0;i<n;i++){
                        cout<<i+1<<". "<<s[i].name<<endl;
                    }
                    cout<<endl;
                    
                    cout<<"What speaker's data would you like to change? ";
                    cin>>chngSpk;
                    cin.ignore();
                }while(chngSpk<1 || chngSpk>n);
                
                cout<<"Speaker name: ";
                getline(cin,s[chngSpk-1].name);
                cout<<s[chngSpk-1].name<<"'s phone number: ";
                getline(cin,s[chngSpk-1].phone);
                cout<<s[chngSpk-1].name<<"'s Topic: ";
                getline(cin,s[chngSpk-1].topic);
                do{
                    cout<<s[chngSpk-1].name<<"'s fee: ";
                    cin>>s[chngSpk-1].fee;
                    cin.ignore();
                }while(s[chngSpk-1].fee<1);
                cout<<endl;
                break;
            }
            case 2:{
                for(int i=0;i<n;i++){
                cout<<s[i].name<<endl;
                cout<<"Phone number: "<<s[i].phone<<endl;
                cout<<"Topic: "<<s[i].topic<<endl;
                cout<<"Fee: "<<s[i].fee<<endl;
                }
                break;
            }
            case 3:{
                again=false;
                break;
            }
            default: {
                cout<<"Error: In switch statment\n";
            }
        }

    }while(again);
    delete []s;
}
void prob2(){
    cout<<"Gaddis 11th Edition Chapter 11 Problem 7: Customer Accounts\n";
    
    int n;//number of accounts
    int answ;
    int chngSpk;
    bool again=true;
    
    cout<<"How many accounts?\n";
    cin>>n;
    cin.ignore();
    cout<<endl;
    Account *a=new Account[n];
    for(int i=0;i<n;i++){
        cout<<"Account holder's name: ";
        getline(cin,a[i].name);
        cout<<a[i].name<<"'s Address: ";
        getline(cin,a[i].address);
        cout<<a[i].name<<"'s City, State, and Zip: ";
        getline(cin,a[i].city);
        cout<<a[i].name<<"'s Telephone Number: ";
        getline(cin,a[i].phone);
        cout<<a[i].name<<"'s Account Balance: ";
        cin>>a[i].bal;
        cin.ignore();
        cout<<a[i].name<<"'s Date of last payment: ";
        getline(cin,a[i].lastpay);
        cout<<endl;
    }
    
    do{
        cout<<endl<<"Account Holders:"<<endl;
            for(int i=0;i<n;i++){
            cout<<i+1<<". "<<a[i].name<<endl;
        }
        cout<<endl;
        do{
            cout<<"1. Change data for an account holder\n2. Display accounts\n3. Exit\n";
            cin>>answ;
            cin.ignore();
            if(answ<1 || answ>3){
                cout<<"Error: Your input was not 1,2 or 3\n";
            }
        }while(answ<1 || answ>3);
        switch(answ){
            case 1: {
                do{
                    cout<<endl<<"Account Holders:"<<endl;
                    for(int i=0;i<n;i++){
                        cout<<i+1<<". "<<a[i].name<<endl;
                    }
                    cout<<endl;
                    
                    cout<<"What Account data would you like to change? ";
                    cin>>chngSpk;
                    cin.ignore();
                }while(chngSpk<1 || chngSpk>n);
                
            cout<<"Account holder's name: ";
            getline(cin,a[chngSpk-1].name);
            cout<<a[chngSpk-1].name<<"'s Address: ";
            getline(cin,a[chngSpk-1].address);
            cout<<a[chngSpk-1].name<<"'s City, State, and Zip: ";
            getline(cin,a[chngSpk-1].city);
            cout<<a[chngSpk-1].name<<"'s Telephone Number: ";
            getline(cin,a[chngSpk-1].phone);
            do{
                cout<<a[chngSpk-1].name<<"'s Account Balance: ";
                cin>>a[chngSpk-1].bal;
                cin.ignore();
            }while(a[chngSpk-1].bal<1);
            cout<<a[chngSpk-1].name<<"'s Date of last payment: ";
            getline(cin,a[chngSpk-1].lastpay);
            cout<<endl;
            break;
            }
            case 2:{
                for(int i=0;i<n;i++){
                cout<<a[i].name<<endl;
                cout<<"Address: "<<a[i].address<<endl;
                cout<<"City, State, and Zip: "<<a[i].city<<endl;
                cout<<"Telephone Number: "<<a[i].phone<<endl;
                cout<<"Account Balance: "<<a[i].bal<<endl;
                cout<<"Date of Last Payment: "<<a[i].lastpay<<endl;
                }
                break;
            }
            case 3:{
                cout<<"switch 3\n";
                again=false;
                break;
            }
            default: {
                cout<<"Error: In switch statment\n";
            }
        }
    }while(again);
    delete []a;
}
void prob3(){
    cout<<"Gaddis 11th Edition Chapter 11 Problem 11: Monthly Budget\n";
    getInfo();
    compare();
}
void compare(){
    Budget b;
    if(b.house<=500){
        cout<<"Spending was under in Housing $";
        cout<<500-b.house<<endl;
    }else if(b.house>500){
        cout<<"Spending was over in Housing $";
                cout<<b.house-500<<endl;
    }
    if(b.util<=150){
        cout<<"Spending was under in Utilities $";
        cout<<150-b.util<<endl;
    }else if(b.util>150){
        cout<<"Spending was over in Utilities $";
                cout<<b.util-150<<endl;
    }
    if(b.house<=65){
        cout<<"Spending was under in Household Expenses $";
        cout<<65-b.house<<endl;
    }else if(b.house>65){
        cout<<"Spending was over in Household Expenses $";
                cout<<b.house-65<<endl;
    }
    if(b.trans<=50){
        cout<<"Spending was under in Transportation $";
        cout<<50-b.trans<<endl;
    }else if(b.trans>50){
        cout<<"Spending was over in Transportation $";
                cout<<b.trans-50<<endl;
    }
    if(b.food<=250){
        cout<<"Spending was under in Food $";
        cout<<250-b.food<<endl;
    }else if(b.food>250){
        cout<<"Spending was over in Food $";
                cout<<b.food-250<<endl;
    }
    if(b.medical<=30){
        cout<<"Spending was under in Medical $";
        cout<<30-b.medical<<endl;
    }else if(b.medical>30){
        cout<<"Spending was over in Medical $";
                cout<<b.medical-30<<endl;
    }
    if(b.insur<=100){
        cout<<"Spending was under in Insurance $";
        cout<<100-b.insur<<endl;
    }else if(b.insur>100){
        cout<<"Spending was over in Insurance $";
                cout<<b.insur-100<<endl;
    }
    if(b.enter<=150){
        cout<<"Spending was under in Entertainment $";
        cout<<150-b.enter<<endl;
    }else if(b.enter>150){
        cout<<"Spending was over in Entertainment $";
                cout<<b.enter-150<<endl;
    }
    if(b.clothes<=75){
        cout<<"Spending was under in Clothing $";
        cout<<75-b.clothes<<endl;
    }else if(b.clothes>75){
        cout<<"Spending was over in Clothing $";
                cout<<b.clothes-75<<endl;
    }
    if(b.misc<=50){
        cout<<"Spending was under in Miscellaneous $";
        cout<<50-b.misc<<endl;
    }else if(b.misc>50){
        cout<<"Spending was over in Miscellaneous $";
                cout<<b.misc-50<<endl;
    }
    cout<<endl;
}
void getInfo(){
    Budget b;
    cout<<"Input the housing cost for this month\n$";
    cin>>b.house;
    cout<<"Input the Utilities cost for this month\n$";
    cin>>b.util;
    cout<<"Input the Household Expenses cost for this month\n$";
    cin>>b.expense;
    cout<<"Input the Transportation cost for this month\n$";
    cin>>b.trans;
    cout<<"Input the Food cost for this month\n$";
    cin>>b.food;
    cout<<"Input the Medical cost for this month\n$";
    cin>>b.medical;
    cout<<"Input the Insurance cost for this month\n$";
    cin>>b.insur;
    cout<<"Input the Entertainment cost for this month\n$";
    cin>>b.enter;
    cout<<"Input the Clothing cost for this month\n$";
    cin>>b.clothes;
    cout<<"Input the Miscellaneous cost for this month\n$";
    cin>>b.misc;
}
    
void prob4(){
    cout<<"Gaddis 11Th Edition Chapter 11 Problem 13: Drink Machine Simulator\n";
    float payment;      //users payment
    int choice;         //which soda
    float change;       //change to be returned
    const int SIZE = 5;
    float earnings=0.0f; //Total earnings
    
    Drink drinkInfo[SIZE];
    
    drinkInfo[0].drinkName = "Cola";
    drinkInfo[0].cost = .75;
    drinkInfo[0].quantity = 20;

    drinkInfo[1].drinkName = "Root Beer";
    drinkInfo[1].cost = .75;
    drinkInfo[1].quantity = 20;

    drinkInfo[2].drinkName = "Lemon-Lime";
    drinkInfo[2].cost = .75;
    drinkInfo[2].quantity = 20;

    drinkInfo[3].drinkName = "Grape Soda";
    drinkInfo[3].cost = .8;
    drinkInfo[3].quantity = 20;

    drinkInfo[4].drinkName = "Cream Soda";
    drinkInfo[4].cost = .8;
    drinkInfo[4].quantity = 20;
    
    do{
        earnings+=payment;
        cout<<endl; 
        cout<<"1. Cola\n2. Root Beer\n3. Lemon-Lime\n4. Grape Soda\n5. Cream Soda\n6. Quit\n";
        cout<<"Choose one of the menu items\n";
        cin>>choice;

        switch(choice){
            case 1:{
            do{
                cout<<"Please enter the amount of money to be paid (in cents): ";
                cin>>payment;
                if(payment<0 || payment>1){
                    cout << "That is an invalid amount of change. Please re-enter your amount.";
                }
            }while(payment<0 || payment>1);
                change = payment-drinkInfo[0].cost;
                cout << "Your change is $" << change << endl;
                break;
            }
            case 2: {
                do{
                    cout<<"Please enter the amount of money to be paid (in cents): ";
                    cin>>payment;
                    if(payment<0 || payment>1){
                        cout << "That is an invalid amount of change. Please re-enter your amount.";
                    }
                 }while(payment<0 || payment>1);
                change = drinkInfo[1].cost - payment;
                cout << "Your change is $" << change << endl;
                break;
            }
            case 3: {
                do{
                    cout<<"Please enter the amount of money to be paid (in cents): ";
                    cin>>payment;
                    if(payment<0 || payment>1){
                        cout << "That is an invalid amount of change. Please re-enter your amount.";
                    }
                }while(payment<0 || payment>1);
                change = drinkInfo[2].cost - payment;
                cout<<"Your change is $"<<change<<endl;
                break;
            }
            case 4:{
                do{
                    cout<<"Please enter the amount of money to be paid (in cents): ";
                    cin>>payment;
                    if(payment<0 || payment>1){
                        cout << "That is an invalid amount of change. Please re-enter your amount.";
                    }
                }while(payment<0 || payment>1);
                change = drinkInfo[3].cost - payment;
                cout<<"Your change is $"<<change<<endl;
                break;
            }
            case 5:{
                do{
                    cout<<"Please enter the amount of money to be paid (in cents): ";
                    cin>>payment;
                    if(payment<0 || payment>1){
                        cout << "That is an invalid amount of change. Please re-enter your amount\n";
                    }
                }while(payment<0 || payment>1);
                change = drinkInfo[4].cost - payment;
                cout<<"Your change is $"<<change<<endl;
                break;
            }
            case 6:{
                cout<<"The machine has earned $"<<earnings<<endl;
                break;
            }
            default:{
                cout<<"Error: In the switch statment\n";
            }
        }
    } while (choice != 6);
}
void prob5(){
    cout<<"Gaddis 11th Edition Chapter 11 Problem 1: Movie Data\n";
    Movie m;

    //Gather the movie information
    cout<<"Input the Title\n"; 
    cin.ignore();
    getline(cin,m.title);
    cout<<"Input the Director\n";
    getline(cin,m.director);
    cout<<"Input the Year Released\n";
    getline(cin,m.year);
    cout<<"Input the Running time (in minutes)\n";
    cin>>m.time;
    cin.ignore();
    
    //Display the results
    cout<<"The Movie title is "<<m.title<<endl;
    cout<<"The Director is "<<m.director<<endl;
    cout<<"The Year Released is "<<m.year<<endl;
    cout<<"The Running time (in minutes) is "<<m.time<<endl;
    cout<<endl;
    
    
}

    



