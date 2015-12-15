/* 
 * File:   FinalExam.h
 * Author: Hector Espinoza
 * Created on November 24, 2015, 11:58 AM
 */

#ifndef FINALEXAM_H
#define	FINALEXAM_H
#include "GradedActivity.h"

class FinalExam : public GradedActivity{
private:
    int numQuestions; // Number of questions
    float pointsEach; //points for each question
    int numMissed; //Number if questions missed
public:
    //Default Constructor
    FinalExam();
    //Constructor
    FinalExam(int,int);
    //Mutator Function
    void set(int,int);
    //Accessor functions
    float getNumQuestions() const { return numQuestions; }
    float getPointsEach() const { return pointsEach; }
    int getNumMissed() const { return numMissed; }

};

#endif	/* FINALEXAM_H */

