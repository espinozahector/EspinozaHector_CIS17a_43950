/* 
 * File:   Player.cpp
 * Author: rcc
 * 
 * Created on October 14, 2015, 10:27 AM
 */

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(){
    pName = "Hero"; //Player Name
    
    pMxHlth = 10; //Max Health
    pCHlth = 10; //Current Health
    pStmna = 10; //Stamina
    
    pStr = 5; //Strength
    pDef = 5; //Defense
    pAcc = 70; //Accuracy
    pDex = 5; //Dexterity
    pInt = 5; //Intelligence
    pLuc = 5; //Luck
    
    pCExp = 0; //Current Experience
    pMxExp = 100; //Max Experience to level
    pLvl = 1; //Current level
    
    pDead = false;
}
Player::Player(string name){
    pName = name; //Player Name
    
    pMxHlth = 10; //Max Health
    pCHlth = 10; //Current Health
    pStmna = 10; //Stamina
    
    pStr = 5; //Strength
    pDef = 5; //Defense
    pAcc = 70; //Accuracy
    pDex = 5; //Dexterity
    pInt = 5; //Intelligence
    pLuc = 5; //Luck
    
    pCExp = 0; //Current Experience
    pMxExp = 100; //Max Experience to level
    pLvl = 1; //Current level
    
    pDead = false;
}
string Player::name(){
    return pName;
}
void Player::setName(string name){
    pName = name;
}

int Player::getCHlth(){
    return pCHlth; //Returns current health
}
int Player::getMxHlth(){
    return pMxHlth; //Returns the max health
}
void Player::modHlth(int value){
    pMxHlth += value; //Sets max health
}
int Player::getStmna(){
    return pStmna;
}
int Player::attck(){
    //Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = pStr*0.7;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < pLuc){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > pAcc){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
}
int Player::dmged(int eAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = eAtt - pDef; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < pDex * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    pCHlth -= dmg;
    
     //If the health drops below zero
    if(pCHlth < 0){
        //Set health to zero
        pCHlth = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;
}

void Player::modStat(int str, int def, int acc, int dex, int intl, int luc){
    pStr += str; // Modifies strength
    pDef += def; // Defense
    pAcc += acc; // Accuracy
    pDex += dex; // Dexterity
    pInt += intl; // Intelligence
    pLuc += luc; //Luck
}
void Player::seeStat(){
    int quit = 0;
    do{
        cout <<"--------------------------------" <<endl
                <<"============ Stats =============" <<endl
                <<"Name: " <<pName <<setw(10) <<"Lvl: " <<pLvl <<endl
                <<"Hp: " <<pCHlth <<"/" <<pMxHlth
                <<setw(10) <<"Exp: " <<pCExp <<"/" <<pMxExp <<endl
                <<"--------------------------------" <<endl
                <<"Str: " <<pStr <<endl
                <<"Def: " <<pDef <<endl
                <<"Acc: " <<pAcc <<endl
                <<"Dex: " <<pDex <<endl
                <<"Int: " <<pInt <<endl
                <<"Luc: " <<pLuc <<endl
                <<"--------------------------------" <<endl
                <<"================================" <<endl;
        cout <<"Enter -1 to quit: ";
        cin >> quit;
    }while(quit != -1);
    cls();
}
int Player::getStat(int stat){
    //Returns the given stat
    switch(stat){
        case 1:
            return pMxHlth;
            break;
        case 2:
            return pCHlth;
            break;
        case 3:
            return pStmna;
            break;
        case 4:
            return pStr;
            break;
        case 5:
            return pDef;
            break;
        case 6:
            return pAcc;
            break;
        case 7:
            return pDex;
            break;
        case 8:
            return pInt;
            break;
        case 9:
            return pLuc;
            break;
        case 10:
            return pMxExp;
            break;
        case 11:
            return pCExp;
            break;
        case 12:
            return pLvl;
            break;
    }
}
void Player::setStat(int stat, int value){
    //Set the indicated stat with the given value
    switch(stat){
        case 1:
            pMxHlth = value;
            break;
        case 2:
            pCHlth = value;
            break;
        case 3:
            pStmna = value;
            break;
        case 4:
            pStr = value;
            break;
        case 5:
            pDef = value;
            break;
        case 6:
            pAcc = value;
            break;
        case 7:
           pDex = value;
            break;
        case 8:
            pInt = value;
            break;
        case 9:
            pLuc = value;
            break;
        case 10:
            pMxExp = value;
            break;
        case 11:
            pCExp = value;
            break;
        case 12:
            pLvl = value;
            break;
    }
}

bool Player::setExp(int exp){
    pCExp += exp; //Sets experience to current exp level
    
    if(pCExp > pMxExp){ //If the current exp exceeds the max exp
        pCExp -= pMxExp; //Assigns excess exp to current level
        return true; //Level up is true
    }
    
    return false; //Level up is false
}
void Player::lvlUp(){
    int pts = 5, pIn; //Points to distribute and player input
    int str = 0, def = 0, acc = 0, dex = 0, intl = 0, luc = 0; //Stat pts
   
    string quit; //String for confirming quit
    
    pLvl++; //Increment lvl up
    
    do{
        //Displays level up screen
        cout <<"Level up!" <<endl
                <<"Distribute your stats! Points: " <<pts <<endl
                <<"---------------------------------------" <<endl
                <<"[1] Str: " <<pStr <<" + (" <<str <<")" <<endl
                <<"[2] Def: " <<pDef <<" + (" <<def <<")" <<endl
                <<"[3] Acc: " <<pAcc <<" + (" <<acc <<")" <<endl
                <<"[4] Dex: " <<pDex <<" + (" <<dex <<")" <<endl
                <<"[5] Int: " <<pInt <<" + (" <<intl <<")" <<endl
                <<"[6] Luc: " <<pLuc <<" + (" <<luc <<")" <<endl
                <<"---------------------------------------" <<endl;
        
        
        if(pts > 0){ //If the user still has points to distribute
            //User selects a stat to raise
            cout <<"Select a stat: "; 
            cin >> pIn;
            
            //Distributes the point
            switch(pIn){
                case 1: //Strength
                    str++;
                    pts--;
                    break;
                    
                case 2: //Defense
                    def++;
                    pts--;
                    break;
                    
                case 3: //Accuracy
                    acc++;
                    pts--;
                    break;
                    
                case 4: //Dexterity
                    dex++;
                    pts--;
                    break;
                    
                case 5: //Intelligence
                    intl++;
                    pts--;
                    break;
                    
                case 6: //Luck
                    luc++;
                    pts--;
                    break;
            }
        }
        else{ //Else if the user is out of points
            //Prompt to confirm selection
            cout <<"Confirm (Y/N)? ";
            cin >> quit;
            
            //If the user does not select to quit
            if(tolower(quit[0]) != 'y'){
                //Reset stats
                str = 0;
                def = 0;
                acc = 0;
                dex = 0;
                intl = 0;
                luc = 0;
                
                //Reset points
                pts = 5;
            }
            else{ //If the user does select to quit
                //Modify max health
                modHlth(10);
                //Modify the stats by the selected values
                modStat(str,def,acc,dex,intl,luc);
            }
        }
                
        cls();
    }while(tolower(quit[0]) != 'y');
}
int Player::getLvl(){
    return pLvl; //Returns the player's level
}
bool Player::dead(){
    if(pCHlth < 1){
        pDead = true;
    }
    //Returns death flag
    return pDead;
}

void Player::cls(){
    for(int i = 0; i < 10; i++){
        cout <<endl;
    }
}

