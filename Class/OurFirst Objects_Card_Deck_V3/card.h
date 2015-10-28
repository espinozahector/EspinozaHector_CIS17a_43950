/* 
 * File:   card.h
 * Author: Hector Espinoza
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Specification for the card class
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        char number; 
        void setNum(char);                 //Mutator/utility
    public:
        Card(char);                        //Constructor
        char getNum(){return number;}      //Accessor (in-line))
        char suit();                       //Suit property
        char numVal();                     //Numerical Value Property
        char faceVal();                    //Face value property
};


#endif	/* CARD_H */

