/* 
 * File:   main.cpp
 * Author: rcc
 * Created on November 24, 2015, 11:32 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "FinalExam.h"
#include "CurvedActivity.h"

int main(int argc, char** argv) {
    float numericScore;
    float percentage;
    
    //Define a CurvedActivity Object
    CurvedActivity exam;
    
    //Get the unadjusted score
    cout << "Enter the student's raw numeric score: ";
    cin >> numericScore;
    
    // Get the curve percentage.
    cout << "Enter the curve percentage for this student: ";
    cin >> percentage;
    
    //Send the values to the exam object
    exam.setPercentage(percentage);
    exam.setScore(numericScore);
    
    //Display the grade data
    cout<<fixed << setprecision(2);
    cout<<"The raw score is " << exam.getRawScorew() << endl;
    cout<<"The curved score is " << exam.get_score() <<endl;
    cout<<"The curved grade is " << exam.getLetterGrade() <<endl;
    
    return 0;
}

