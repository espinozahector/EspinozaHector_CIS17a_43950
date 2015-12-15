/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 22, 2015, 10:12 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

//User Libraries
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

using namespace std;


/*
 * 
 */
//Creates new game
void newGme();
//Loads game
void loadGme();
//Basic level menu
void level(Player&, Game&, bool&);
//Arena function
void arena(Player&,Game&, bool&);
//Battle interface
void bttlUi(Player&,Enemy&, bool&);
//UI
void ui(string, Player, Enemy);
//Chapter one story
void chp1(Player&, Game&);
//Pseudo cls
void cls();
//Delays text for an indicated time
void delay(int); 

int main(int argc, char** argv) {
    srand(time(0));
    /*
    //User input
    int userIn;
    //Flag for exit
    bool quit = false;
  
    do{
        cout <<"======================" <<endl
                <<"       RPG Game" <<endl
                <<"======================" <<endl
                <<"       Menu" <<endl
                <<"----------------------" <<endl
                <<"1] New Game" <<endl
                <<"2] Load Game" <<endl
                <<"3] Quit" <<endl
                <<"----------------------" <<endl
                <<"Make your choice: ";
        cin >> userIn;

        switch (userIn){
            case 1:
                newGme();
                break;
            case 2:
                loadGme();
                break;
            case 3:
                quit = true;
                break;
            default:
                cout <<"Invalid input!" <<endl;
                delay(399999999);
                break;
        }
        cls();
    }while(!quit);
     */
    bool lvComp = false;
    Player hero;
    Enemy foe("Demon", 10, 50, 10, 0, 80, 10, 10, 10);
    bttlUi(hero, foe, lvComp);
    
    
    return 0;
}



void newGme(){
    //Variables for the player name and answer
    string name, ans;
    do{
        //Clear screen
        cls();
        //Prompt user
        cout <<"----------------------" <<endl
            <<"       New Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
        //Receives name
        cin >> name;
    
        //Prompt confirm 
        cout <<"Name: " <<name <<endl
                <<"Confirm (Y/N)? ";
        cin >> ans;
    
    //Repeat until player inputs yes
    }while(tolower(ans[0]) != 'y');
    
    //Initiate hero
    Player hero(name);
    //Initiate game
    Game rpg;
    //Save the game
    if(!rpg.save(hero)){
        //Prompt user if error
        cout <<"Error: Failed to create save file!" <<endl;
    }
    else{
        //Prompt successful save
        cout <<"Save successful!" <<endl;
        //Delay text
        delay(399999999);
        //Clear screen
        cls();
        
        //Begin game
        chp1(hero, rpg);
    }
}
void loadGme(){
    //Clear screen
    cls();
    //User name
    string name;
    //Prompt user
    cout <<"----------------------" <<endl
            <<"     Load Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
    //Input name of save
    cin >> name;
    
    //Initiate hero
    Player hero;
    //Initiate game
    Game rpg;
    //Load the game
    if(!rpg.load(hero, name)){
        //Prompt user when error
        cout <<"Error: File does not exist!" <<endl;
        delay(399999999);
    }
    else{
        //Prompt user when successful
        cout <<"Load successful"<<endl;
        delay(399999999);
    }
}

void level(Player&hero, Game&rpg, bool&lvComp){
    int ans;
    //Flag to allow the player to continue
    bool cont;
    
    cls();
    
    do{
        cont = false;
        
        
        cout <<"======================" <<endl
                    <<"       Barracks" <<endl
                    <<"======================" <<endl
                    <<"----------------------" <<endl
                    <<"1] Bed(Save)" <<endl
                    <<"2] Shop" <<endl
                    <<"3] Arena (Fight)" <<endl
                    <<"4] Main Menu" <<endl
                    <<"----------------------" <<endl
                    <<"Enter choice: ";
        cin >> ans;

        switch(ans){
            case 1:
                if(!rpg.save(hero)){
                    cout <<"Error: Failed to save game!" <<endl;
                    delay(399999999);
                }
                else{
                    cout <<"Save successful" <<endl;
                    delay(399999999);
                }
                break;
            case 2:
                
                break;
            case 3:
                arena(hero, rpg, lvComp);
                cont = true;
                break;
            case 4:
                return;
                break;
            default:
                cout <<"Invalid input!" <<endl;
                delay(399999999);
                break;
        }
        
        cls();
    }while(!cont);
    
}

void arena(Player &hero,Game &rpg, bool &lvComp){
    switch(rpg.getChckpt()){
        case 0:
            //Dialogue
            cout <<"Fight 1" <<endl;
            
            //Create enemy
            Enemy foe("Demon", 10, 50, 10, 3, 80, 10, 10, 10);
            bttlUi(hero, foe, lvComp);
            
            
            
            break;
    }
}

void bttlUi(Player &hero,Enemy &foe, bool &lvComp){
    int choice;
    //Input validation
    bool inVal;
    
    
    do{
        do{
            cls();
            ui("Fight!", hero, foe);
            cout <<"1] Attack" <<endl
                <<"2] Guard" <<endl
                <<"3] Action" <<endl
                <<"----------------------------"
                <<"----------------------------" <<endl
                <<"Enter: ";
            cin >> choice;


            inVal = true;

            switch(choice){
            case 1:
                cls();
                ui("Attack!", hero, foe);
                cout <<hero.name() <<" attacks!" <<endl;
                delay(399999999);
                cout <<foe.name() <<" receives " <<foe.dmged(hero.attck())
                        <<" damage!" <<endl;
                delay(399999999);
                break;
            case 2:
                cls();
                ui("Guard", hero, foe);

                break;
            case 3:
                cls();
                ui("Action", hero, foe);
                
                break;
            default:
                cout <<"Invalid input!" <<endl;
                inVal = false;
                delay(399999999);
                break;
            }

        } while(!inVal);
        
        if(foe.dead()){
            cout << foe.name() <<" has fallen!" <<endl;
            delay(399999999);
        }
    }while(!hero.dead() && !foe.dead());
    
            
}
void ui(string title, Player hero, Enemy foe){
    cout <<"============================" 
            <<"============================" <<endl
            <<right <<setw(30)<<title <<endl
            <<"============================" 
            <<"============================" <<endl
            <<left <<hero.name() 
            <<right <<setw(52) 
            <<foe.name() <<endl
            <<left <<"HP: " <<hero.getCHlth() <<"/" <<hero.getMxHlth() 
            <<right <<setw(40) 
            <<foe.getCHlth() <<"/" <<foe.getMxHlth() <<" :HP"<<endl
            <<left <<"Stamina: " <<hero.getStmna() 
            <<right <<setw(36)
            <<foe.getStmna() <<" :Stamina" <<endl
            <<"----------------------------"
            <<"----------------------------" <<endl;
}

void chp1(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //Dialogue
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"You died!" <<endl <<"Game Over!" <<endl;
            //Delay text
            delay(399999999);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        
        //Increment percentage completed
        rpg.modCmplte(10);
        //Set checkpoint to chapter 2
        rpg.setChckpt(2);
        //Chapter 2 function
    }
    
}



void cls(){
    for(int i = 0; i < 10; i++){
        cout <<endl;
    }
}

void delay(int time){
    //Delay the text for the indicated time
    for(int i = 0; i < time; i++){}
}