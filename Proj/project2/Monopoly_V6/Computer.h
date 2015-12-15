/* 
 * File:   Computer.h
 * Author: rcc
 *
 * Created on December 9, 2015, 2:03 PM
 */

#ifndef COMPUTER_H
#define	COMPUTER_H

#include "Player.h"

class Computer : public Player{
public:
    Computer();
    void setmoney(int);
    void setloc(int);
    void setroll(int);
    int getMoney() { return bal; }
    int getloc() { return loc; }
    int getroll() { return roll; }

};

#endif	/* COMPUTER_H */

