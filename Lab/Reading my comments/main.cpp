/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on December 9, 2015, 10:37 AM
 * Purpose: To read only comments
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    char temp;
    bool found=false;
    ifstream fin;
    ofstream fout;
    
    cout<<"Opening Files...\n"; 
    fin.open("old.txt", ios::in);
    fout.open("new.txt", ios::out);
    
    //Only reading in the comments
    while (!fin.eof() ) {
        fin.get(temp);
        if (temp == '/' || temp == '*'){
            found = true;
        }
        if(found == true){
            fout << temp;
        }
        if (temp == '\n'){
            fout << endl;
            found =false;
        }
    }
    cout<<"Done =D\n";
    cout<<"Closing Files...\n";
    
    fin.close();
    fout.close();
    return 0;
}


