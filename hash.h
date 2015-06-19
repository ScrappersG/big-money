//
//  hash.h
//  group ibrahim part
//
//  Created by ibrahim ibrahim on 6/9/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#ifndef __group_ibrahim_part__hash__
#define __group_ibrahim_part__hash__

#include <stdio.h>
#include "scrapper.h"
#include "linkedlist.h"
#include <string>

using namespace std;

class HASH
{
private:
    
    int hashtablesize;
    int load;
    int collisions;
    int fullbucket;
    
    // delcare a struct for the hash table
    struct bucket
    {
        int count; // keeps count for bucket
        Scrapper * my_array[3]; // array of objects in bucket
    };

    bucket* ptr;
    
    
    linklist* rejected;

	
public:
    
    // constructor
    HASH(int x);
    
    // destructor
    ~HASH();
    
    // member function all return data from hash
    int return_hashsize(){return hashtablesize;}
    int return_collisions(){return  collisions;}
    int return_buc_two(){return fullbucket;}
    
    int empty_buckets();
    int getload();
    
    
    // hash table operations
    int gethashed(string key);
    bool add (Scrapper*);
    
    //search function
    Scrapper *search(string name);
    
    //remove function
    bool remove(string name);
    
    //both prints
    void print();
    void print_index();
    
    // print overflow from hash table
    void print_overflow(){rejected->print();}
    
    // return count from linked list
    int count(){return rejected->return_count();}
    
    //rehashing function
   void rehash(int hashsize);
    
    // delete pointers for hash, inorder to rehash
    void deletehashptr();
	
    
};



#endif /* defined(__group_ibrahim_part__hash__) */
