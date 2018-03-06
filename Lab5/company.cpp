// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)


#include <cassert>
#include "company.h"
#include<string>
//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);
        this->company_name=company_name;
        this->head_ptr=NULL; this->tail_ptr=NULL;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);
        
        // COMPLETE THE IMPLEMENTATION...
        *this=src;
    }
    
    
    company& company::operator= (const company &src) {//
        Debug("Company assignemnt operator..." << std::endl);
       
        // COMPLETE THE IMPLEMENTATION...
        //company test;
        list_clear(this->head_ptr);
        list_copy(src.head_ptr,this->head_ptr,this->tail_ptr);
        this->company_name=src.company_name;
    
        return *this; //return object
    }
    
    
    company::~company() {
        list_clear(head_ptr);
    }
    
    
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    
    bool company::insert(const std::string& product_name, const float& price) {
        
        assert(product_name.length() > 0);
        
        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        node* new_node=new node(product_name, price,NULL);
        if (head_ptr == NULL) {
            // COMPLETE THE IMPLEMENTATION...
            
            tail_ptr=head_ptr=new_node; //set head and tail to new node
        }
        else {
            // COMPLETE THE IMPLEMENTATION...
            tail_ptr->setLink(new_node); //set tail_ptr and make tail_ptr to new node
            tail_ptr=new_node;
        }
        
        return true;
    }
    
  
    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);
        
        // COMPLETE THE IMPLEMENTATION...
        if(head_ptr==NULL) return false;
        if(!list_contains_item(head_ptr,product_name)){ //use listcontains to erase
            return false;
        }
        node* temp;
        if(head_ptr->getName().compare(product_name)==0)
        {   temp=head_ptr; head_ptr=head_ptr->getLink(); //erase specific product
            free(temp); return true;
            
        }
        
        node *prev;
        prev=temp=head_ptr; //check malloc error here
        while(temp!=NULL){
            if(temp->getName().compare(product_name)==0){
                break;
            }
            prev=temp; temp=temp->getLink(); //erase specific product
        }
        
        prev->setLink(temp->getLink());
        free(temp); //free node
        return true;
        
    }
    
    
}
