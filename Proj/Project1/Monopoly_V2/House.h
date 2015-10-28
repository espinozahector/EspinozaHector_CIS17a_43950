/* 
 * File:   House.h
 * Author: Hector Espinoza
 * Created on October 13, 2015, 1:08 PM
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

