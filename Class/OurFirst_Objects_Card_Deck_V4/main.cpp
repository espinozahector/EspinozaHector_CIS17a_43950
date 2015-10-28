/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Creation of first object oriented program
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Deck.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    //Declare some variables
    Deck deck();

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check\n";
    for(int i=0;i<deck.getNCrd();i++){
        Card card(deck.deal()+1);
        cout<<"Card Number = "<<static_cast<int>(card.getNum());
        cout<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }
    
    //Output the array
//    cout<<endl<<endl<<"After Shuffle\n";
//    for(int i=0;i<nCards;i++){
//        cout<<"Card Number = "<<static_cast<int>(card[indx[i]]->getNum());
//        cout<<" Suit = "<<card[indx[i]]->suit();
//        cout<<" Numerical Value = "<<static_cast<int>(card[indx[i]]->numVal());
//        cout<<" Face Value = "<<card[indx[i]]->faceVal()<<endl;
//    }
    //Exit Stage Right!
    return 0;
}
