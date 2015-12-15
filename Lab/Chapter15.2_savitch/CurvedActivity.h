/* 
 * File:   CurvedActivity.h
 * Author: rcc
 * Created on November 24, 2015, 3:49 PM
 */

#ifndef CURVEDACTIVITY_H
#define	CURVEDACTIVITY_H
#include "GradedActivity.h"

class CurvedActivity : public GradedActivity{
protected:
    float rawScore;
    float percentage;
public:
    //Default Constructor
    CurvedActivity() : GradedActivity(){
        rawScore = 0.0; percentage = 0.0;
    }
    //Mutator functions
    void setScore(float);
    void setPercentage(float);
    //Accessor functions
    float getPercentage() const { return percentage; }
    float getRawScorew() const { return rawScore; }

};

#endif	/* CURVEDACTIVITY_H */

