//.CPP File


/* comment on invariants  required*/

#include "sequence.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include<cstdlib>
#include <cmath>


namespace scu_coen79_3{
    
    bool sequence::is_item() const {
        if(current_index<used){
            return true;
        }
        return false;
    }
   void sequence:: start(){
       current_index=0;
    }
    
    void sequence::end(){
        //iterator points to last item in sequence
        current_index=used-1;
    }
    
    void sequence::last(){
        //set to capacity-1, regardless of number of items in sequence
        current_index=CAPACITY-1;
        
    }
    
   
    
    void sequence::advance(){
        assert(is_item());
        if(current_index<used){
        // not current_indext+1, or will loop forever
            current_index++; //advance index
        }
    }
    
    void sequence::retreat(){
        if(current_index>0){
            current_index--; //decrement index
        }
    }
    
    void sequence::insert(const value_type & entry){
        assert(size()<CAPACITY);
        if(used==0){
            data[used]=entry;
            current_index=0;
            
            //one item inserted
        }
        else {
        //insert new item in front of index
            for ( int i=used;i>=current_index+1;--i){
                data[i]=data[i-1];
             }
            data[current_index]=entry;
            //new item is now current item of sequence
          }
        
        used++; //increment size
    }
    void sequence::attach(const value_type & entry){
        assert(size()<CAPACITY);
        
        if (!is_item()){ //if no current item, place in end
            data[used]=entry;
        }
        else {
        for ( int i=used;i>current_index +1;--i){
            data[i]=data[i-1];
            //shift everything to right, make room to attach entry behind current_index
        }
        data[current_index+1]=entry;
            current_index=current_index+1;
        }
        used++; //increment size
        }
    
    void sequence::remove_current(){
        assert(is_item()==true);
       
        
        for ( int i=current_index+1;i<used;++i){
            data[i-1]=data[i]; //shift item to left
        }
        used--; //decrement used by 1
    }
    
    void sequence::insert_front(const value_type & entry) {
        assert(size()<CAPACITY);
        current_index=0;
        insert(entry);
        used++; //increment size
    }
    
    void sequence::attach_back(const value_type & entry){
        assert(size()<CAPACITY);
        data[used]=entry; //attach at end
        used++; //increment size
    }
   
    
    void sequence::remove_front(){
        for ( int i=0;i<used-1;++i){
            data[i]=data[i+1]; //shift everything to left
        }
        used--;//decrement used
    }
    
    sequence::value_type sequence::current() const{
        assert(is_item());
        return data[current_index]; //return item
    }
    
    sequence::value_type sequence::operator[] ( int index)const {
        assert(index<used);
        return data[index]; //return item in desired index
    }
    
    double sequence::mean() const{
        double sum=0.0;
        for ( int i=0; i<used;++i){
            sum+=data[i];
        }
        return sum/size();
    }
    double sequence::standardDeviation() const {
        
        double stanDev=0.0;
        for ( int i=0;i<used;++i){
            stanDev+=pow(data[i]-mean(),2);
        }
        return sqrt(stanDev/used); 
    }
    
    sequence operator +=(const sequence& lhs, const sequence& rhs){
        sequence n(lhs); //copy of lhs
        int start=lhs.used;
        n.used=lhs.used+rhs.used;
        
        for ( int i=0;i<rhs.used;++i){ //add everything from rhs to lhs
            n.data[start]=rhs.data[i];
            start++;
        }
        return n;//return copy of lhs, executes
    }
   
    sequence operator +(const sequence& lhs, const sequence& rhs){
        sequence answer;
        assert(lhs.size()+ rhs.size()<=sequence::CAPACITY);
        answer+=lhs;
        answer+=rhs;
        return answer;
    }
    
    sequence::value_type summation(const sequence &s){
        double total=0.0;
        for ( int i=0; i<s.size();++i){
            total+=s.data[i];
        }
        return total;
    }
   
    
}
    
    

