//
//  poly.h
//  poly
//
//  Created by Alma Niu on 2/2/18.
//  Copyright © 2018 Coen79. All rights reserved.
//

#ifndef poly_h
#define poly_h
#include <iostream>

namespace coen79_lab4{
    class poly{
        
    public:
        static const unsigned int MAXIMUM_DEGREE=29;
        static const size_t CAPACITY=30;
        
        void update_current_degree(); //degree 3 is x^3
        
         //size of maximum exponenet allowed for a polynomial
        poly(double c=0.0, unsigned int e=0);
           //initialize all coefficients to 0
        
        //Modification Member Functions
        void assign_coef(double coefficient, unsigned int exponent);
        void add_to_coef(double amount, unsigned int exponent);
        void clear( );
        
        //Constant Member Functions
        poly antiderivative( ) const;
        double coefficient(unsigned int exponent) const;
        double definite_integral(double x0, double x1) const;
        unsigned int degree( ) const;
        poly derivative( ) const;
        double eval(double x) const;
        bool is_zero( ) const;
        unsigned int next_term(unsigned int e) const;
        unsigned int previous_term(unsigned int e) const;
        //Constant Operators
        double operator() (double x) const;
        
        friend poly operator +(const poly& p1, const poly& p2);
        friend poly operator -(const poly& p1, const poly& p2);
        friend poly operator *(const poly& p1, const poly& p2);
        friend std::ostream& operator << (std::ostream& out, const poly& p);
        
    private:
        double data[CAPACITY];
        
    };
    
    
    
    
    // NON-MEMBER OUTPUT FUNCTIONS
    
    
}

#endif /* poly_h */
