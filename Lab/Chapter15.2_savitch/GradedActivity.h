/* 
 * File:   GradedActivity.h
 * Author: rcc
 *
 * Created on November 24, 2015, 11:43 AM
 */

#ifndef GRADEDACTIVITY_H
#define	GRADEDACTIVITY_H

class GradedActivity {
protected:
    char letter;
    float score;
public:
    //Default constructor
    GradedActivity();
    //Mutator Function
    void setScore(float);
    //Acessor function
    float get_score() const { return score;}
    char getLetterGrade() const;
    
    
};

#endif	/* GRADEDACTIVITY_H */

