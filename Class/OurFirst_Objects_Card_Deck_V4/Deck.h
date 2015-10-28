/* 
 * File:   card.h
 * Author: Hector Espinoza
 * Created on October 22, 2015, 11:58 AM
 * Purpose: Specification for the Deck class
 */


#ifndef DECK_H
#define	DECK_H

#include "card.h"
#include "Deck.h"

class Deck{
    private: 
        int nCards;
        Card **card; 
        char *indx;
        char dltCard;
    public:
        Deck();
        ~Deck();
        void shuffle();
        char deal();
        int getNCrd();
};

#endif	/* DECK_H */

