/* 
 * File:   Hand.h
 * Author: rcc
 *
 * Created on November 10, 2015, 11:18 AM
 */

#ifndef HAND_H
#define	HAND_H

#include "Card.h"

class Hand{
   private:
       int nCards;
       Card **card;
       char recCard;
   public:
       Hand();
       ~Hand();
       Hand& operator--();
       Hand operator--(int);
       char inspect(char);
       void receive(int);
       int getNCrd(void){return recCard;};
};

#endif	/* HAND_H */