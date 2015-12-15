/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 3, 2015, 11:33 PM
 * Purpose: 
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    bool runagn = false;
    int choice;
    do{
        do{
            cout<<"1. Problem 1 \n2. Problem 2 \n3 End \n";
            cin>>choice;
            if(choice<1 || choice>3){
                cout<<"ERROR: Invalid input\n";
            }
        }while(choice<1 || choice>3);
        switch(choice){
            case 1: {
                cout<<"Problem 1\n";
                break;
            }
            case 2: {
                cout<<"Problem 2\n";
                break;
            }
            case 3: {
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

