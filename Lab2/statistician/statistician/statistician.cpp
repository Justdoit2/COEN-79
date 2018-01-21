//
//  main.cpp
//  statistician
//
//  Created by Alma Niu on 1/19/18.
//  Copyright © 2018 Coen79. All rights reserved.
//
#include <cassert>
#include "statistician.h"
#include <iostream>
#include <algorithm>


using namespace std;
using namespace coen79_lab2; //for main
namespace coen79_lab2 //header definition
{
    //functions implemented here
    void statistician::next(double r)
    {
        total+=r; //increment sum
        used++;   //increment total
        if(length()==1){
            min=r; max=r;
        }
        else {  //set max and min
            if(r>max){
                max=r;
            }
            else if(r<min){
                min=r;
            }
        }
    }
    void statistician::reset()
    {
        total=0.0; used=0.0; //clear back to 0
    }
    
    double statistician::sum() const
    {
        return total; //return total items
    }
    
    double statistician::mean() const
    {
        assert(length()>0);
        return sum()/used; //return sum
    }
    
    double statistician::minimum() const
    {
        assert(length()>0);
        
        return min;  //return minimum
    }
    
    double statistician::maximum() const
    {
        return max; //return maximum
    }
    
    
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        return (s1.length()==s2.length() &&  //compare all attributes to ensure equal
                s1.mean()==s2.mean() &&
                s1.sum()==s2.sum() &&
                s1.maximum()==s2.maximum() &&
                s1.minimum()==s2.minimum());
        
    }
    
    statistician operator+(const statistician& s1, const statistician& s2){
        
        statistician c;  //add
        //add private member variables and set it to c's private member variables
        c.total=s1.total+s2.total;
        c.used=s1.used+s2.used;
        c.min=(s1.min<s2.min)?s1.min:s2.min;
        c.max=(s1.max>s2.max)?s1.max:s2.max;
        
        return c;
        
    }
    
    statistician operator *(double scale, const statistician& s){
        //multiply most private member variables with scale
        statistician c;
        c.total=(scale * s.total);
        
        c.used=s.used;
        c.min=(scale * s.min);
        c.max=(scale *s.max);
        
        
   
        return c;
    }
    
}






// Helper function to print statistician info
void printStatisticianInfo(statistician & s) {
    cout << "Sum: " << s.sum() << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "Smallest: " << s.minimum() << endl;
    cout << "Largest: " << s.maximum() << endl;
    cout << endl;
}

// main function
int main(int argc, const char * argv[])
{
    statistician s1, s2, s3;
    
    cout << "--- s1 prints ---" << endl;
    
    s1.next(1.0);
    printStatisticianInfo(s1);
    
    s1.next(2.0);
    printStatisticianInfo(s1);
    
    s1.next(3.0);
    printStatisticianInfo(s1);
    
    cout << "--- s2 prints ---" << endl;
    
    s2.next(4.0);
    printStatisticianInfo(s2);
    
    s2.next(5.0);
    printStatisticianInfo(s2);
    s2.next(6.0);
    printStatisticianInfo(s2);
    
    s3 = s1 + s2;
    
    cout << "--- s3 print ---" << endl;
    
    printStatisticianInfo(s3);
    
    cout << "--- erase prints ---" << endl;
    
    s1.reset();
    s1.next(5);
    printStatisticianInfo(s1);
    
    s2 = s1;
    printStatisticianInfo(s1);
    
    s1.reset();
    s2.reset();
    s1.next(4);
    s2.next(4);
    if (s1 == s2)
        cout << "s1 is equal to s2" << endl;
    
    cout << endl << "--- scaling test ---" << endl;
    
    s1.reset();
    s1.next(4);
    s1.next(-2);
    printStatisticianInfo(s1);
    s1 = -1* s1;
    printStatisticianInfo(s1);
    
    
    
    
    return 0;
}

