//
//  main.cpp
//  poly
//

//
#include "poly.h"
#include<fstream>
#include<cassert>
#include <iostream>
#include<climits>
#include<cmath>
using namespace std;

namespace coen79_lab4{
    
    poly::poly(double c,unsigned int exponent){//constructor 
        assert(exponent<=MAXIMUM_DEGREE);
        for( int i=0; i<CAPACITY;++i){
            data[i]=0; //assume zero
        }
        data[exponent]=c;
       //polynomial with all zero coefficients
        }
     void poly::assign_coef(const double coefficient, unsigned int exponent){
        assert(exponent<=MAXIMUM_DEGREE);
        data[exponent]=coefficient;//assign coefficient
    }
    
    void poly::add_to_coef(const double amount, unsigned int exponent){ //add const to strengthen link
         assert(exponent<=MAXIMUM_DEGREE); //apparent origianl 3.45x, assining random number
        data[exponent]+=amount;             //but derivative 3.45 degree 0, so working
    }
    void poly::clear(){
        poly(0.0,0.0); //all coe-efficients set to 0
    }
    
    unsigned int poly::degree() const{
        for ( int i=CAPACITY-1;i>=0;--i){
            if(data[i]!=0){
                return i;
            }
        }
        return 0; //return highest degree in polynomial
    }
    /*
    poly::antiderivative() const {
        
    }
    */
    double poly::coefficient(unsigned int exponent) const{
        if(exponent>MAXIMUM_DEGREE){
            return 0;
        }
        else {
            return data[exponent]; //return value in exponent
        }
    }
    
    double poly::eval(double x) const {
        for ( int i=0; i<CAPACITY;++i){
            if(data[i]==x){
                return data[i]; //return value
            }
        }
        return NULL;//else null
    }
    
    
    poly poly::antiderivative() const{
        assert(degree()<MAXIMUM_DEGREE);
        poly a(0,0); //create new polynomial
        a.data[0]=0;
        for ( int i=0; i<MAXIMUM_DEGREE;++i){
            a.data[i+1]=(data[i]/(i+1)); //shift everything to right
        }
        return a;//return new polynomial
    }
    
    double poly::definite_integral(double x0,double x1) const {
        poly b;
        b=antiderivative();
        
        double upper=0.0;
        double lower=0.0;
        for ( int i=0;i<MAXIMUM_DEGREE;++i){
            upper+=(b.data[i] * pow(x0,i)); //evaluate sum of upper bound
            lower+=(b.data[i]*pow(x1,i));//evaluate sum of lower bound
        }
        return upper-lower;//return difference
        }
    
    poly poly::derivative() const {
        poly c;
        for ( int i=1; i<MAXIMUM_DEGREE;++i){
            c.data[i-1]=(data[i]*i); //compute derivative
        }
        return c;
    }
    
    bool poly::is_zero() const {
        //if entire array is 0
        for ( int i=0; i<MAXIMUM_DEGREE;++i){
            if(data[i]!=0){
                return false;
            }
        }
        return true; //polynomial is all zero
    }
    
    unsigned int poly::next_term(unsigned int e) const {
        for ( int i =e+1; e<CAPACITY;++i){
            if(data[i]!=0){
                    return i; //get next term
        }
        }
     return 0;
    }
    
    unsigned int poly::previous_term(unsigned int e ) const {
        for ( int i=e-1;i>=0;--i){
            if(data[i]!=0){
                return i;//get previous term that is not zero
            }
        }
        return 0;
    }
    double poly::operator()(double x) const{
        return eval(x); //return eval
    }
    
    poly operator+(const poly& p1, const poly& p2){
       
        poly result;
        for ( int i=0; i<poly::CAPACITY;++i){
            result.data[i]=p1.data[i]+p2.data[i];
        }  //addiction operator
         
        return result;
    }
    
    poly operator-(const poly& p1, const poly& p2){
        poly result;
        for ( int i=0; i<poly::CAPACITY;++i){
            result.data[i]=abs(p1.data[i]-p2.data[i]);
        }  //difference of p1 and p2
        return result;
    }
    
    poly operator*(const poly& p1, const poly& p2){
        assert(p1.degree()+p2.degree()<=poly::MAXIMUM_DEGREE);
        poly result;
        for ( int i=0; i<poly::CAPACITY;++i){
            for ( int j=0; j<poly::CAPACITY;++j){
                result.data[i+j]+=(p1.data[i]*p2.data[j]);
            }
        }  //multiplication of pl and p2
       
        return result;
    }
    
    std::ostream& operator <<(ostream& out, const poly& p){
       
        for ( int i=p.degree();i>=0;--i){
            if( i>1){
                out<<p.data[i] +'x^'+i+' '; //output and show degree
             }
            else if (i==1){
                out<<p.data[i]+'x'+ ' ';//output and show x
            }
            else if(i==0){
                out<<p.data[i]; //output number
            }
        }
        return out; //need to return out b/c ostream
    }
    
   
}//namespace


