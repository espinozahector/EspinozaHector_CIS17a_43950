/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 3, 2015, 11:33 PM
 * Purpose: 
 */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;
void problem1();
//Problem 1 functions
int counter(string,int,float &);

void problem2();
//Problem 2 Functions
int cntVwl(string);
int cntCnst(string);
int cntBoth(string);

void problem3();
void problem4();
//Problem 4 functions
void ArryToF(ofstream &,int [],int);
void fileToA(ifstream &,int [],int);

void problem5();

int main(int argc, char** argv) {
    bool runagn = false;
    int choice;
    do{
        do{
            cout<<"1. Problem 1 \n2. Problem 2 \n3. Problem 3 \n4. Problem 4 \n5. Problem 5\n6. Exit\n";
            cin>>choice;
            cin.ignore();
            if(choice<1 || choice>6){
                cout<<"ERROR: Invalid input\n";
            }
        }while(choice<1 || choice>6);
        switch(choice){
            case 1: {
                cout<<"Problem 1\n";
                problem1();
                break;
            }
            case 2: {
                cout<<"Problem 2\n";
                problem2();
                break;
            }
            case 3: {
                cout<<"Problem 3\n";
                problem3();
                break;
            }
            case 4: {
                cout<<"Problem 4\n";
                problem4();
                break;
            }
            case 5: {
                cout<<"Problem 5\n";
                problem5();
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

void problem1(){
    cout<<"Gaddis Chapter 10 Problem 3 word counter\n";
    //Declare variables and pointers
    string *stptr;
    string text;
    float average;
    int sum=0;
    
    //Get information
    cout<<"Enter a phrase:\n";
    getline(cin,text);
    
    stptr=&text;//pointer = text by refrance
    //Output results
    cout<<"You have "<<counter(*stptr,sum,average)<<" words in your phrase"<<endl;
    cout<<"Average letter per word is "<<average<<endl<<endl;
}
int counter(string n,int sum, float &average){
    int count=0;
    string temp;
    n+=" ";
    for(int i=0;i<n.size();i++){
        if(n[i]==' '){
            if(temp.empty()){
                
            }else{
                count++;
                temp="";
            }
        }else temp+=n[i];
        if(n[i]!=' ')sum++;
    }
    average=static_cast<float>(sum)/count;
    return count;
}
void problem2(){
    cout<<"Gaddis Chapter 10 Problem 6"<<endl;
    char choice;
    bool again=true;
    string *stprt;
    string text;

    do{
        //Get information
        cout<<"Enter a phrase:\n";
        getline(cin,text);
        stprt= &text;
     do{
        do{

           //Menu
        cout<<"A. count the number of vowels in the string"<<endl;
        cout<<"B. count the number of constants in the string"<<endl;
        cout<<"C. count both the vowels and constants in the string"<<endl;
        cout<<"D. Enter another string"<<endl;
        cout<<"E. Exit the Program"<<endl;
        cin>>choice;
        cin.ignore();
        cout<<endl;

            if(choice<'A' && choice>'E' || choice<'a' && choice>'e'){
                cout<<"ERROR: you did not enter the appropiate menu"<<endl;
            }
        }while(choice<'A' && choice>'E' || choice<'a' && choice>'e');

            if(choice=='A' || choice =='a'){
                cout<<"Your string has "<<cntVwl(*stprt)<<" vowels"<<endl;
            }else if(choice=='B' || choice =='b'){
                cout<<"Your string has "<<cntCnst(*stprt)<<" constants"<<endl;
            }else if(choice=='C' || choice =='c'){
                cout<<"Your string has "<<cntBoth(*stprt)<<" constants and vowels"<<endl;
            }else if(choice=='D' || choice =='d'){
                  
            }else if(choice=='E' || choice =='e'){
                again=false;
            }
     }while(choice!='D' && choice!='d' && choice !='E' && choice!='e');
    }while(again==true);
}
int cntVwl(string words){
    int count=0;
    words+=" ";
    for(int i=0;i<words.size();i++){
        if(words[i]=='a' || words[i]=='A' || words[i]=='e' || words[i]=='E' ||
        words[i]=='i' || words[i]=='I' || words[i]=='o' || words[i]=='O' ||
        words[i]=='u' || words[i]=='U'){
            //add to count
            count++;
        }
    }
    return count;
}
int cntCnst(string words){
    int count=0;
    words+=" ";
    for(int i=0;i<words.size();i++){ 
        //Check if letter
        if(words[i]>='A' && words[i]<='Z' || words[i]>='a' && words[i]<='z'){
                
        if(words[i]!='a' && words[i]!='A' && words[i]!='e' && words[i]!='E' &&
           words[i]!='i' && words[i]!='I' && words[i]!='o' && words[i]!='O' &&
           words[i]!='u' && words[i]!='U' && words[i]!=' '){
            //add to count if constant
                count++;
        }
      }
    }
    return count;
}
int cntBoth(string words){
    int count=0;
    for(int i=0;i<words.size();i++){
        //Check for letter
        if(words[i]>='A' && words[i]<='Z' || words[i]>='a' && words[i]<='z'){
            count++;
        }
    }
    return count;
}
void problem3(){
    cout<<"Gaddis Chapter 12 Problem 7: Sentence Filter"<<endl;
    
    ifstream fin;
    ofstream fout;
    
    //Declare Variables
    string temp;
    bool isFrst=true;
    
    cout<<"Opening 'file1.txt'\n";
    fin.open("file1.txt");
    cout<<"opening 'file2.txt'\n\n";
    fout.open("file2.txt");
    
    while(getline(fin,temp)){
        
        for(int i=0;i<temp.size()-1;i++){
            if(!isFrst){
                if(temp[i]=='.'){
                    isFrst=true;
                }
                if(temp[i]!=' ' && temp[i]>='A' && temp[i]<='Z'){
                    temp[i]=temp[i]+32;
                    }
                }
            if(isFrst){
                if(temp[i]!=' ' && temp[i]>='a' && temp[i]<='z'){
                    temp[i]=temp[i]-32;
                    isFrst=false;
                }else if(temp[i]!=' ' && temp[i]>='A' && temp[i]<='Z'){
                    isFrst=false;
                }
            }
        }
        fout<<temp;
    }
    cout<<"Your files has completed the process and finished writing to 'file2.txt'"<<endl;
    cout<<"Both files have been completed"<<endl;
    fin.close();
    fout.close();
    cout<<endl;
}
void problem4(){
    cout<<"Gaddis Chapter 12 Problem 8"<<endl;
    //Declare pointer and dynamic array
    int *intptr;
    int size=5;
    intptr=new int [size];
    int mult;
    
    cout<<"What multiple of a number do you want store in the array? ";
    cin>>mult;
    for(int i=0;i<size;i++){
        intptr[i]=mult*(i+1);
    }
    
    //fstream variables
    ifstream fin;
    ofstream fout;
    
    cout<<"Writing the array to file 'array.txt'..."<<endl;
    ArryToF(fout,intptr,size);
    cout<<"Finished writing array to file."<<endl;
    cout<<endl;
    
    cout<<"Getting array from file 'array2.txt'"<<endl;
    fileToA(fin,intptr,size);
    cout<<"Finished grabbing array from file"<<endl;
    
    fin.close();
    fout.close();
    cout<<endl;
}
void ArryToF(ofstream &fout,int a[],int s){
    fout.open("array.txt", ios::out | ios::binary);
    
    for(int i=0;i<s;i++){
        fout<<a[i];
        fout<<' ';
    }
}
void fileToA(ifstream &fin,int a[],int s){
    fin.open("array2.txt", ios::in | ios::binary);
    
    int i=0;
    while(fin){
        fin>>a[i];
        i++;
    }
    cout<<"The array from file 'array2.txt'"<<endl;
    for(int i=0;i<s;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl<<endl;
}
void problem5(){
    cout<<"Gaddis Chapter 12 Problem 11"<<endl;
    
    struct division{
        string div [4]={"North","East","South","West"};
    };
    struct quarter{
        int quar=4;
    };
    struct sales{
        int sales[4];
    };
    
    //Declare Variables
    division d;
    quarter q;
    sales s;
    ofstream fout;
    
    //Open file
    cout<<"Opening 'sales.rtf'\n";
    fout.open("sales.rtf");
    
    //For loop to enter the sales for each division
    for(int i=0;i<q.quar;i++){
        for(int j=0;j<q.quar;j++){
        cout<<"Input the sales for division "<<i+1<<" quarter "<<j+1<<" $";
        cin>>s.sales[j];
        //Inputs into the file
        fout<<d.div[i]<<" division-quarter "<<j+1<<" sales $"<<s.sales[j]<<endl;
        }   
        cout<<endl;
        fout<<endl;
    }
    
    //Close file
    cout<<"Finished writing to 'sales.rtf'"<<endl;
    fout.close();
    cout<<endl;
}
    
