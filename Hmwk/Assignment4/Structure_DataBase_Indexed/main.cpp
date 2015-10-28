/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 6, 2015, 11:20 AM
 * Purpose: 
 * Hmwk: Convert structure to dot operator and the array notation to pointer notation.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//User libraries
#include "indexedcolum.h"

//Global constants

//Function Prototypes
IndxCol *fill(int);
void prntStr(IndxCol *,int);
void prntAry(int *,int,int);
void mrkSort(IndxCol *);


int main(int argc, char** argv) {
    //Call the random number generator seed fucntion
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the memory for the structure
    int n=100,col=10;
    IndxCol *str=fill(n);
    //Print the structure
    cout<<"The original index array\n";
    prntAry((*str).index,(*str).size,col);
    cout<<"The original data array\n";
    prntAry((*str).array,(*str).size,col);
    cout<<"The original data array using the index array\n";
    prntStr(str,col);
    //Sort the data using an index,hence data base sort
    mrkSort(str);
    //Print the structure
    cout<<"The index array after sorting\n";
    prntAry((*str).index,(*str).size,col);
    cout<<"The data array after sorting\n";
    prntAry((*str).array,(*str).size,col);
    cout<<"The data array using the index array after sorting\n";
    prntStr(str,col);
    //Exit Stage Right!
    return 0;
}
void mrkSort(IndxCol *a){
    //Pick a position to sort
    for(int pos=0;pos<(*a).size-1;pos++){
        //Sort the list by position
        for(int lst=pos+1;lst<(*a).size;lst++){
            if(((*a).array[(*a).index[pos]])>((*a).array[(*a).index[lst]])){
                int temp=(*a).index[pos];
                (*a).index[pos]=(*a).index[lst];
                (*a).index[lst]=temp;
            }
        }
    }
}
void prntAry(int *a,int size,int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<setw(2)<<a[i]<<' ';
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void prntStr(IndxCol *a,int perLine){
    cout<<endl;
    for(int i=0;i<(*a).size;i++){
        cout<<(*a).array[(*a).index[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
IndxCol *fill(int n){
    //Allocate memory
    IndxCol *col=new IndxCol;
    if(n<=1)n=2;
    (*col).size=n;
    (*col).array=new int[n];
    (*col).index=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        *((*col).index+i)=i;
        (*col).array[i]=rand()%90+10;
    }
    //Return the allocated and filled 
    return col;
}

