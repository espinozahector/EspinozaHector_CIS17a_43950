/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 9, 2015, 11:40 PM
 * Purpose: Monopoly
 */

/*
 * 1. Need to move spaces
 * 2. If statments for chance and community chest and income tax luxury tax and jail
 * 3. Output the board
 * 4. Jail and missing a turn
 * 5. Score??(input to a file and cout the file at the end)
 * 6. Buy property
 * 7. rent 
 * 8. bonus: selling price of property,buying houses
 * 9. determine the winner(let the user exit sooner and winner be determined by who has more money)
 *    (otherwise is determined when one player has 0.)
 * 10. When the computer will buy his property.
 * 11.
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
//#include <vector>
using namespace std;
#include "House.h"

unsigned char roll(unsigned char,unsigned char);
void move(int,int &,int &);
void chance(int,int,int,int);




int main(int argc, char** argv) {
    //Set the random number seed and size the array
    srand(static_cast<unsigned int>(time(0)));
    
    const int SIZE=40;//size of the board
    bool gameovr=false;
    char buyansw;
    int choice;//play game or see the rules
    int answ;//answer to roll,buy or end turn
    
    
    int p1=0,c1=0; //player 1 computer 1
    int p1loc=0,c1loc=0;//location on the board where player 1 and computer are
    int p1bal=1500,c1bal=1500;//total balance of both players
    
    ifstream fin;//file input
    string temp;//string temp for the file
    
    House *board=new House[SIZE];
//    vector <int> p1prop;
//    vector <int> c1prop;
    int pmove[SIZE];//player 1 moves
    int cmove[SIZE];//computer1 moves
    //sets the whole array to 0
    for(int i=0;i<SIZE;i++){
        pmove[i]=cmove[i]=0;
    }
    bool avail[SIZE];//if the house is owned or available
   //sets the whole board to true available to buy
    for(int i=0;i<SIZE;i++){
        avail[i]=true;
    }
    //Sets the chance,go,income tax, etc to not able to buy
    avail[1]=false;
    avail[3]=false;
    avail[5]=false;
    avail[8]=false; 
    avail[11]=false;
    avail[18]=false;
    avail[21]=false;
    avail[23]=false;
    avail[31]=false;
    avail[34]=false;
    avail[37]=false;
    avail[39]=false;
    
    string property[40]={"Go","Mediterranean Avenue","Community Chest","Baltic Avenue"," Income Tax","Reading Railroad",
                         "Oriental Avenue","Chance","Vermont Avenue","Connecticut Avenue","Jail","St. Charles Place",
                         "Electric Company","States Avenue"," Virginia Avenue","Pennsylvania RailRoad","St. James Place",
                         "Community Chest","Tennessee Avenue"," New York Avenue","Free Parking","Kentucky Avenue","Chance",
                         "Indiana Avenue","Illinois Avenue"," B. & O. Railroad","Atlantic Avenue","Ventnor Avenue",
                         "Water Works","Marvin Gardens","Go to Jail","Pacific Avenue","North Carolina Avenue",
                         "Community Chest","Pennsylvania Avenue","Short Line","Chance","Park Place","Luxury Tax","BoardWalk"};
    int buy[SIZE]={0,60,0,60,0,200,100,0,100,120,0,140,150,140,160,200,180,0,180,
                   200,0,220,0,220,240,200,260,260,150,280,0,300,300,0,320,200,0,350,0,400};
    int rent[SIZE]={0,20,0,40,0,25,60,0,60,80,0,100,75,100,120,250,140,0,140,160,
                    0,180,0,180,200,250,220,220,75,240,0,260,260,0,280,250,0,350,0,500};
    
    for(int i=0;i<SIZE;i++){
    board[i].setName(property[i]);
    board[i].setBuy(buy[i]);
    board[i].setRent(rent[i]);
    
    }
//    for(int i=0;i<SIZE;i++){
//        board[i].print();
//        cout<<endl;
//    }
    
    
    cout<<"Welcome to the Monopoly game!!!\n";
    cout<<"Each player starts off with $1500\n";
    do{
        do{
        cout<<"1. Play the game\n2. See rules\n";
        cin>>choice;
        }while(choice<1 || choice>2);
        cout<<"Player 1 goes first\n";
        switch(choice){
            case 1:{
                do{
                p1=roll(6,2);
                cout<<"Player 1 you rolled your dice and got "<<p1<<endl;
                cout<<"Move forward "<<p1<<" spaces."<<endl;
                p1loc+=p1;
                pmove[p1loc]=1;
                for(int i=0;i<SIZE;i++){
                    cout<<pmove[i]<<' ';
                    }
                    cout<<endl;
                do{
                    cout<<"1. Buy Property\n2. End Turn\n";
                    cin>>answ;
                    switch(answ){
                        case 1: {
                            if(avail[p1loc]==false){
                                cout<<"You cannot buy this property\n";
                            }else if(avail[p1loc]==true){
                                cout<<"You can buy this property\n";
                                board[p1loc].print();
                                do{
                                    cout<<"Press 'Y' if you want to buy this property,or 'N' if you do not\n";
                                    cin>>buyansw;
                                    if(buyansw!='Y' && buyansw!='y' && buyansw!='N' && buyansw!='n'){
                                        cout<<"Invalid Input\n";
                                    }
                                }while(buyansw!='Y' && buyansw!='y' && buyansw!='N' && buyansw!='n');
                                if(buyansw=='Y' && buyansw=='y'){
                                    cout<<"You purchased "<<property[p1loc];
                                    avail[p1loc]=false;//Is no longer available
//                                    p1prop.push_back(p1loc); 
                                }
                            }
                            break;
                        }
                        case 2:{
                            cout<<"Turn Ended\n";
                            break;
                        }
                        default: cout<<"Error: In the switch statment\n";
                    }
                }while(answ!=2);
                //computers turn
                cout<<"It is the computers turn\n";
                c1=roll(6,2);
                
                //Determine the winner
                if(p1bal<=0){
                    cout<<"You lose!!"<<endl;
                    gameovr=true;
                }else if(c1bal<=0){
                    cout<<"You win!!"<<endl;
                    gameovr=true;
                }
                
                }while(gameovr==false);
                break;
            }
            case 2:{
                cout<<endl;
                //Cout the rules    
                fin.open("rules.txt");
                if(fin.is_open()){
                    while(getline(fin,temp)){
                        cout<<temp<<endl;
                    }
                }
                fin.close();
                break;
            }
            default: cout<<"Error: In the switch Statement\n";
        }
    }while(choice!=1);
    
    delete []board;
    return 0;
}
void chance(int p1bal,int c1bal,int p1,int c1,int b[40]){
    int random=rand()%12+1;
    cout<<random;
    switch(random){
        case 1:{
            cout<<"Chance: Convicted of Identity theft, Go to Jail. Do not pass go. Do not collect $200\n";
            break;
        }
        case 2:{
            cout<<"Chance: A group of guest wins a class action suit against your hotel pay each player $500\n";
            p1bal-=500;
            c1bal+=500;
            break;
        }
        case 3:{
            cout<<"Chance: Ride First class to reading railroad. If you pass go collect $200\n";
            break;
        }
        case 4:{
            cout<<"Chance: Make a donation for disaster relief. Pay $150\n";
            p1bal-=150;
            break;
        }
        case 5:{
            cout<<"Chance: Get a tax break for driving a Hybrid. Collect $50\n";
            p1bal+=500;
            break;
        }
        case 6:{
            cout<<"Chance: Advance to go collect $200\n";
            break;
        }
        case 7:{
            cout<<"Chance: Summoned for jury duty. Go back three spaces.\n";
//            House.board[p1-3];
            break;
        }
        case 8:{
            cout<<"Chance: Take a helicopter ride to BoardWalk. If you pass go collect $200\n";
            break;
        }
        case 9:{
            cout<<"Chance: Accept the position of CEO of a high powered investment banking firm. Collect a signing bonus of $500\n";
            p1bal+=500;
            break;
        }
        case 10:{
            cout<<"Chance: Jump on a plane to Illinois Avenue. If you pass go collect $200\n";
            break;
        }
        case 11:{
            cout<<"Chance: Splash out on a trip to St. Charles place. If you pass go collect $200\n";
            break;
        }
        case 12:{
            cout<<"Chance: You are acquitted. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
            break;
        }
        default: cout<<"Error: In the switch statment\n";
    }
}
//Rolls the dice
unsigned char roll(unsigned char sides,unsigned char nDie){ 
    //Declare the sum the die rolls 
    unsigned char sum=0; 
    //Loop for each die 
    for(int thrw=1;thrw<=nDie;thrw++){ 
        sum+=(rand()%sides+1); 
    } 
    return sum; 
}

