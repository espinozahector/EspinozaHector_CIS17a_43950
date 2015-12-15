/* 
 * File:   main.cpp
 * Author: Eugenia
 *
 * Created on November 11, 2015, 10:16 AM
 */

#include <iostream>
using namespace std;

int month(int);

int main(int argc, char** argv) {

    int SIZE=12;
    int array[SIZE];
    int total=0;
    int average=0;
    int small=1000,large=1;
    int highest=0,lowest=0;
    
    for(int i=1;i<=SIZE;i++){
       cout<<"Input the total amount of rainfall for ";
       month(i);
       cout<<endl;
       cin>>array[i];
       total+=array[i];
       if(array[i]<small){
        small=array[i];
            lowest=i;
        }
       if(array[i]>large){
           large=array[i];
            highest=i;
        }
    }
    
    average=total/SIZE;
    cout<<"The total rainfall for the year is "<<total<<endl;
    cout<<"The average monthly rainfall is "<<average<<endl;
    cout<<"The month with the highest amount of rainfall was ";
    month(highest);
    cout<<" with "<<array[highest]<<" amount of rainfall."<<endl;
    cout<<"The month with the lowest amount of rainfall was ";
    month(lowest);
    cout<<" with "<<array[lowest]<<" amount of rainfall."<<endl;
    return 0;
}
int month(int i){
    switch (i){
        case 1:{
            cout<<"January";
            break;
        }
        case 2:{
            cout<<"February";
            break;
        }
        case 3:{
            cout<<"March";
            break;
        }
        case 4:{
            cout<<"April";
            break;
        }
        case 5:{
            cout<<"May";
            break;
        }
        case 6:{
            cout<<"June";
            break;
        }
        case 7:{
            cout<<"July";
            break;
        }
        case 8:{
            cout<<"August";
            break;
        }
        case 9:{
            cout<<"September";
            break;
        }
        case 10:{
            cout<<"October";
            break;
        }
        case 11:{
            cout<<"November";
            break;
        }
        case 12:{
            cout<<"December";
            break;
        }
        default:{cout<<"ERROR\n";break;}
    }
}

