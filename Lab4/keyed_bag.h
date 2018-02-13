//
//  key_bag.h
//  key_bag
//
//  Created by Alma Niu on 2/2/18.
//  Copyright © 2018 Coen79. All rights reserved.
//

#ifndef keyed_bag_h
#define keyed_bag_h
#include <cstdlib>
using namespace std;
namespace scu_coen79_4{
    class keyed_bag{
        public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef string key_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        
        keyed_bag(){used=0;};
        
        //Modification Member Functions
        void erase();
        bool erase( const key_type& key);
        void insert(const value_type& entry, const key_type& key);
        void operator+=(const keyed_bag& addend);
        //Constant Member Functions
        
        bool has_key(const key_type& key) const;
        value_type get(const key_type& key) const;
        size_type size()const {return used;};
        size_type count(const value_type& target)const;
        bool hasDuplicateKey(const keyed_bag& otherBag) const;
    private:
        key_type keys[CAPACITY];
        value_type data[CAPACITY];
        size_type used;
    };
    
    keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2);
    
}




#endif /* key_bag_h */
