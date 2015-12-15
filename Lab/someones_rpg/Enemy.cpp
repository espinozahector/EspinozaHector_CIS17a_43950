/* 
 * File:   Enemy.cpp
 * Author: rcc
 * 
 * Created on October 14, 2015, 10:46 AM
 */
#include <cstdlib>
#include <string>

#include "Enemy.h"

using namespace std;

Enemy::Enemy(string name, int mxHlth, int stmna,  int str, int 
def, int acc, int dex, int intl, int luc){
    eName = name;
    
    eMxHlth = mxHlth;
    eCHlth = eMxHlth;
    eStmna = stmna;
    
    eStr = str;
    eDef = def;
    eAcc = acc;
    eDex = dex;
    eInt = intl;
    eLuc = luc;
    
    eDead = false;
}
string Enemy::name(){
    return eName;
}
int Enemy::getMxHlth(){
    return eMxHlth;
}
int Enemy::getCHlth(){
    return eCHlth;
} 
int Enemy::getStmna(){
    return eStmna;
}
int Enemy::attck(){
//Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = eStr*0.7;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < eLuc){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > eAcc){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
} 
int Enemy::dmged(int pAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = pAtt - eDef; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < eDex * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    eCHlth -= dmg;
    
    //If the health drops below zero
    if(eCHlth < 0){
        //Set health to zero
        eCHlth = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;
}
bool Enemy::dead(){
    if(eCHlth < 1){
        eDead = true;
    }
    return eDead;
}
int Enemy::choice(){
    //Enemy's chosen input
    int eIn;
    
    //If current health is less than 10% of max hp
    if(eCHlth < static_cast<float>(eMxHlth)*0.10){
        //Select to heal
        eIn = 4;
    }
}
