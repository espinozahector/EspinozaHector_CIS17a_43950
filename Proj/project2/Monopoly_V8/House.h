/* 
 * File:   Human.cpp
 * Author: Hector Espinoza
 * Created on December 8, 2015, 3:57 PM
 */

#ifndef HOUSE_H
#define	HOUSE_H
using namespace std;

class House{
private:
    string name;
    int buy;
    int rent;
public:
    void setName(string);
    void setBuy(int);
    void setRent(int);
    string getName() const;
    int getBuy() const;
    int getRent() const;
    void print();
    
};

#endif	/* HOUSE_H */

