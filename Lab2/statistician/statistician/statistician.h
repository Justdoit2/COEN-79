//
//  statistician.h
//  statistician
//
//  Created by Alma Niu on 1/19/18.
//  Copyright © 2018 Coen79. All rights reserved.
//

#ifndef statistician_h
#define statistician_h
#include <climits>
#include<iostream>
#include<cstdlib>

namespace coen79_lab2
{
    class statistician
    {
    public:
        
        //CONSTRUCTOR
        statistician(){used=0.0; total=0.0;}; //new statistician size is 0
        
        //MEMEBER FUNCTION
        void next(double r);
        void reset();
        double length() const {return used;};
        double sum() const;
        double mean() const;
        double minimum() const;
        double maximum() const;
   
    //ACCESS PRIVATE VARIABLES
    friend statistician operator +(const statistician& s1, const statistician& s2);
    friend statistician operator *(double scale, const statistician& s);
    
    private:
        
        double used,total; //keep track of index of double integers
        double min=INT_MAX;
        double max=INT_MIN;
    };
    //NONMEMBER FUNCTIONS
    
    
    bool operator ==(const statistician& s1, const statistician& s2);
    
    
}


#endif /* statistician_h */


