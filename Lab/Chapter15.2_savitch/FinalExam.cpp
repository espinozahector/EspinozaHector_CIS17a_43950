/* 
 * File:   FinalExam.cpp
 * Author: Hector Espinoza
 * Created on November 24, 2015, 11:58 AM
 */

#include "FinalExam.h"

FinalExam::FinalExam(){
    numQuestions=0;
    pointsEach=0.0;
    numMissed=0;
}
FinalExam::FinalExam(int a, int b){
    set(a,b);
}
void FinalExam::set(int a, int b){
    float numericScore; //top hold the numeric score
    
    //set the number of questions and number missed
    numQuestions = a;
    numMissed = b;
    
    //Calculate the points for each question
    pointsEach = 100.0 / numQuestions;
    
    //Calculate the numeric score for this exam
    numericScore = 100.0 - (b * pointsEach);
    
    //Call the inherited score function to set the numeric score
    setScore(numericScore);
}