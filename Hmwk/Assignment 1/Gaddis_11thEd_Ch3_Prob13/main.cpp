/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 8, 2015
 * Purpose: Currency
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

/* //User Libraries
 * 
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 *///Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    float Yen;    //Japanese Yens
    float Euro;   //Euros
    float dollar; //Total us dollars
           
    //Input the value
    cout<<"Input the number of U.S. Dollars you have to convert to Japanese Yens and euros."<<endl;
    cout<<"$";
    cin>>dollar;
    
    //Calculate
    Euro=(dollar*0.91f);
    Yen=(dollar*122.34f);
    
    //Output the results
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<dollar<<" U.S. dollar will convert to "<<Euro<<" Euros"<<endl;
    cout<<dollar<<" U.S. dollar will convert to "<<Yen<<" Japanese Yens"<<endl;
    return 0;
}

