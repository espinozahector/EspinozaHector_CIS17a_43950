/* 
 * File:   Player.h
 * Author: rcc
 *
 * Created on October 14, 2015, 10:27 AM
 */

#include <string>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
public:
    Player(); //Base constructor
    Player(string); //Constructor for new game
    
    string name();//Return's player name
    void setName(string); //set player name
    
    int getCHlth();//Returns player's current health
    int getMxHlth();//Returns player's max health
    void modHlth(int);//Modifies player's max health
    
    int getStmna(); //Returns the player's stamina
    
    int attck(); //Sets the damage
    int dmged(int); //Calculates incoming damage 
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int); //Returns the indicated stat
    void setStat(int, int); //Set the indicated stat
    
    bool setExp(int); //Calculates added exp
    void lvlUp(); //Level up 
    int getLvl(); //Returns level
    
    bool dead(); //Returns death flag
    
    
private:
    void cls();
    
    string pName; //Player name
    int pMxHlth, pCHlth, pStmna; //Player max/current health and stamina
    int pStr, pDef, pAcc; //Combat stats
    int pDex, pInt, pLuc; //Social stats
    int pCExp, pMxExp, pLvl; //Current/max experience and level
    
    //Flag for player death
    bool pDead;
};


#endif	/* PLAYER_H */

