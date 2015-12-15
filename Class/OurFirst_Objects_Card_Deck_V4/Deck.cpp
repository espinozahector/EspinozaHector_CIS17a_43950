/* 
 * File:   card.h
 * Author: Hector Espinoza
 * Created on October 22, 2015, 11:58 AM
 * Purpose: Implementation for the Deck class
 */

#include <cstdlib>
#include "Deck.h"

Deck::Deck(){
    //Start constructing the Deck by initializing the properties
    card=new Card*[nCards];
    indx-new char[nCards];
    dltCard=0;
    nCards=52;
    //Loop and create the cards and the indx
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i+1);
        indx[i]=i;
    }
}

Deck::~Deck(){
    //Deallocate memory
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete[]card;
    delete[]indx;
}
void Deck::shuffle(){
    //shuffles the whole deck 7 times
    for(int i=1;i<=7;i++){
        for(int j=0;j<nCards;j++){
            int rnd=rand()%nCards;
            int temp=indx[j];
            indx[j]=indx[rnd];
            indx[rnd]=temp;
        }   
    }
}
char Deck::deal(){
//    if(dltCard>.9*nCards){
//        
//    }
    return indx[dltCard++];   
}
int Deck::getNCrd(){
    return nCards;
}