/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on September 24, 2015, 12:42 PM
 * Purpose: Chapter 9 Pointers and Dynamic Arrays
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void problem1();
//Problem 1 functions
void sort(int [], int);
void print(int [], int);
void problem2();
void problem3();

//Execution Begins Here!!
int main(int argc, char** argv) {
    int choice;
    do{
        do{
            cout<<"1. Problem 1\n2. Problem 2\n3. Problem 3\n-1 to terminate\n";
            cin>>choice;

            if(choice!=-1 && choice <1 && choice>3){
                cout<<"You did not choose 1, 2, 3, or -1"<<endl;
            }

            }while(choice!=-1 && choice <1 && choice>3);

                switch(choice){
                    case 1:problem1();break;
                    case 2:problem2();break;
                    case 3:problem3();break;
                    default: cout<<"Bye bye!!"<<endl;

                }
    
    }while(choice!=-1);
    return 0;
}
void problem1(){
    cout<<"Problem 1"<<endl;
//2. Test Scores #1 
//Write a program that dynamically allocates an array large enough to hold a user-
//defined number of test scores. Once all the scores are entered, the array should be 
//passed to a function that sorts them in ascending order. Another function should be 
//called that calculates the average score. The program should display the sorted list of 
//scores and averages with appropriate headings. Use pointer notation rather than array 
//notation whenever possible. 
//Input Validation: Do not accept negative numbers for test scores.

    int  *scores,        // To dynamically allocate an array
         total=0,        // Accumulator
         average=0,      // To hold average test score
         numTests;       // To hold number of tests
    int test;            //To hold the test score
    do{ 
         cout<<"Enter the number of test scores: ";
         cin>>numTests;
         
         if(numTests<0){
            cout<<"Invalid number of test scores.";
            cout<<"Enter a positive number of test scores."<<endl;
         }
    }while(numTests<0);
    cout<<endl;

    // dynamically allocates an array to numTest
    scores=new int [numTests];
    
    // Get the scores for each test
    cout<<"Enter the test scores:\n";
    do{
        for (int i=0;i<numTests;i++){
            cout<<"Test "<<(i+1)<<": ";
            cin>>test;
            
            if(test>=0){
                scores[i]=test;
            }
            if(test<0){
            cout << "Invalid test score. Enter a positive test scores." << endl;
            i=i-1;
            }
        }
    }while (test<0);

    // Sorts the array
    sort(scores, numTests);

    //Total of all scores
    for (int i=0;i<numTests;i++){
        total+=scores[i];
    }

    // Calculates the average of the test scores
    average=total / numTests;

    //Output 
    cout<<"\nTests scores: ";
    print(scores, numTests);
    cout<<"Average score: "<<average<<endl;

    //Deletes the memory
    delete [] scores;
    scores=0;
}

void sort(int array[], int size){
    int temp;
    bool swap;

    do{
        swap = false;
        for (int i=0;i<(size - 1);i++){
            if (array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap=true;
            }
        }
    }
    while(swap);
}

void print(int array[], int size){
    for (int i=0;i<size;i++){
    cout<<array[i]<<" ";
    cout<<endl;
    }
}

void problem2(){
    cout<<"Problem 2"<<endl;
    cout<<"Savitch 9th Edition Chapter 9 Problem 5"<<endl;
    //Declare the functions
    int num=4;
    int com[num]={5,6,4,3};
    int **temp;
    temp = new int *[num];
    for(int i=0;i<4;i++){
        temp[i] = new int [com[i]];
    }
    int choice; 
    bool again=true;
    int stat; //Computer station
    int   id, //Student ID
          lab; //Lab1-4
    do{
            cout<<endl;
            for(int i=0;i<num;i++){
                cout<<"Lab "<<i+1<<' ';
                for(int j=0;j<com[i];j++){
                    cout<<j+1<<": ";
                    if(temp[i][j]==0)cout<<"Empty ";
                    else cout<<temp[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<endl;
        do{
            cout<<"1. Log on\n2. Log off\n3. Exit!\n";
            cout<<"What would you like to do?:";
            cin>>choice;
                if(choice<1 && choice>3){
                    cout<<"ERROR: You did not enter a proper selection\n";
                }
        }while(choice<1 && choice>3);
        switch(choice){
            case 1:{
                again=true;
                int check;
                cout<<"What is your ID number?:";
                cin>>id;
                
                do{
                    cout<<"What lab are you in?: ";
                    cin>>lab;
                    cout<<endl;
                    if(lab>num){
                        cout<<"ERROR!!There are only "<<num<<" labs"<<endl;
                    }
                }while(lab<1 || lab>num);
                bool good =true;
                //Validate if their are the right amount of stations to lab
                do{
                    cout<<"What computer are you logging into?: ";
                    cin>>stat;
                    
                    if(lab==1){
                        check=5;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }else if(lab==2){
                        check=6;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }else if(lab==3){
                        check=4;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }   
                    }else if(lab==4){
                        check=3;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }
                }while(good==false);     
                //Validate to check if the station is already taken
                if(temp[lab-1][stat-1]!=0){
                    cout<<endl<<"Someone is already logging in to that station!!!"<<endl;
                }else temp[lab-1][stat-1]=id;
                break;
            }
            case 2:{
                int check;
                again=true; 
                do{
                    cout<<"What lab are you in?: ";
                    cin>>lab;
                    cout<<endl;
                    if(lab>num){
                        cout<<"ERROR!!There are only "<<num<<" labs"<<endl;
                    }
                }while(lab<1 || lab>num);
                bool good =true;
                //Validate if their are the right amount of stations to lab
                do{
                    cout<<"What computer are you logging into?: ";
                    cin>>stat;

                    if(lab==1){
                        check=5;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }else if(lab==2){
                        check=6;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }else if(lab==3){
                        check=4;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }   
                    }else if(lab==4){
                        check=3;
                        if(stat>check){
                            good=false;
                            cout<<"ERROR!!There is no station "<<stat<<" in lab "<<lab<<endl;
                        }else{
                            good=true;
                        }
                    }
                }while(good==false);     

                if(temp[lab-1][stat-1]!=0){
                    temp[lab-1][stat-1]=0;
                    cout<<"You have logged off"<<endl;
                }else{
                    cout<<endl<<"There is no login account for that computer station!"<<endl;
                }
            break;
        }
        case 3: again=false;
            break;
        default:{
            cout<<"ERROR: Program will self-destruct"<<endl;
            for(int i =10;i>0;i--){
            cout<<"In T-Minus "<<i<<" seconds"<<endl;
            }
            cout<<"KABOOM!!!\n";
            }
        }         
    }while(again);
}
void problem3(){
    cout<<"Problem 3"<<endl;
//4. Write a function that takes a C string as an input parameter and reverses the
//string. The function should use two pointers, front and rear. The front pointer 
//should initially reference the first character in the string, and the rear pointer 
//should initially reference the last character in the string. Reverse the string 
//by swapping the characters referenced by front and rear, then increment front
//to point to the next character and decrement rear to point to the preceding 
//character, and so on, until the entire string is reversed. Write a main program 
//to test your function on various strings of both even and odd length.
    char array[10]="Hello";
    char *ptr1;
    char *ptr2;
    
    ptr1=&array[0];
    ptr2=&array[5];
    
//    cout<<array[1];
    cout<<*ptr1;
    cout<<sizeof(array);
    cout<<*ptr2;
    //USED TO LEARN POINTERS
//    int x=25;
//    int *ptr=0;
//    ptr=&x;
//    
//    cout<<x<<endl;
//    cout<<*ptr;
    
//    int size=6;
//    char word[size]={"Hello"};
//    char *first;
//    char *last;
//    char temp;
////    for(int i=0;i<sizeof(word);i++){
////        for(int j=sizeof(word);j>0;j--){
//            *first=word[1];
//            *last=word[5];
//            //Swap
//            temp=*first;
//            *first=*last;
//            *last=temp;
////        }  
//            for(int i=0;i<sizeof(word);i++){
//        cout<<word[i]<<" ";
//            }
////    }
//    
    cout<<endl;
}

