/* 
 * File:   Gaming.h
 * Author: rcc
 *
 * Created on December 10, 2015, 3:29 PM
 */

#ifndef GAMING_H
#define	GAMING_H

class Gaming {
protected:
    bool who;//used to see who's turn it is
    bool prison;//If the player is in jail 
    bool cprison;//If the computer is in jail
    bool game;//to continue the game until there is a winner
    int turn; //Turns if the player or computer land on jail
public:
    Gaming();
    
    void setwho(bool);
    void setprison(bool);
    void setcprison(bool);
    void setgame(bool);
    void setturn(int);

    bool getwho() const { return who; }
    bool getprison() const { return prison; }
    bool getcprison() const { return cprison; }
    bool getgame() const { return game; }
    int getturn() const { return turn; }
};

#endif	/* GAMING_H */

