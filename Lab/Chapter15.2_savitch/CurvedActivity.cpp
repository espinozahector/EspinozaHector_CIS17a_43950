/* 
 * File:   CurvedActivity.cpp
 * Author: rcc
 * Created on November 24, 2015, 3:49 PM
 */

#include "CurvedActivity.h"

void CurvedActivity::setScore(float s){
    rawScore = s;
    GradedActivity::setScore(rawScore * percentage);
}
void CurvedActivity::setPercentage(float c){
    percentage = c;
}
