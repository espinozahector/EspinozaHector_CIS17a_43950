/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 17, 2015, 12:42 PM
 * Purpose: Find the number of modes
 */

//system libraries
#include <iostream>
#include <vector>
using namespace std;

//User libraries

//Global constants

//Function prototypes
void fillAry(int[],int,int);
void prntAry(int[],int);
void prntVec(vector<int>&);
void sortAry(int[],int);
float mean(int [],int);
float median(int [],int);

//Execution begins here
int main(int argc, char** argv) {
    bool plyagn=false;
    char choice1;
    
    do{
    //Declare variables
    int fcount=0,   //frequency
        mod=20,     //mod number for array
        mode=0,     //mode count
        size=50;    //size of array
    vector<int> freq;    //frequency of numbers
    char choice;    //user choice
    
    do{
        cout<<"Do you want to change the mod and SIZE of the array? [y]/[n]"<<endl;
        cout<<"Default mod is "<<mod<<" and default SIZE is "<<size<<endl;
        cin>>choice;
        if(choice!='Y' && choice!='y' && choice!='N' && choice!='n'){
            cout<<"You did not enter a [Y] or [N]"<<endl;
        }
    }while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');
    
    if(choice=='Y' || choice=='y'){
        cout<<"What number do you want for the mod?"<<endl;
        cin>>mod;
        
        cout<<"What size do you want the array to be?"<<endl;
        cin>>size;
    }
    
    int numbers[size]={}; //initialize the array.
    
    cout<<"Initial Array: "<<endl;
    fillAry(numbers,size,mod);
    prntAry(numbers,size);
    
    cout<<"Sorted Array: "<<endl;
    sortAry(numbers,size);
    prntAry(numbers,size);
    
    for(int i=0;i<size;i++){
        
        //if the current number equals the next number, add to frequency
        if(numbers[i]==numbers[i+1]){
            fcount++;
        }else {
            freq.push_back(fcount);
            fcount=0;
        }
    }
    
    prntVec(freq);
    
    int max=0;
    for(int i=0;i<freq.size();i++){
        if(freq[i]>max){
            max=freq[i];
        }
    }
    
    for(int i=0;i<freq.size();i++){
        if(max==freq[i]){
            mode++;
        }
    }
    cout<<"The mean is "<<mean(numbers,size)<<endl;
    cout<<"The median is "<<median(numbers,size)<<endl;
    cout<<"Number of Modes is "<<mode<<endl;
    do{
        cout<<"Do you want to re-run this program? [y]/[n]"<<endl;
        cin>>choice1;
        if(choice1!='Y' && choice1!='y' && choice1!='N' && choice1!='n'){
            cout<<"You did not enter a [Y] or [N]"<<endl;
        }
    }while(choice1!='Y' && choice1!='y' && choice1!='N' && choice1!='n');
        if(choice1=='N' || choice1=='n'){
            cout<<"Bye bye!!!"<<endl;
            plyagn=true;
        }
    }while(plyagn==false);
    return 0;
}
float median(int numbers[],int size){
    int pos1,pos2;
    float temp;
    if(size%2==1){
        temp=static_cast<float>(numbers[size/2]+numbers[size/2+1])/2;
    }
    else{
        temp=numbers[size/2];
    }
    return temp;
}
float mean(int numbers[],int size){
    int total=0;
    for(int i=0;i<size;i++){
        total=numbers[i]+total;
    }
    total=total/size;
    return total;
}

void prntVec(vector<int>& v){
    cout<<"Frequency of numbers: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

void sortAry(int x[],int size){
    for(int i=0;i<size;i++){
        int temp=0;
        for(int j=0;j<size-1;j++){
            if(x[j]>x[j+1]){
                temp=x[j+1];
                x[j+1]=x[j];
                x[j]=temp; 
            }
        }
    }
}

void prntAry(int x[],int size){
    for(int i=0;i<size;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void fillAry(int x[],int size,int j){
    for(int i=0;i<size;i++){
        x[i]=i%j;
    }
}