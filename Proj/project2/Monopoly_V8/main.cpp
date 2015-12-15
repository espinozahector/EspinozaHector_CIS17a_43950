/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on October 9, 2015, 11:40 PM
 * Purpose: Monopoly
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries
#include "House.h"
#include "Human.h" // has the player class
#include "Computer.h" //Has the player class as well
#include "Gaming.h"

//Global constants
const int SIZE=40;//size of the board

//Function Prototypes
unsigned char roll(unsigned char,unsigned char);//roll dice
void rules();//outputs the rules of the game
void over();//outputs game over picture
void display(int[],int[],string[],Human &,Computer &);//displays the board

int compmove(Computer &,int[]);//computer moves thru the board
int pay(Human &,Computer &,Gaming &);
int move(Human &,int[]);
int win(Human &,Computer &,Gaming &);
int jail(Human &,Computer &,Gaming &,int[],int[]);
int chance(Human &,Computer &,Gaming &,int[],int[]);
int chest(Human &,Computer &,Gaming &,int[], int[]);

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed and size the array
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Human h;
    Computer c;
    Gaming g;
    string sym;
    char check;//is the player would like to buy
    int play=0;//play the game or see rules
    int buyans;//If the user would like to buy the property
    int choice;//To change the symbol
   
    
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
        //Sets the chance,go,income tax, et. to not able to buy
        if (i==0 || i==2 || i==4 || i==7 ||i==10 || i==17 || i==20 || i==22 || i==30 || i==33 || i==36 || i==38){
            avail[i]=false;
        }
    }
    
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
            cin.ignore();
            if(play<1 || play>2){
                cout<<"ERROR: Invalid Input\n";
            }
        }while(play<1 || play>2);
        
        switch(play){
            case 1:{
                while(choice!=3){
                cout<<"Change your symbol?\n";
                cout<<"1. Change your symbol\n2. Change the comptuer's symbol\n3. Play the game\n";
                cin>>choice;
                cin.ignore();
                if(choice==1){
                    do{
                    cout<<"Input your character symbol ex.(!,*,#,$)\n";
                    cout<<"Symbol: ";
                    getline(cin,sym);
                    sym.size();
                    if(sym.size()>3){
                        cout<<"ERROR: Your Input must be 1 char or it can be up to 3 characters\n";
                    }
                }while(sym.size()>3);
                h.setsym(sym);
                }else if(choice==2){
                    do{
                    cout<<"Input the computer's symbol ex.(!,*,#,$)\n";
                    cout<<"Symbol: ";
                    getline(cin,sym);
                    sym.size();
                    if(sym.size()>3){
                        cout<<"ERROR: Your Input must be 1 char or it can be up to 3 characters\n";
                    }
                }while(sym.size()>3);
                c.setsym(sym);
                }else if(choice==3){
                    cout<<"Have Fun!\n";
                }
                }

                do{
                    win(h,c,g);
                    if(g.getgame()==false){
                        break; 
                    }
                    if(g.getgame()!=false){
                        if(g.getcprison()==false){
                            g.setturn(2);  
                            g.setcprison(true);
                        }else{
                            g.setturn(1);
                        }
                        for(int i=1;i<=g.getturn();i++){
                            g.setwho(true);
                            h.setroll(roll(6,2));
                            cout<<"It is your turn, balance $"<<h.getMoney()<<"\n";
                            cout<<"Player 1 you rolled your dice and got "<<h.getroll()<<endl;
                            cout<<"Move forward "<<h.getroll()<<" spaces."<<endl; 
                            pmove[h.getloc()]=0;
                            h.setloc(h.getloc()+h.getroll());

                            move(h,pmove);
                            
                            cout<<"You landed on "<<property[h.getloc()]<<endl;
                            if(h.getloc()==4 || h.getloc()==38){
                                pay(h,c,g);
                            }
                            if(h.getloc()==7 || h.getloc()==22 || h.getloc()==36){
                                chance(h,c,g,pmove,cmove);
                            }
                            if(h.getloc()==2 || h.getloc()==17 || h.getloc()==33){
                                chest (h,c,g,pmove,cmove);
                            }
                            if(h.getloc()==30){
                                g.setprison(false);
                                jail(h,c,g,pmove,cmove);
                            }
                            cout<<"Your balance is $"<<h.getMoney()<<endl;
                            //Output the board
                            display(pmove,cmove,property,h,c);
                            //Used to check if player lands on a computer owned location
                            for(int i=0;i<c1prop.size();i++){
                                if(h.getloc()==c1prop[i]){
                                    h.setmoney(h.getMoney()-rent[h.getloc()]);

                                    c.setmoney(c.getMoney()+rent[h.getloc()]);
                                    cout<<"Computer owns "<<property[h.getloc()]<<" you owe $"<<rent[h.getloc()]<<" for rent\n";
                                }
                            }
                            //To determine the winner
                            win(h,c,g);
                            if(g.getgame()==false){
                                break; 
                            }
                                do{
                                    do{
                                        cout<<"1. Buy Property\n2. See your property\n3. End turn\n";
                                        cin>>buyans;
                                        cin.ignore();
                                        if(buyans<1 || buyans>3){
                                            cout<<"Invalid Input\n";
                                        }
                                    }while(buyans<1 || buyans>3);
                                    switch(buyans){
                                        case 1:{
                                            if(avail[h.getloc()]==false){
                                                cout<<"You cannot buy this property\n";
                                            }else if(avail[h.getloc()]==true){
                                                cout<<"You can buy this property\n";
                                                board[h.getloc()].print();
                                                do{
                                                    cout<<"Press 'Y' if you want to buy this property,or 'N' if you do not\n";
                                                    cin>>check;
                                                    cin.ignore();
                                                    if(check!='Y' && check!='y' && check!='N' && check!='n'){
                                                        cout<<"Invalid Input\n";                         
                                                    }
                                                }while(check!='Y' && check!='y' && check!='N' && check!='n');

                                                if(check=='Y' || check=='y'){
                                                    if(h.getMoney()<buy[h.getloc()]){
                                                        cout<<"You can not afford this property\n";
                                                    }else if(h.getMoney()>=buy[h.getloc()]){
                                                        cout<<"You purchased "<<property[h.getloc()]<<endl;
                                                        h.setmoney(h.getMoney()-buy[h.getloc()]);//Subtracts the cost to buy from the players balance
                                                        avail[h.getloc()]=false;//Is no longer available
                                                        p1prop.push_back(h.getloc());//stores the location of where the player owns
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
                                                cout<<"\n************************************************\n\n";
                                                for(int i=0;i<p1prop.size();i++){
                                                    cout<<"You own "<<property[p1prop[i]]<<endl;
                                                }
                                                cout<<"\n************************************************\n\n";
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
                    win(h,c,g);
                    if(g.getgame()==false){
                        break; 
                    }
                    if(g.getgame()!=false){
                        if(g.getprison()==false){
                                g.setturn(2);
                                g.setprison(true);
                            }else{
                                g.setturn(1);
                            }
                            for(int i=1;i<=g.getturn();i++){
                                g.setwho(false);
                                c.setroll(roll(6,2));
                                cout<<"Now it is the computers turn, balance $"<<c.getMoney()<<"\n";
                                cout<<"The computer moved forward "<<c.getroll()<<" spaces."<<endl;
                                cmove[c.getloc()]=0;
                                c.setloc(c.getloc()+c.getroll());
                                compmove(c,cmove);

                                cout<<"The computer landed on "<<property[c.getloc()]<<endl;
                                win(h,c,g);//determines the winner
                                if(g.getgame()==false)break;//doesn't let the computer turn happen if player wins
                                //calls the income tax function
                                if(c.getloc()==4 || c.getloc()==38){
                                     pay(h,c,g);
                                }
                                //calls the chance function
                                if(c.getloc()==7 || c.getloc()==22 || c.getloc()==36){
                                    chance(h,c,g,pmove,cmove);
                                }
                                //calls the chest function
                                if(c.getloc()==2 || c.getloc()==17 || c.getloc()==33){
                                    chest (h,c,g,pmove,cmove);
                                }
                                //Calls the jail function
                                if(c.getloc()==30){
                                    g.setcprison(false);
                                   jail(h,c,g,pmove,cmove);
                                }

                                //Used to check if player lands on a computer owned location
                                for(int i=0;i<p1prop.size();i++){
                                    if(c.getloc()==p1prop[i]){
                                        c.setmoney(c.getMoney()-rent[c.getloc()]);

                                        h.setmoney(h.getMoney()+rent[c.getloc()]);                                        
                                        cout<<"You own "<<property[c.getloc()]<<" the computer owes you $"<<rent[c.getloc()]<<" for rent\n";
                                    }
                                }
                                int Cbuy=rand()%3+1;
                                if(avail[c.getloc()]==true){
                                   if(c.getMoney()>buy[c.getloc()]){
                                       if(Cbuy==2){
                                          cout<<"The computer purchased "<<property[c.getloc()]<<endl;
                                          c.setmoney(c.getMoney()-buy[c.getloc()]);//Subrtracts the cost to buy from the players balance
                                          avail[c.getloc()]=false;//Is no longer available
                                          c1prop.push_back(c.getloc());//stores the location of where the player owns 
                                        }
                                    }
                                }
                                display(pmove,cmove,property,h,c);
                                cout<<"Computer's turn ended, balance $"<<c.getMoney()<<"\n";
                                cout<<"\n\n";
                            }

                    }
                }while(g.getgame());
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
    fout<<"Player 1 balance: $"<<h.getMoney()<<endl;
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
int pay(Human &h,Computer &c,Gaming &g){
    if(g.getwho()==true){
        if(h.getloc()==4){
            cout<<"You paid $200 to the bank\n";
            h.setmoney(h.getMoney()-200);
        }else if(h.getloc()==38){
            cout<<"You paid $100 to the bank\n";
            h.setmoney(h.getMoney()-100);
        }
    }else if(g.getwho()==false){
        if(c.getloc()==4){
            cout<<"The computer paid $200 to the bank\n";
            c.setmoney(c.getMoney()-200);
        }else if(c.getloc()==38){
            cout<<"The computer paid $100 to the bank\n";
            c.setmoney(c.getMoney()-100);
        }
    }
}
int jail(Human &h,Computer &c,Gaming &g,int pmove[],int cmove[]){
    if(g.getwho()==true){
        pmove[h.getloc()]=0;
        h.setloc(10);
        h.setroll(0);//Dont know if i need it??????????????????????????????????????????????
        pmove[h.getloc()]=1;
        cout<<"You are in Jail\n";
    }else if(g.getwho()==false){
        cmove[c.getloc()]=0;
        c.setloc(10);
        c.setroll(0);
        cmove[c.getloc()]=1;
        cout<<"The computer is in Jail\n";
    }
}
/*******************************************************************************
 *                              DISPLAY
 *******************************************************************************
 * purpose: display the board
 * input:
 *      pmove[]->the players place on teh board
 *      cmove[]->the computers place on the board
 */
void display(int pmove[],int cmove[],string property[],Human &h,Computer &c){
//    for(int i=0;i<SIZE;i++){
//        //The top of the board
//        if(i<=10){
//            cout<<property[i];
//            if(pmove[i]==1){
//                cout<<" P ";
//            }
//            cout<<" | ";
//        }
//        if(i==10){
//            cout<<endl;
//        }
//    }
//    //The sides
//    for(int i=11;i<=20;i++){
//        for(int j=39;j<=31;j--){
//            cout<<property[i]<<setw(10)<<property[j]<<endl;
//        }
//    }
//    for(int i=0;i<SIZE;i++){
//        //The bottom
//        if(i>20 && i<=30){
//            cout<<property[i];
//            if(pmove[i]==1){
//                cout<<" P ";
//            }
//            cout<<" | "; 
//        }
//        if(i==30){
//            cout<<endl;
//        }
//    }
        
    
    //Old
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"--";
    }
    cout<<endl;
    for(int i=1;i<=SIZE;i++){
        cout<<"| ";
        if(pmove[i]==1){
            cout<<h.getsym();
        }
        if(cmove[i]==1){
            cout<<c.getsym();
        }
    }
    cout<<endl;
    for(int i=0;i<SIZE;i++){
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
int win(Human &h,Computer &c,Gaming &g){
    //Wins when computer has no money
    if(h.getMoney()<=0){
        cout<<"You lose!!!\n";
        g.setgame(false);
    }else if(c.getMoney()<=0){
        cout<<"You win!!\n";
        g.setgame(false);
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
int compmove(Computer &c,int cmove[]){
    //Used to make sure the board is set to 0
    for(int i=0;i<SIZE;i++){
        cmove[i]=0;
    }
    for(int i=0;i<=c.getroll();i++){
        if(c.getloc()>39){
            c.setloc(c.getloc()-39);
            cout<<"The computer passed 'Go' and collected $200\n";
            c.setmoney(c.getMoney()+200);
        }else{
            cmove[c.getloc()]=1;
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
int move(Human &h,int pmove[]){
    //Used to make sure the board is set to 0
    for(int i=0;i<SIZE;i++){
        pmove[i]=0;
    }
    for(int i=0;i<=h.getroll();i++){
        if(h.getloc()>39){
            h.setloc(h.getloc()-39);
            cout<<"You passed 'Go' please collect $200\n";
            h.setmoney(h.getMoney()+200);
        }else{
            pmove[h.getloc()]=1;
        }
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
    cout<<endl;
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
        sum-> the total sum of the dice      
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
int chance(Human &h,Computer &c,Gaming &g,int pmove[],int cmove[]){
    int random=rand()%12+1;
    if(g.getwho()==true){
        switch(random){
            case 1:{
                cout<<"Chance: Convicted of Identity theft, Go to Jail. Do not pass go. Do not collect $200\n";
                g.setprison(false);
                jail(h,c,g,pmove,cmove);
                break;
            }
            case 2:{
                cout<<"Chance: A group of guest wins a class action suit against your hotel pay each player $500\n";
                h.setmoney(h.getMoney()-500);
                c.setmoney(c.getMoney()+500);
                break;
            }
            case 3:{
                cout<<"Chance: Ride First class to reading railroad. If you pass go collect $200\n";
                pmove[h.getloc()]=0;
                h.setroll(5);//IDK IF I NEED IT?????????????????????????
                h.setloc(5);
                move(h,pmove);
                break;
            }
            case 4:{
                cout<<"Chance: Make a donation for disaster relief. Pay $150\n";
                h.setmoney(h.getMoney()-150);
                break;
            }
            case 5:{
                cout<<"Chance: Get a tax break for driving a Hybrid. Collect $50\n";
                h.setmoney(h.getMoney()+50);
                break;
            }
            case 6:{
                cout<<"Chance: Advance to go collect $200\n";
                pmove[h.getloc()]=0;
                h.setroll(0);//IDK IF I NEED IT?????????????????????????
                h.setloc(0);
                move(h,pmove);
                cout<<"You passed 'Go' collect $200\n";
                h.setmoney(h.getMoney()+200);
                break;
            }
            case 7:{
                cout<<"Chance: Summoned for jury duty. Go back three spaces.\n";
                pmove[h.getloc()]=0;
                h.setloc(h.getloc()-3);
                pmove[h.getloc()]=1;
                break;
            }
            case 8:{
                cout<<"Chance: Take a helicopter ride to BoardWalk. If you pass go collect $200\n";
                pmove[h.getloc()]=0;
                h.setroll(39);//IDK IF I NEED IT?????????????????????????
                h.setloc(39);
                move(h,pmove);
                break;
            }
            case 9:{
                cout<<"Chance: Accept the position of CEO of a high powered investment banking firm. Collect a signing bonus of $500\n";
                h.setmoney(h.getMoney()+500);
                break;
            }
            case 10:{
                cout<<"Chance: Jump on a plane to Illinois Avenue. If you pass go collect $200\n";
                pmove[h.getloc()]=0;
                h.setroll(24);//IDK IF I NEED IT?????????????????????????
                h.setloc(24);
                move(h,pmove);
                break;
            }
            case 11:{
                cout<<"Chance: Splash out on a trip to St. Charles place. If you pass go collect $200\n";
                pmove[h.getloc()]=0;
                h.setroll(11);//IDK IF I NEED IT?????????????????????????
                h.setloc(11);
                move(h,pmove);
                break;
            }
            case 12:{
                cout<<"Chance: You are acquitted. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            }
    }else if(g.getwho()==false){
        switch(random){
            case 1:{
                cout<<"Chance: Convicted of Identity theft, Go to Jail. Do not pass go. Do not collect $200\n";
                g.setcprison(false);
                jail(h,c,g,pmove,cmove);
                break;
            }
            case 2:{
                cout<<"Chance: A group of guest wins a class action suit against your hotel pay each player $500\n";
                c.setmoney(c.getMoney()-500);
                h.setmoney(h.getMoney()+500);
                break;
            }
            case 3:{
                cout<<"Chance: Ride First class to reading railroad. If you pass go collect $200\n";
                cmove[c.getloc()]=0;
                c.setroll(5);
                c.setloc(5);
                compmove(c,cmove);
                break;
            }
            case 4:{
                cout<<"Chance: Make a donation for disaster relief. Pay $150\n";
                c.setmoney(c.getMoney()-150);
                break;
            }
            case 5:{
                cout<<"Chance: Get a tax break for driving a Hybrid. Collect $50\n";
                c.setmoney(c.getMoney()+50);
                break;
            }
            case 6:{
                cout<<"Chance: Advance to go collect $200\n";
                cmove[c.getloc()]=0;
                c.setroll(0);
                c.setloc(0);
                compmove(c,cmove);
                cout<<"You passed 'Go' collect $200\n";
                c.setmoney(c.getMoney()+200);
                break;
            }
            case 7:{
                cout<<"Chance: Summoned for jury duty. Go back three spaces.\n";
                cmove[c.getloc()]=0;
                c.setloc(c.getloc()-3);
                cmove[c.getloc()]=1;
                break;
            }
            case 8:{
                cout<<"Chance: Take a helicopter ride to BoardWalk. If you pass go collect $200\n";
                cmove[c.getloc()]=0;
                c.setroll(39);
                c.setloc(39);
                compmove(c,cmove);
                break;
            }
            case 9:{
                cout<<"Chance: Accept the position of CEO of a high powered investment banking firm. Collect a signing bonus of $500\n";
                c.setmoney(c.getMoney()+500);
                break;
            }
            case 10:{
                cout<<"Chance: Jump on a plane to Illinois Avenue. If you pass go collect $200\n";
                cmove[c.getloc()]=0;
                c.setroll(24);
                c.setloc(24);
                compmove(c,cmove);
                break;
            }
            case 11:{
                cout<<"Chance: Splash out on a trip to St. Charles place. If you pass go collect $200\n";
                cmove[c.getloc()]=0;
                c.setroll(11);
                c.setloc(11);
                compmove(c,cmove);
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
int chest(Human &h,Computer &c,Gaming &g,int pmove[], int cmove[]){
    int random=rand()%15+1;
    if(g.getwho()==true){
        switch(random){
            case 1:{
                cout<<"Community Chest: Make it Big in HollyWood. Collect $2000 in a movie deal\n";
                h.setmoney(h.getMoney()+2000);
                break;
            }
            case 2:{
                cout<<"Community Chest: You promote your new Book on tv morning news. Receive $100 in bonus sales\n";
                h.setmoney(h.getMoney()+100);
                break;
            }
            case 3:{
                cout<<"Community Chest: Advance to 'Go'(Collect $200)\n";
                pmove[h.getloc()]=0;
                h.setroll(0);//IDK if i need it????????????????????????????????????????
                h.setloc(0);
                move(h,pmove);
                cout<<"You passed 'Go' collect $200\n";
                h.setmoney(h.getMoney()+200);
                break;
            }
            case 4:{
                cout<<"Community Chest: Your trust fund becomes available. Collect $500\n";
                h.setmoney(h.getMoney()+500);
                break;
            }
            case 5:{
                cout<<"Community Chest: Take dance lessons with a celebrity coach. Pay $500\n";
                h.setmoney(h.getMoney()-500);
                break;
            }
            case 6:{
                cout<<"Community Chest: You run for mayor. Collect $100 from each player to fund your campaign\n";
                c.setmoney(c.getMoney()-100);
                h.setmoney(h.getMoney()+100);
                break;
            }
            case 7:{
                cout<<"Community Chest: You coordinate opening day activities at progressive field. Collect $250 for your services\n";
                h.setmoney(h.getMoney()+250);
                break;
            }
            case 8:{
                cout<<"Community Chest: Your computer network gets hit with a virus. Pay $1000\n";
                h.setmoney(h.getMoney()-1000);
                break;
            }
            case 9:{
                cout<<"Community Chest: Sell your lifetime, 50-yard line, season tickets on e-bay. Collect $200\n";
                h.setmoney(h.getMoney()+200);
                break;
            }
            case 10:{
                cout<<"Community Chest: Win big at the casino. Collect $1000\n";
                h.setmoney(h.getMoney()+1000);
                break;
            }
            case 11:{
                cout<<"Community Chest: You owe back taxes. Pay $500 in fines\n";
                h.setmoney(h.getMoney()-500);
                break;
            }
            case 12:{
                cout<<"Community Chest: You win the lottery. Collect $1000\n";
                h.setmoney(h.getMoney()+1000);
                break;
            }
            case 13:{
                cout<<"Community Chest: You are a runner up on a reality Tv show. Collect $100\n";
                h.setmoney(h.getMoney()+100);
                break;
            }
            case 14:{
                cout<<"Community Chest: Arrested for insider trading. Go to jail. DO NOT PASS 'GO', DO NOT COLLECT $200\n";
                g.setprison(false);
                jail(h,c,g,pmove,cmove);
                break;
            }
            case 15:{
                cout<<"Community chest: Received a presidential pardon. GET OUT OF JAIL FREE. This card may be kept until needed.\n";
                break;
            }
            default: cout<<"Error: In the switch statment\n";
            }
    }else if(g.getwho()==false){
        switch(random){
            case 1:{
                cout<<"Community Chest: Make it Big in HollyWood. Collect $2000 in a movie deal\n";
                c.setmoney(c.getMoney()+2000);
                break;
            }
            case 2:{
                cout<<"Community Chest: You promote your new Book on tv morning news. Receive $100 in bonus sales\n";
                c.setmoney(c.getMoney()+100);
                break;
            }
            case 3:{
                cout<<"Community Chest: Advance to 'Go'(Collect $200)\n";
                cmove[c.getloc()]=0;
                c.setroll(0);
                c.setloc(0);
                compmove(c,pmove);
                cout<<"You passed 'Go' collect $200\n";
                c.setmoney(c.getMoney()+200);
                break;
            }
            case 4:{
                cout<<"Community Chest: Your trust fund becomes available. Collect $500\n";
                c.setmoney(c.getMoney()+500);
                break;
            }
            case 5:{
                cout<<"Community Chest: Take dance lessons with a celebrity coach. Pay $500\n";
                c.setmoney(c.getMoney()-500);
                break;
            }
            case 6:{
                cout<<"Community Chest: You run for mayor. Collect $100 from each player to fund your campaign\n";
                h.setmoney(h.getMoney()-100);
                c.setmoney(c.getMoney()+100);
                break;
            }
            case 7:{
                cout<<"Community Chest: You coordinate opening day activities at progressive field. Collect $250 for your services\n";
                c.setmoney(c.getMoney()+250);
                break;
            }
            case 8:{
                cout<<"Community Chest: Your computer network gets hit with a virus. Pay $1000\n";
                c.setmoney(c.getMoney()-1000);
                break;
            }
            case 9:{
                cout<<"Community Chest: Sell your lifetime, 50-yard line, season tickets on e-bay. Collect $200\n";
                c.setmoney(c.getMoney()+200);
                break;
            }
            case 10:{
                cout<<"Community Chest: Win big at the casino. Collect $1000\n";
                c.setmoney(c.getMoney()+1000);
                break;
            }
            case 11:{
                cout<<"Community Chest: You owe back taxes. Pay $500 in fines\n";
                c.setmoney(c.getMoney()-500);
                break;
            }
            case 12:{
                cout<<"Community Chest: You win the lottery. Collect $1000\n";
                c.setmoney(c.getMoney()+1000);
                break;
            }
            case 13:{
                cout<<"Community Chest: You are a runner up on a reality Tv show. Collect $100\n";
                c.setmoney(c.getMoney()+100);
                break;
            }
            case 14:{
                cout<<"Community Chest: Arrested for insider trading. Go to jail. DO NOT PASS 'GO', DO NOT COLLECT $200\n";
                g.setcprison(false);
                jail(h,c,g,pmove,cmove);
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
