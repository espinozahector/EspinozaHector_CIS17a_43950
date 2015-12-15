/* 
 * File:   GradedActivity.cpp
 * Author: rcc
 * Created on November 24, 2015, 11:43 AM
 */

#include "GradedActivity.h"

GradedActivity::GradedActivity(){
    letter = ' '; 
    score=0.0;
}
void GradedActivity::setScore(float s){
    score=s;
    getLetterGrade();
}
char GradedActivity::getLetterGrade() const {
    char letterGrade;
    if (score > 89)
        letterGrade = 'A'; 
    else if (score > 79) 
        letterGrade = 'B'; 
    else if (score > 69) 
        letterGrade = 'C'; 
    else if (score > 59) 
        letterGrade = 'D'; 
    else 
        letterGrade = 'F';
    return letterGrade;
}

