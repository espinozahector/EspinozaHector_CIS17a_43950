/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 8, 2015, 5:00 PM
 * Purpose: 
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    unsigned int start; //starting number of organisms
    float daily; //average daily population increase (as a percentage)
    unsigned int days; //number of days they will multiply
    unsigned int temp;
    do{
        cout<<"What is the starting number of organisms? "<<endl;
        cin>>start;
            if(start<2){
                cout<<"Error: Starting population cannot be lower than 2"<<endl;
            }
    }while(start<2);
    do{
        cout<<"What is the average daily population increase (as a percentage ex: .05) "<<endl;
        cin>>daily;
            if(daily<0){
            cout<<"Error: The average daily population increase cannot be a negative number"<<endl;
            }
        }while(daily<0);
    do{
        cout<<"Input the number of days they will multiply "<<endl;
        cin>>days;
            if(days>1){
            cout<<"Error: Days they will  multiple cannot be lower than 1"<<endl;
            }
    }while(days>1);
    for(int i=1;i<=days;i++){
       cout<<"Day "<<i<<" has a population of "<<start<<endl; 
        temp=start*daily;
        start=start+temp;
    }

    return 0;
}

