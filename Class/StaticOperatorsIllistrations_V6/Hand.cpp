/* 
 * File:   Hand.cpp
 * Author: rcc
 * 
 * Created on November 10, 2015, 11:18 AM
 */

#include "Hand.h"
       
Hand::Hand(){
    //Start constructing the Deck by initializing the properties
    recCard=0;
    nCards=5;
    card=new Card*[nCards];
}

Hand::~Hand(){
    //Deallocate Memory
    for(int i=0;i<recCard;i++){
        delete card[i];
    }
    delete []card;
}

char Hand::inspect(char num){
    if(num>nCards){
        return 0;
    }
    return card[num-1]->getNum();
}

void Hand::receive(int num){
    if(recCard>nCards)return;
    card[recCard++]=new Card(num);
}

Hand& Hand::operator--(){
    delete card[--recCard];
    return *this;
}