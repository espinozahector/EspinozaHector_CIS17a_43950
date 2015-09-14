/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 8, 2015, 5:16 PM
 * Purpose: Celsius to Fahrenheit
 */

#include <iostream>

using namespace std;
//Write a program that converts Celsius temperatures
//to Fahrenheit temperatures. The formula is 
//F is the Fahrenheit temperature, 
//and C is the Celsius temperature.

int main(int argc, char** argv) {
    //Declare Variables
    unsigned int celsius,Farnhit; //Celcuis and fahrenheit
    
    cout<<"Input the Celsius and i will convert it to Fahrenheit.";
    cin>>celsius;
    
    //Convert celsius to fahrenheit  
    Farnhit = ((celsius*9)/5)+32;
    
    //Output the results
    cout<<"The conversion of Celsius to Fahrenheit is "<<Farnhit<<endl;
    

    return 0;
}

