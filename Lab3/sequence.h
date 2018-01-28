//HEADER FILE

#ifndef SCU_coen79_SEQUENCE_H
#define SCU_coen79_SEQUENCE_H
#include <cstdlib>

namespace scu_coen79_3 {
    class sequence
    { public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;//whenver put size_type, will label size_t
        static const size_type CAPACITY = 50;
       
        // CONSTRUCTOR
        sequence( ){used=0;};
        
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
           //reset to position 0
        void end();
            //points to last item in sequence
        void last();
            //iterator reset to cap-1, regardless of num items in sequence
    
        void advance( );
            //pre:isitem() returns true
            //post:iterator increased by one
        
        void retreat();
            //iterator retreats by one
        
        void insert(const value_type& entry);
            //insert item before current index and new item becomes index
        
        void attach(const value_type& entry);
            //insert item after current index and new item becomes index
        void remove_current();
            //Precondtion: isitem() returns true
            //Postcondition: The current item has been removed from the sequence
        
        void insert_front(const value_type & entry);
        
        void attach_back(const value_type & entry);
        
        void remove_front();
        
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const{return used;};
            //inline member function
        
        bool is_item( ) const;
       
        value_type current() const;
            //return current item
        
        value_type operator[] (int index) const;
            //return item at specific index
       
        double mean() const;
            //mean of values stored in sequence
        
        double standardDeviation() const;
            //standard deviation of values stored
        
    friend sequence operator +=(const sequence& lhs, const sequence& rhs);
    
    friend sequence::value_type summation(const sequence &s);
    
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
   
    sequence operator +(const sequence& lhs, const sequence& rhs);

}




#endif /* sequence_h */
