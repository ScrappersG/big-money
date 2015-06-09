//
//  hash.cpp
//  group ibrahim part
//
//  Created by ibrahim ibrahim on 6/9/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#include <stdio.h>
#include "tower.h"
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
    struct item
    {
        
        int count; // keeps count for bucket
        tower my_array[3]; // array of objects in bucket
    };
    
    item* ptr;
    
    
public:
    
    // constructor
    HASH(int x);
    
    // destructor
    ~HASH();
    
    
    // member function all return data from hash
    int return_hashsize(){return hashtablesize;}
    int return_collisions(){return  collisions;}
    int return_buc_two(){return fullbucket;}
    int return_load(){return load;}
    int empty_buckets();
    
    
    // hash table operations
    int gethashed(string key);
    void add (tower&);
    tower search(string name);
    void print();
    void print_two();
    
    
    
    
    
    
};
