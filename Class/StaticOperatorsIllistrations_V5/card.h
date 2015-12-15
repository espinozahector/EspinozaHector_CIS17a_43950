/* 
 * File:   card.h
 * Author: Hector Espinoza
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Specification for the card class
 * Modified on November 5, 2015
 */

#ifndef CARD_H
#define	CARD_H

using namespace std;

class Card{
    private:
        char number; 
        void setNum(char);                 //Mutator/utility
        static int count; //count the number of objects
//        static std::string bgd; //background file
    public:
        Card(char);                        //Constructor
        char getNum(){return number;}      //Accessor (in-line))
        char suit();                       //Suit property
        char numVal();                     //Numerical Value Property
        char faceVal();                    //Face value property
        static int getCnt(){return count;}//retrive the static count
//        static std::string getBgd(){return bgd;}//background file
};

#endif	/* CARD_H */