/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 1, 2015, 12:10 PM
 * Purpose: Self Contained Array
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global constants

//Function Prototypes
Array *fillAry(int);
void printAry(Array *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed and size the array
    srand(static_cast<unsigned int>(time(0)));
    int size=100,perLine=10;
    
    //Declare and size are ADT
    Array *array=fillAry(size);
    
    //Print the results
    printAry(array,perLine);
    
    //Destroy/Deallocate memory
    delete []array->data;
    delete array;
    
    //Exit Stage Right
    return 0;
}
void printAry(Array *a,int perLine){
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}
Array *fillAry(int n){
    //Check n
    if(n<=1)n=2;
    //Allocate the memory
    Array *a=new Array;
//    a->size=n;
    (*a).size=n;
    a->data=new int[a->size];
    //Loop and fill with random numbers
    for(int indx=0;indx<a->size;indx++){
//        a->data[indx]=rand()%90+10;
          (*a).data[indx]=rand()%90+10;//? Convert array to pointer notation
    }
    //Exit
    return a;
}

