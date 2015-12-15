/* 
 * File:   Human.cpp
 * Author: Hector Espinoza
 * Created on December 8, 2015, 3:57 PM
 */

#ifndef HUMAN_H
#define	HUMAN_H

#include "Player.h"

class Human : public Player {
public:
    Human();
    void setmoney(int);
    void setloc(int);
    void setroll(int);
    int getMoney() { return bal; }
    int getloc() { return loc; }
    int getroll() { return roll; }

};

#endif	/* HUMAN_H */

