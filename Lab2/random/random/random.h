//
//  random.h
//  random
//
//  Created by Alma Niu on 1/19/18.
//  Copyright © 2018 Coen79. All rights reserved.
//

#ifndef random_h
#define random_h
#include <iostream>
#include<cassert>
using namespace std;

namespace coen79_lab2 {
    class rand_gen
    {
    public:
        rand_gen(int s=0,int m=0,int i=0,int mod=0){
            seed=s;
            multiplier=m;
            increment=i;
            modulus=mod;
        }
        void set_seed(int newSeed);
        
        int next();
        
        void print_info();
        
    private:
        int multiplier, increment, modulus, seed;
        
    };
}

#endif /* random_h */
