/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 9, 2015, 11:40 PM
 * Purpose: Monopoly
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries
#include "House.h"
#include "Player.h"
#include "Computer.h"

//Global constants
const int SIZE=40;//size of the board

//Function Prototypes
unsigned char roll(unsigned char,unsigned char);//roll dice
void rules();//couts the rules of the game
void over();//couts game over pic
void display(int[],int[]);//displays the board
int win(int,int,bool&);//determine the winner
int jail(int&,int[],int&);
int cjail(int&,int[],int&);
int pay(int &,int);//player income tax
int cpay(int &,int);//computer income tax
int pchance(int &,int &,int &,int[] ,int &,bool&);//Player chance
int cchance(int &,int &,int &,int [],int &,bool&);//Computer chance
int pchest(int &,int &,int &,int [],int &,bool&);//Player community chest
int cchest(int &,int &,int &,int [],int &,bool&);//computer community chest
int move(int&,int&,int&,int[]);//player moves thru the board
int compmove(int &,int &,int &,int[]);//computer moves thru the board

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed and size the array
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Player p;
    Computer c;
    p.p1=0;//player dice
    p.p1bal=1500;//player bank account
    p.p1loc=0;//player location on the board
    c.c1=0; //computer dice 
    c.c1bal=1500;//computer bank account
    c.c1loc=0;//computer location on the board
    
    bool prison=true;//misses a turn
    bool cprison=true;//computer misses a turn
    bool game=true;//to continue the game until there is a winner
    char check;//is the player would like to buy
    int play=0;//play the game or see rules
    int buyans;//If the user would like to buy the property
    int turn=1; //Turns if the player or computer land on jail
    
    House *board=new House[SIZE];//dynamic array to hold the name, buy and rent of the property
    string property[SIZE]={"Go","Mediterranean Avenue","Community Chest","Baltic Avenue"," Income Tax","Reading Railroad",
                         "Oriental Avenue","Chance","Vermont Avenue","Connecticut Avenue","In Jail or Just visiting","St. Charles Place",
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
    
    bool avail[SIZE];//if the house is owned or available
    //sets the whole board to true available to buy
    for(int i=0;i<SIZE;i++){
        avail[i]=true;
    }
    //Sets the chance,go,income tax, etc.. to not able to buy
    avail[0]=false;
    avail[2]=false;
    avail[4]=false;
    avail[7]=false; 
    avail[10]=false;
    avail[17]=false;
    avail[20]=false;
    avail[22]=false;
    avail[30]=false;
    avail[33]=false;
    avail[36]=false;
    avail[38]=false;
    
    int pmove[SIZE];//is the player's board
    int cmove[SIZE];//the computers board
    vector <int> p1prop;
    vector <int> c1prop;
    //sets the whole array to 0
    for(int i=0;i<SIZE;i++){
        pmove[i]=0;
        cmove[i]=0;
    }
    
    do{
        do{
            cout<<"Welcome to the Monopoly game!!!\n";
            cout<<"Each player starts off with $1500\n";
            cout<<"1. To play the game\n2. To see the rules\n";
            cin>>play;
            if(play<1 || play>2){
                cout<<"Invalid Input\n";
            }
        }while(play<1 || play>2);
        
        switch(play){
            case 1:{
                do{
                    if(game!=false){
                        if(cprison==false){
                            turn=2;  
                            cprison=true;      
                        }else{
                            turn=1;
                        }
                        for(int i=1;i<=turn;i++){
                            p.p1=roll(6,2);
                            cout<<"Player 1 you rolled your dice and got "<<p.p1<<endl;
                            cout<<"Move forward "<<p.p1<<" spaces."<<endl; 
                            pmove[p.p1loc]=0;
                            p.p1loc+=p.p1;
                            move(p.p1loc,p.p1,p.p1bal,pmove);
                            cout<<"You landed on "<<property[p.p1loc]<<endl;
                            if(p.p1loc==4 || p.p1loc==38){
                                pay(p.p1bal,p.p1loc);
                            }
                            if(p.p1loc==7 || p.p1loc==22 || p.p1loc==36){
                                pchance(p.p1bal,p.p1loc,p.p1,pmove,c.c1bal,prison);
                            }
                            if(p.p1loc==2 || p.p1loc==17 || p.p1loc==33){
                                pchest(p.p1bal,p.p1loc,p.p1,pmove,c.c1bal,prison);
                            }
                            if(p.p1loc==30){
                                prison=false;
                                jail(p.p1loc,pmove,p.p1);
                            }
                            cout<<"Your balance is $"<<p.p1bal<<endl;
                            //Output the board
                            display(pmove,cmove);
                            //Used to check if player lands on a computer owned location
                            for(int i=0;i<c1prop.size();i++){
                                if(p.p1loc==c1prop[i]){
                                    p.p1bal-=rent[p.p1loc];
                                    c.c1bal+=rent[p.p1loc];
                                    cout<<"Computer owns "<<property[p.p1loc]<<" you owe $"<<rent[p.p1loc]<<" for rent\n";
                                }
                            }
                            //To determine the winner
                            win(p.p1bal,c.c1bal,game);
                            if(game==false){
                                break; 
                            }
                                do{
                                    do{
                                        cout<<"1. Buy Property\n2. See your property\n3. End turn\n";
                                        cin>>buyans;
                                        if(buyans<1 || buyans>3){
                                            cout<<"Invalid Input\n";
                                        }
                                    }while(buyans<1 || buyans>3);
                                    switch(buyans){
                                        case 1:{
                                            if(avail[p.p1loc]==false){
                                                cout<<"You cannot buy this property\n";
                                            }else if(avail[p.p1loc]==true){
                                                cout<<"You can buy this property\n";
                                                board[p.p1loc].print();
                                                do{
                                                    cout<<"Press 'Y' if you want to buy this property,or 'N' if you do not\n";
                                                    cin>>check;
                                                    if(check!='Y' && check!='y' && check!='N' && check!='n'){
                                                        cout<<"Invalid Input\n";                         
                                                    }
                                                }while(check!='Y' && check!='y' && check!='N' && check!='n');

                                                if(check=='Y' || check=='y'){
                                                    if(p.p1bal<buy[p.p1loc]){
                                                        cout<<"You can not afford this property\n";
                                                    }else if(p.p1bal>=buy[p.p1loc]){
                                                        cout<<"You purchased "<<property[p.p1loc]<<endl;
                                                        p.p1bal-=buy[p.p1loc];//Subtracts the cost to buy from the players balance
                                                        avail[p.p1loc]=false;//Is no longer available
                                                        p1prop.push_back(p.p1loc);//stores the location of where the player owns
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2:{
                                            if(p1prop.size()==0){
                                                cout<<"You do not own any property\n";
                                            }else{
                                                //Cout the property the player owns
                                                for(int i=0;i<p1prop.size();i++){
                                                    cout<<"You own "<<property[p1prop[i]]<<endl;
                                                }
                                            }
                                            break;
                                        }
                                        case 3:{
                                           cout<<"Turn ended!\n\n\n";
                                           break; 
                                        }
                                        default:cout<<"Error: In the switch statment\n";
                                    }
                                }while(buyans!=3);
                        }
                    }
                    if(game!=false){
                        if(prison==false){
                                turn=2;
                                prison=true;    
                            }else{
                                turn=1;
                            }
                            for(int i=1;i<=turn;i++){
                            c.c1=roll(6,2);
                            cout<<"Now it is the computers turn, balance $"<<c.c1bal<<"\n";
                            cout<<"The computer moved forward "<<c.c1<<" spaces."<<endl;
                            cmove[c.c1loc]=0;
                            c.c1loc+=c.c1;
                            compmove(c.c1loc,c.c1,c.c1bal,cmove);

                            cout<<"The computer landed on "<<property[c.c1loc]<<endl;
                            win(p.p1bal,c.c1bal,game);//determines the winner
                            if(game==false)break;//doesn't let the computer turn happen if player wins
                            //calls the income tax function
                            if(c.c1loc==4 || c.c1loc==38){
                                 cpay(c.c1bal,c.c1loc);
                            }
                            //calls the chance function
                            if(c.c1loc==7 || c.c1loc==22 || c.c1loc==36){
                                cchance(c.c1bal,c.c1loc,c.c1,cmove,p.p1bal,cprison);
                            }
                            //calls the chest function
                            if(c.c1loc==2 || c.c1loc==17 || c.c1loc==33){
                                cchest(c.c1bal,c.c1loc,c.c1,cmove,p.p1bal,cprison);
                            }
                            //Calls the jail function
                            if(c.c1loc==30){
                                cprison=false;
                               cjail(c.c1loc,cmove,c.c1); 
                            }

                            //Used to check if player lands on a computer owned location
                            for(int i=0;i<p1prop.size();i++){
                                if(c.c1loc==p1prop[i]){
                                    c.c1bal-=rent[c.c1loc];
                                    p.p1bal+=rent[c.c1loc];
                                    cout<<"You own "<<property[c.c1loc]<<" the computer owes you $"<<rent[c.c1loc]<<" for rent\n";
                                }
                            }
                            int Cbuy=rand()%3+1;
                            if(avail[c.c1loc]==true){
                               if(c.c1bal>buy[c.c1loc]){
                                   if(Cbuy==2){
                                      cout<<"The computer purchased "<<property[c.c1loc]<<endl;
                                      c.c1bal-=buy[c.c1loc];//Subrtracts the cost to buy from the players balance
                                      avail[c.c1loc]=false;//Is no longer available
                                      c1prop.push_back(c.c1loc);//stores the location of where the player owns 
                                    }
                                }
                            }
                            display(pmove,cmove);
                            cout<<"Computer's turn ended, balance $"<<c.c1bal<<"\n";
                            cout<<"\n\n";
                            }

                    }
                }while(game);
                break;
            }
            case 2:{
                rules();
                break;
            }
        }
    }while(play!=1);
    over();
    //Writes to a file::binary the p1 balance and property's
    ofstream fout("scores.txt",ios::binary);
    cout<<"Writing down your score to a file..\n";
    fout<<"Player 1 balance: $"<<p.p1bal<<endl;
    //Cout the property the player owns
    int counter=0;
    for(int i=0;i<p1prop.size();i++){
        fout<<"You own "<<property[p1prop[i]]<<", ";
        counter++;
        if(counter>3){
            fout<<endl;
            counter=0;
        }
    }
    fout.close();
    cout<<"Thank you for playing!!"<<endl;
    return 0;
}
/*******************************************************************************
 *                              DISPLAY
 *******************************************************************************
 * purpose: display the board
 * input:
 *      pmove[]->the players place on teh board
 *      cmove[]->the computers place on the board
 */
void display(int pmove[],int cmove[]){
    for(int i=0;i<=SIZE;i++){
        cout<<"--";
    }
    cout<<endl;
    for(int i=1;i<=SIZE;i++){
        cout<<"| ";
        if(pmove[i]==1){
            cout<<"P";
        }
        if(cmove[i]==1){
            cout<<"C";
        }
    }
    cout<<endl;
    for(int i=0;i<=SIZE;i++){
        cout<<"--";
    }
    cout<<endl;
}
/*******************************************************************************
 *                              Win
 *******************************************************************************
 * purpose: To determine the winner
 * input:
 *      p1bal-> player 1's balance
 *      c1bal-> computers balance
 *      game-> to determine if the game is over
 * output:
 *      game-> sets game = to false
 *      
 */
int win(int p1bal,int c1bal,bool&game){
    //Wins when computer has no money
    if(p1bal<=0){
        cout<<"You lose!!!\n";
        game=false;
    }else if(c1bal<=0){
        cout<<"You win!!\n";
        game=false;
    }
}
/*******************************************************************************
                                Jail
 *******************************************************************************
 * purpose: relocates player to jail
 * input:
 *      p1loc-> takes in the players location on the board
 *      pmove[]-> the array to move player from his position to jail
 *      p1->the sum of the dice
 * output:
 *      p1loc-> to 10 for jail
 *      p1=10 so afterwards the movement will continue from jail
 *      pmove[]->sets the new location for player
 *      
 */
int jail(int &p1loc,int pmove[],int &p1){
    if(p1loc==30){
        pmove[p1loc]=0;
        p1loc=10;
        p1=10;
        pmove[p1loc]=1;
        cout<<"You are in Jail\n";
    }
}
/*******************************************************************************
                                cJail
 *******************************************************************************
 * purpose: relocates computer to jail
 * input:
 *      c1loc-> takes in the computers location on the board
 *      cmove[]-> the array to move computer from his position to jail
 *      c1->the sum of the dice
 * output:
 *      c1loc-> to 10 for jail
 *      c1=10 so afterwards the movement will continue from jail
 *      cmove[]->sets the new location for computer
 *      
 */
int cjail(int &c1loc,int cmove[],int &c1){
    if(c1loc==30){
        cmove[c1loc]=0;
        c1loc=10;
        c1=10;
        cmove[c1loc]=1;
        cout<<"The computer is in Jail\n";
    }
}
/*******************************************************************************
                                    compmove
 *******************************************************************************
 * purpose: To move computer around the board
 * input:
 *      c1loc-> takes in the players location on the board
 *      c1->    to move computer around the board c1 times
 *      c1bal-> if passed go add $200
 *      cmove[]->sets new location for computer
 * output:
 *      c1bal->if passed go collect $200
 *      c1loc->if passed go starts at the beginning
 */
int compmove(int &c1loc,int &c1,int &c1bal,int cmove[]){
    for(int i=0;i<=c1;i++){
        if(c1loc>39){
            c1loc-=39;
            cout<<"The computer passed 'Go' and collected $200\n";
            c1bal+=200;
        }else{
            cmove[c1loc]=1;
        }
    }
}
/*******************************************************************************
                                    move
 *******************************************************************************
 * purpose: To move Player around the board
 * input:
 *      p1loc-> takes in the players location on the board
 *      p1->    to move computer around the board c1 times
 *      p1bal-> if passed go add $200
 *      pmove[]->sets new location for computer
 * output:
 *      p1bal->if passed go collect $200
 *      p1loc->if passed go starts at the beginning
 */
int move(int &p1loc,int &p1,int &p1bal,int pmove[]){
    for(int i=0;i<=p1;i++){
        if(p1loc>39){
            p1loc-=39;
            cout<<"You passed 'Go' please collect $200\n";
            p1bal+=200;
        }else{
            pmove[p1loc]=1;
        }
    }
}
/*******************************************************************************
                                    pchest
 *******************************************************************************
 * purpose: calls community chest to select a random card
 * input:
 *      p1bal-> the balance of the player
 *      p1loc-> location at where player 1 is
 *      p1->    the dice of where player 1 is
 *      pmove[]-> location  
 *      c1bal->
 *      prison->
 * output:
 *      p1bal->if passed go collect $200
 *      p1loc->if passed go starts at the beginning
 */
int pchest(int &p1bal,int &p1loc,int &p1,int pmove[],int &c1bal,bool &prison){
    int random=rand()%15+1;
    if(p1loc==2 || p1loc==17 || p1loc==33){
        switch(random){
            case 1:{
                cout<<"Community Chest: Make it Big in HollyWood. Collect $2000 in a movie deal\n";
                p1bal+=2000;
                break;
            }
            case 2:{
                cout<<"Community Chest: You promote your new Book on tv morning news. Receive $100 in bonus sales\n";
                p1bal+=100;
                break;
            }
            case 3:{
                cout<<"Community Chest: Advance to 'Go'(Collect $200)\n";
                pmove[p1loc]=0;
                p1=0;
                p1loc=0;
                move(p1loc,p1,p1bal,pmove);
                cout<<"You passed 'Go' collect $200\n";
                p1bal+=200;
                break;
            }
            case 4:{
                cout<<"Community Chest: Your trust fund becomes available. Collect $500\n";
                p1bal+=500;
                break;
            }
            case 5:{
                cout<<"Community Chest: Take dance lessons with a celebrity coach. Pay $500\n";
                p1bal-=500;
                break;
            }
            case 6:{
                cout<<"Community Chest: You run for mayor. Collect $100 from each player to fund your campaign\n";
                c1bal-=100;
                p1bal+=100;
                break;
            }
            case 7:{
                cout<<"Community Chest: You coordinate opening day activities at progressive field. Collect $250 for your services\n";
                p1bal+=250;
                break;
            }
            case 8:{
                cout<<"Community Chest: Your computer network gets hit with a virus. Pay $1000\n";
                p1bal-=1000;
                break;
            }
            case 9:{
                cout<<"Community Chest: Sell your lifetime, 50-yard line, season tickets on e-bay. Collect $200\n";
                p1bal+=200;
                break;
            }
            case 10:{
                cout<<"Community Chest: Win big at the casino. Collect $1000\n";
                p1bal+=1000;
                break;
            }
            case 11:{
                cout<<"Community Chest: You owe back taxes. Pay $500 in fines\n";
                p1bal-=500;
                break;
            }
            case 12:{
                cout<<"Community Chest: You win the lottery. Collect $1000\n";
                p1bal+=1000;
                break;
            }
            case 13:{
                cout<<"Community Chest: You are a runner up on a reality Tv show. Collect $100\n";
                p1bal+=100;
                break;
            }
            case 14:{
                cout<<"Community Chest: Arrested for insider trading. Go to jail. DO NOT PASS 'GO', DO NOT COLLECT $200\n";
                prison=false;
                jail(p1loc,pmove,p1);
                break;
            }
            case 15:{
                cout<<"Community chest: Received a presidential pardon. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            } 
    }
}
/*******************************************************************************
                                    cchest
 *******************************************************************************
 * purpose: calls community chest to select a random card
 * input:
 *      c1bal-> the balance of the player
 *      c1loc-> location at where computer is
 *      c1->    the dice of where computer is
 *      cmove[]-> location  
 *      p1bal-> players balance
 *      cprison-> if computer is in jail
 * output:
 *      c1bal->if passed go collect $200
 *      c1loc->if passed go starts at the beginning
 */
int cchest(int &c1bal,int &c1loc,int &c1,int cmove[],int &p1bal,bool &cprison){
    int random=rand()%15+1;
    if(c1loc==2 || c1loc==17 || c1loc==33){
        switch(random){
            case 1:{
                cout<<"Community Chest: Make it Big in HollyWood. Collect $2000 in a movie deal\n";
                c1bal+=2000;
                break;
            }
            case 2:{
                cout<<"Community Chest: You promote your new Book on tv morning news. Receive $100 in bonus sales\n";
                c1bal+=100;
                break;
            }
            case 3:{
                cout<<"Community Chest: Advance to 'Go'(Collect $200)\n";
                cmove[c1loc]=0;
                c1=0;
                c1loc=0;
                move(c1loc,c1,c1bal,cmove);
                cout<<"You passed 'Go' collect $200\n";
                c1bal+=200;
                break;
            }
            case 4:{
                cout<<"Community Chest: Your trust fund becomes available. Collect $500\n";
                c1bal+=500;
                break;
            }
            case 5:{
                cout<<"Community Chest: Take dance lessons with a celebrity coach. Pay $500\n";
                c1bal-=500;
                break;
            }
            case 6:{
                cout<<"Community Chest: You run for mayor. Collect $100 from each player to fund your campaign\n";
                p1bal-=100;
                c1bal+=100;
                break;
            }
            case 7:{
                cout<<"Community Chest: You coordinate opening day activities at progressive field. Collect $250 for your services\n";
                c1bal+=250;
                break;
            }
            case 8:{
                cout<<"Community Chest: Your computer network gets hit with a virus. Pay $1000\n";
                c1bal-=1000;
                break;
            }
            case 9:{
                cout<<"Community Chest: Sell your lifetime, 50-yard line, season tickets on e-bay. Collect $200\n";
                c1bal+=200;
                break;
            }
            case 10:{
                cout<<"Community Chest: Win big at the casino. Collect $1000\n";
                c1bal+=1000;
                break;
            }
            case 11:{
                cout<<"Community Chest: You owe back taxes. Pay $500 in fines\n";
                c1bal-=500;
                break;
            }
            case 12:{
                cout<<"Community Chest: You win the lottery. Collect $1000\n";
                c1bal+=1000;
                break;
            }
            case 13:{
                cout<<"Community Chest: You are a runner up on a reality Tv show. Collect $100\n";
                c1bal+=100;
                break;
            }
            case 14:{
                cout<<"Community Chest: Arrested for insider trading. Go to jail. DO NOT PASS 'GO', DO NOT COLLECT $200\n";
                cprison=false;
                cjail(c1loc,cmove,c1);
                break;
            }
            case 15:{
                cout<<"Community chest: Received a presidential pardon. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            } 
    }
}
/*******************************************************************************
                                    pchance
 *******************************************************************************
 * purpose: calls chance to select a random card
 * input:
 *      p1bal-> the balance of the player
 *      p1loc-> location at where player 1 is
 *      p1->    the dice of where player 1 is
 *      pmove[]-> location  of players moves on board
 *      c1bal-> computers balance
 *      prison-> is player is in prison
 * output:
 *      p1bal->if passed go collect $200
 *      p1loc->if passed go starts at the beginning
 */
int pchance(int &p1bal,int &p1loc,int &p1,int pmove[],int &c1bal,bool &prison){
    int random=rand()%12+1;
    if(p1loc==7 || p1loc==22 || p1loc==36){
        switch(random){
            case 1:{
                cout<<"Chance: Convicted of Identity theft, Go to Jail. Do not pass go. Do not collect $200\n";
                prison=false;
                jail(p1loc,pmove,p1);
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
                pmove[p1loc]=0;
                p1=5;
                p1loc=5;
                move(p1loc,p1,p1bal,pmove);
                break;
            }
            case 4:{
                cout<<"Chance: Make a donation for disaster relief. Pay $150\n";
                p1bal-=150;
                break;
            }
            case 5:{
                cout<<"Chance: Get a tax break for driving a Hybrid. Collect $50\n";
                p1bal+=50;
                break;
            }
            case 6:{
                cout<<"Chance: Advance to go collect $200\n";
                pmove[p1loc]=0;
                p1=0;
                p1loc=0;
                move(p1loc,p1,p1bal,pmove);
                cout<<"You passed 'Go' collect $200\n";
                p1bal+=200;
                break;
            }
            case 7:{
                cout<<"Chance: Summoned for jury duty. Go back three spaces.\n";
                pmove[p1loc]=0;
                p1loc-=3;
                pmove[p1loc]=1;
                break;
            }
            case 8:{
                cout<<"Chance: Take a helicopter ride to BoardWalk. If you pass go collect $200\n";
                pmove[p1loc]=0;
                p1=39;
                p1loc=39;
                move(p1loc,p1,p1bal,pmove);
                break;
            }
            case 9:{
                cout<<"Chance: Accept the position of CEO of a high powered investment banking firm. Collect a signing bonus of $500\n";
                p1bal+=500;
                break;
            }
            case 10:{
                cout<<"Chance: Jump on a plane to Illinois Avenue. If you pass go collect $200\n";
                pmove[p1loc]=0;
                p1=24;
                p1loc=24;
                move(p1loc,p1,p1bal,pmove);
                break;
            }
            case 11:{
                cout<<"Chance: Splash out on a trip to St. Charles place. If you pass go collect $200\n";
                pmove[p1loc]=0;
                p1=11;
                p1loc=11;
                move(p1loc,p1,p1bal,pmove);
                break;
            }
            case 12:{
                cout<<"Chance: You are acquitted. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            }
    }
}
/*******************************************************************************
                                    cchance
 *******************************************************************************
 * purpose: calls chance to select a random card
 * input:
 *      c1bal-> the balance of the computer
 *      c1loc-> location at where computer is
 *      c1->    the dice of where computer is
 *      cmove[]-> location  
 *      p1bal-> players balance
 *      cprison-> if computer is in jail
 * output:
 *      c1bal->if passed go collect $200
 *      c1loc->if passed go starts at the beginning
 */
int cchance(int &c1bal,int &c1loc,int &c1,int cmove[],int &p1bal,bool &cprison){
    if(c1loc==7 || c1loc==22 || c1loc==36){
        int random=rand()%12+1;
        switch(random){
            case 1:{
                cout<<"Chance: Convicted of Identity theft, Go to Jail. Do not pass go. Do not collect $200\n";
                cprison=false;
                cjail(c1loc,cmove,c1); 
                break;
            }
            case 2:{
                cout<<"Chance: A group of guest wins a class action suit against your hotel pay each player $500\n";
                c1bal-=500;
                p1bal+=500;
                break;
            }
            case 3:{
                cout<<"Chance: Ride First class to reading railroad. If you pass go collect $200\n";
                cmove[c1loc]=0;
                c1=5;
                c1loc=5;
                compmove(c1loc,c1,c1bal,cmove);
                break;
            }
            case 4:{
                cout<<"Chance: Make a donation for disaster relief. Pay $150\n";
                c1bal-=150;
                break;
            }
            case 5:{
                cout<<"Chance: Get a tax break for driving a Hybrid. Collect $50\n";
                c1bal+=50;
                break;
            }
            case 6:{
                cout<<"Chance: Advance to go collect $200\n";
                cmove[c1loc]=0;
                c1=0;
                c1loc=0;
                compmove(c1loc,c1,c1bal,cmove);
                cout<<"You passed 'Go' collect $200\n";
                c1bal+=200;
                break;
            }
            case 7:{
                cout<<"Chance: Summoned for jury duty. Go back three spaces.\n";
                cmove[c1loc]=0;
                c1loc-=3;
                cmove[c1loc]=1;
                break;
            }
            case 8:{
                cout<<"Chance: Take a helicopter ride to BoardWalk. If you pass go collect $200\n";
                cmove[c1loc]=0;
                c1=39;
                c1loc=39;
                compmove(c1loc,c1,c1bal,cmove);
                break;
            }
            case 9:{
                cout<<"Chance: Accept the position of CEO of a high powered investment banking firm. Collect a signing bonus of $500\n";
                c1bal+=500;
                break;
            }
            case 10:{
                cout<<"Chance: Jump on a plane to Illinois Avenue. If you pass go collect $200\n";
                cmove[c1loc]=0;
                c1=24;
                c1loc=24;
                compmove(c1loc,c1,c1bal,cmove);
                break;
            }
            case 11:{
                cout<<"Chance: Splash out on a trip to St. Charles place. If you pass go collect $200\n";
                cmove[c1loc]=0;
                c1=11;
                c1loc=11;
                compmove(c1loc,c1,c1bal,cmove);
                break;
            }
            case 12:{
                cout<<"Chance: You are acquitted. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            } 
    }
}
/*******************************************************************************
 *                              cpay
 *******************************************************************************
 * purpose: To pay taxes
 * input:
 *      c1bal-> computer balance
 *      c1loc-> computers location
 * output:
 *      
 */
int cpay(int&c1bal,int c1loc){
    if(c1loc==4){
        cout<<"The computer paid $200 to the bank\n";
        c1bal-=200;
    }else if(c1loc==38){
        cout<<"The computer paid $100 to the bank\n";
        c1bal-=100;
    }
}
/*******************************************************************************
 *                              pay
 *******************************************************************************
 * purpose: To pay taxes
 * input:
 *      p1bal-> computer balance
 *      p1loc-> computers location
 * output:
 *      
 */
int pay(int &p1bal,int p1loc){
    if(p1loc==4){
        cout<<"You paid $200 to the bank\n";
        p1bal-=200;
    }else if(p1loc==38){
        cout<<"You paid $100 to the bank\n";
        p1bal-=100;
    }
}
/*******************************************************************************
 *                              over
 *******************************************************************************
 * purpose: to diplay the end text
 * output:
 *      the game over text at the end of the game
 */
void over(){
    ifstream fin;
    string temp;
    //Cout the rules    
    fin.open("game.txt");
    if(fin.is_open()){
        while(getline(fin,temp)){
            cout<<temp;
        }
    }
    cout<<endl;
    fin.close();
}
/*******************************************************************************
 *                              rules
 *******************************************************************************
 * purpose: to diplay the rules of the game
 * display: the rules of the game
 */
void rules(){
    ifstream fin;
    string temp;
    cout<<endl;
    //Cout the rules    
    fin.open("rules.txt");
    if(fin.is_open()){
        while(getline(fin,temp)){
            cout<<temp<<endl;
        }
    }
    fin.close();
}
/*******************************************************************************
 *                              roll
 *******************************************************************************
 * purpose: To roll the dice
 * input:
 *      sides-> number of sides on the dice
 *      nDie-> number of dice in game
 * output:
 *		sum-> the total sum of the dice      
 */
unsigned char roll(unsigned char sides,unsigned char nDie){ 
    //Declare the sum the die rolls 
    unsigned char sum=0; 
    //Loop for each die
    for(int thrw=1;thrw<=nDie;thrw++){ 
        sum+=(rand()%sides+1); 
    } 
    return sum; 
}
