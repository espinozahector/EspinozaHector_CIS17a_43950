/* 
 * File:   Gaming.cpp
 * Author: Hector
 * Created on December 10, 2015, 3:29 PM
 */

#include "Gaming.h"

Gaming::Gaming() {
    who=true;
    prison=true;
    cprison=true;
    game=true;
    turn=1;
}
void Gaming::setwho(bool w){
    who = w;
}
void Gaming::setprison(bool p){
    prison = p;
}
void Gaming::setcprison(bool c){
    cprison = c;
}
void Gaming::setgame(bool g){
    game = g;
}
void Gaming::setturn(int t){
    turn = t;
}


