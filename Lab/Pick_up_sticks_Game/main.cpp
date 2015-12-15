#include <iostream>
using namespace std;


int main()
{	
    // initializing variables. h_pick = human pick. c_pick = computer pick. 
    int toothpicks, h_pick, c_pick;
    bool game_finished;
    bool over =true;
    do{
        cout << "Welcome to the toothpick game!" << endl;        
		game_finished = false;
		toothpicks = 23; //starts new game.
                int turn=1;
		while (!game_finished)
		{
                   do{
                        cout<<"Please pick up your toothpick(s). Choose between 1,2,or 3."<<endl;
                        cout << toothpicks << " toothpicks are remaining." << endl;
                        cin>> h_pick;
                        if(h_pick<1 || h_pick>3){
                            cout<<"You did not choose a 1, 2 , or 3."<<endl;
                        }
                    }while(h_pick<1 || h_pick>3);
                    if(h_pick>1 || h_pick<3){
                                //update toothpicks remaining.
				toothpicks = toothpicks - h_pick;
                    }
                       if(toothpicks>4){
                        c_pick=4-h_pick;
                        toothpicks=toothpicks-c_pick;
                        cout << "The computer took " << c_pick << " toothpick(s)." << endl; // update toothpicks remaining.
                        }else if(toothpicks<=4 && toothpicks>1){
                            c_pick=toothpicks-1;
                            toothpicks= toothpicks-c_pick;
                        cout << "The computer took " << c_pick << " toothpick(s)." << endl; // update toothpicks remaining.
                        }else{
                            c_pick=1;
                            toothpicks= toothpicks-c_pick;
                        cout << "The computer took " << c_pick << " toothpick(s)." << endl; // update toothpicks remaining.
                        }
                   
                   if(toothpicks<=0){
                       int check;
                       if(turn%2==0){
                           check=2;
                       }else if (turn%1==0){
                           check=1;
                       }
                       if(check==1){
                           cout<<"The Computer Wins!!YOU LOSE!!!"<<endl;
                       }else if(check==2){
                           cout<<"YOU WIN!!!"<<endl;
                       }
                        game_finished = true;
                   }
                   turn++;
                                  
            }    
                int again;
                cout<<"Do you want to end the game?\n";
                cin>>again;
                if(again !=1){
                    over=false;
                }else{
                    
                }
    }while(!over);
		return 0;
}
