/* 
 * File:   Human.cpp
 * Author: Hector Espinoza
 * Created on December 8, 2015, 3:57 PM
 */

#include "Player.h"

Player::Player() {
    //sets the whole array to 0
    for(int i=0;i<SIZE;i++){
        move[i] = 0;
    }
}
const int Player::SIZE = 40;
