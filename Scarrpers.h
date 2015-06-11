//
//  tower.h
//  group ibrahim part
//
//  Created by ibrahim ibrahim on 6/9/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#ifndef __group_ibrahim_part__tower__
#define __group_ibrahim_part__tower__

#include <stdio.h>
#include<string>
using namespace std;

class Scrapper
{
    
private:
    string name;
    int heightft;
    int heightm;
    string country;
    int floors;
    string city;
    int year;
    string coord;
    
public:
    //default constructor
    Scrapper(string q = "empty", int w = 0, int r = 0, string t = "empty", int y = 0,
             string u = "empty", int i = 0, string o = "empty"):
    name(q), heightft(w), heightm(r), country(t), floors(y), city(u), year(i), coord(o) {}
    
    //setters
    void setname(string n) {name = n;}
    void setheight(int h) {heightft = h;}
    void setheightm(int h) {heightm = h;}
    void setcountry(string f) {country = f;}
    void setfloors(int g) {floors = g;}
    void setcity(string h) {city = h;}
    void setyear(int a) {year = a;}
    void setcoord(string j) {coord = j;}
    
    //getters
    string getname() const {return name;}
    int getheightft() const {return heightft;}
    int getheightm() const {return heightm;}
    string getcountry() const {return country;}
    int getfloors() const {return floors;}
    string getcity() const {return city;}
    int getyear() const {return year;}
    string getcoord() const {return coord;}
    
    //operators
    friend ostream &operator << (ostream& output, const Scrapper& right)
    {
        output << right.getname() << " ;"
               << right.getcountry() << " , "
               << right.getcity() << " ;  "
               << right.getfloors() << " floors, "
               << right.getheightm() << " meters tall, "
               << right.getheightft()
                << " feet tall; coordinates: " << right.getcoord();
        return output;
    }
    
    bool empty()
    {
        if(name=="empty")
            return true;
        else
            return false;
        

    }
    
    
    
    // Overloaded operators
    bool operator == (const Scrapper& obj)
    {
        if( heightft == obj.getheightft())
            return true;
        else
            return false;
    }
    bool operator < (const Scrapper& obj)
    {
        if(heightft < obj.getheightft())
            return true;
        else
            return false;
    }
    bool operator > (const Scrapper& obj)
    {
        
        if(heightft > obj.getheightft())
            return true;
        else
            return false;
        
    }
    bool operator <= (const Scrapper& obj)
    {
        if( heightft <= obj.getheightft())
            return true;
        else
            return false;
    }
    bool operator >= (const Scrapper& obj)
    {
        if( heightft >= obj.getheightft())
            return true;
        else
            return false;
    }
    
    
 
    
};

#endif /* defined(__group_ibrahim_part__tower__) */
