/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 8, 2015, 5:16 PM
 * Purpose: 
 */

#include <iostream>

using namespace std;

/*The formula for converting a temperature from Fahrenheit to 
Celsius is 
C=5/9(F-32)
where F is the Fahrenheit temperature and C is the Celsius 
 * temperature. Write a function named celsius that accepts a 
 * Fahrenheit temperature as an argument. The function should return 
 * the temperature, converted to Celsius. Demonstrate the function 
 * by calling it in a loop that displays a table of the Fahrenheit 
 * temperatures 0 through 20 and their Celsius equivalents.
 */
int main(int argc, char** argv) {
    //Declare Variables
    float celsius,Farnhit; //Celcuis and fahrenheit
    
    cout<<"Input the Fahrenheit and i will convert it to Celsius.";
    cin>>Farnhit;
    
    //Convert fahrenheit to celsius
    celsius = (Farnhit-32)/1.8;
    
    //Output the results
    cout<<"The conversion of Fahrenheit to Celsius is "<<celsius<<endl;
    

    return 0;
}

