/* 
 * File:   Game.cpp
 * Author: Kauru99
 * 
 * Created on October 14, 2015, 9:15 PM
 */

#include <string>
#include <fstream>
#include <iostream>

#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(){
    //Set game completion and checkpoint to zero
    gCmplte = 0;
    gChckpt = 0;
}
void Game::modCmplte(int value){
    gCmplte += value;
}
void Game::setChckpt(int value){
    gChckpt = value;
}
bool Game::save(Player user){
    //Error checker
    bool error = true;
    //Create game save under the player name
    gFile = "deps/Saves/" + user.name();
    //Opens file
    gSave.open(gFile.c_str());
    
    //If file does not exist
    if(!gSave){
        //Prompt user and flag error
        error = false;
    }
    else{
        //Save user stats
        gSave << user.name() <<endl
                <<gCmplte <<endl
                <<gChckpt <<endl;
        //Retrieves all of the stats
        for (int i = 1; i < 13; i++){
            gSave <<user.getStat(i) <<endl;
        }
    }
    
    //Close the file
    gSave.close();
    
    //Returns error status
    return error;
}
bool Game::load(Player&user, string name){
    //Error checking flag
    bool error = true;
    //Variables to read content
    int cmplte, chckpt; //Game progress and checkpoint
    int stat; //User stats
    //File name
    gFile = "deps/Saves/" + name;
    
    //Open the file
    gLoad.open(gFile.c_str());
    
    //If the file does not exit
    if(!gLoad){
        //Prompt and flag for error
        error = false;
    }
    else{
        //Load information from file
        gLoad >>name >>cmplte >>chckpt;
        user.setName(name);
        gCmplte = cmplte;
        gChckpt = chckpt;
        
        //Sets all of the stats
        for(int i = 1; i < 13; i++){
            //Retrieves stat
            gLoad >> stat;
            //Assigns value to the correct stat
            user.setStat(i, stat);
        }
    }
    
    //Close the file
    gLoad.close();
    
    //Return error status
    return error;
}
int Game::getCmplte(){
    //Return game complete percentage
    return gCmplte;
}
int Game::getChckpt(){
    //Return game checkpoint
    return gChckpt;
}
