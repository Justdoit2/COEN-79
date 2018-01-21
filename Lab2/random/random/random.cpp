#include "random.h"
#include <iostream>

using namespace std;
using namespace coen79_lab2;

// Main Functions
namespace coen79_lab2{
    void rand_gen::set_seed(int newSeed){
        seed=newSeed;
    }
    int rand_gen::next(){
        seed=(multiplier *seed+increment) % modulus;
        
        return seed;
    }
    
    void rand_gen::print_info(){
        printf("Multiplier: %d  Seed: %d Increment:%d Modulus:%d\n",
               multiplier, seed, increment, modulus);
    }
}
void printNumbers(rand_gen &r, int num) {
    
    for (int i = 0; i < num; i++) {
        r.print_info();
        cout << "Next: " << r.next() << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    rand_gen rg(1, 40, 725, 729);
    
    printNumbers(rg, 5);
    
    rg.set_seed(1);
    printNumbers(rg, 5);
    
    rg.set_seed(15);
    printNumbers(rg, 5);
    
    
    rand_gen rg2(14, 85, 637, 1947);
    
    printNumbers(rg2, 5);
    
    rg2.set_seed(14);
    printNumbers(rg2, 5);
    
    
    return 0;
}
