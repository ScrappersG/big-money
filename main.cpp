//
//  main.cpp
//  group ibrahim part
//
//  Created by ibrahim ibrahim on 6/9/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include<fstream>
#include <stdlib.h>
#include <cmath>
#include "scrapper.h"
#include "hash.h"
#include "linkedlist.h"
using namespace std;



// parse data then create objects,
void readinfile(HASH*);

// used to parse the data, readinfile helper
void seperatedata(string&, string&, int&, int&, int&, int&, string&, string&, double&, double&);


void menu(); // displays choices for general menu

// hash table menu
void menu_hash(HASH*); //
void menu_hash_display(); // displays the menu for menuhash


// return lines in the input file,
// used to make hash table
int txt_linecount();

// return prime number, used for hashtable
// used for hashtable size
int returnPrime(int number);

// returnPrime helper
bool checkprime(int number);


int main()
{
   
  // make hashtable using the amount of lines in the text file multiplied by 2, then get next prime number
    int x = txt_linecount();
    x=returnPrime(x);
    
    HASH* hash = new HASH(x);
    
    
    readinfile(hash);
    
 
    char choice;
 
    cout << "LADIES AND GENTLEMEN WELCOME TO THE MAIN EVENT LETS GET READY TO make hashtables and bst's" << endl;
    cout << endl;
    do
    {
        menu();
        cin>>choice;
      
        if(toupper(choice)=='H')
            menu_hash(hash);
        
    }while(toupper(choice)!='Q');
    
    
    delete hash;
    
    
    cout<<'\n' << '\n' <<endl;
    cout << "WE'RE JUST HERE SO WE WON'T GET FINED " << endl;
    
    
    

   
    return 0;
}


void readinfile(HASH* hash)
{
    ifstream infile;
    infile.open("tower.txt");
    if(!infile)
    {
        cout << "No such file exists." << endl;
		return;
    }
    /////////////// changed varriabels to be less shit
    string temp; // stores the entire line and is used separate the data into the various variables
    string name;
    int floors = 0;
    int year = 0;
    int ft = 0;
    int m = 0;
    string city;
    string country;
    double longitude;
	double latitude;
    int x=0;
    while(getline(infile, temp))
    {
        // info used to determine if rehhashing is needed
        double load = hash->getload();
        double old_hashsize = hash->return_hashsize();
        
        
        seperatedata(temp, name, floors, year, ft, m, city, country, longitude, latitude); // temp holds the entier string
        
        Scrapper *data = new Scrapper;
        data->setdata(name, ft, m, country,floors,city,year, longitude, latitude);
        
        
        
        if ( (100* (load/old_hashsize) ) >= 75 )
        {
            
            int newhashtablesize =  old_hashsize*2;
            newhashtablesize = returnPrime(newhashtablesize);
         
          
            
            hash->rehash(newhashtablesize);
         
            
            
        }
        
        
        
        
        
        hash->add(data);
        
      
    }
    infile.close();    
}


void seperatedata(string& temp, string& na, int& flo, int& yea, int& ft,
                  int& m, string& cit, string& coun, double& longt, double& lat)
{
    int i = 0;
   // string floor; // why is this here
    
    na = temp.substr(0, temp.find(';'));
    i = i + na.length() + 1;
    cit = temp.substr(i, temp.find(';', i) - i);
    i = i + cit.length() + 1;
    coun = temp.substr(i, temp.find(';', i) - i);
    i = i + coun.length() + 1;
    m = atoi(temp.substr(i, temp.find(';', i) - i).c_str());
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    ft = atoi(temp.substr(i, temp.find(';', i) - i).c_str());
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    flo = atoi(temp.substr(i, temp.find(';', i) - i).c_str());
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    yea = atoi(temp.substr(i, temp.find(';', i) - i).c_str());
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1; 
    longt = atof(temp.substr(i, temp.find(';', i) - i).c_str());
	i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
	lat = atof(temp.substr(i, temp.length() - i).c_str());
	

}


/*
 returns the line count from the cvs file.
 no parameters.
 */
int txt_linecount()
{
    int count=0;
    string line;
    ifstream infile_count;
    infile_count.open("tower.txt");
    
    if(infile_count.fail())
    {
        cout << "Error opening file" << endl;
    }
    
    while (getline(infile_count,line))
    {
        
        ++count;
    }
    infile_count.close();
    
    if (count%2==0)
    {
        return count;
    }
    else
    {
        count=count+1;
        return count;
    }
    
}

int returnPrime(int number)
{
    int prime = number;
    bool finder;
    
    
    
    
    while (!finder)
    {
        prime++;
        
        if (!checkprime(prime))
            finder=true;
    }
    
    
    
    return prime;
}



bool checkprime(int number)
{
    
    for (int x = 2; x <= number/2; x++)
    {
        if (number % x == 0)
            return true;
    }
    
    return false;
}









//A general menu that can go into more specifics liek workign with the bst and hash
void menu()
{
    cout <<endl;
    cout << "//======================  MENU  =========================\\" <<endl;
    cout << "|*|=====================================================|*|" <<endl;
    cout << "||     Enter a key:                                      ||" <<endl;

    cout << "||H: to access Hash Menu                                 ||" <<endl;
 
    cout<<endl;
}

/*******
 menu display the Hash Menu.
 let the user select from the menu.
 *******/
void menu_hash_display()
{
    cout<<endl;
    cout << "//===============  HASH MENU MADE COOL  =================\\" <<endl;
    cout << "|*|=====================================================|*|" <<endl;
    cout << "||    PRINTERS                                           ||" <<endl;
    cout << "||D: Display content of the hash table                   ||" <<endl;
    cout << "||O: Print overflow from hash table                      ||" <<endl;
    cout << "||P: Print the hash table                                ||" <<endl;
    cout << "||M: Show Menu                                           ||" <<endl;
    cout << "||T: Show the statistics                                 ||" <<endl;
    cout << "||                                                       ||" <<endl;
    cout << "||  SEARCHERS                                            ||" <<endl;
    cout << "||S: Search for skyscaper in the hash table              ||" <<endl;
    cout << "||                                                       ||" <<endl;
    cout << "||    OTHERS                                             ||" <<endl;
    cout << "||H: Height comparison between you and any skyscrapper   ||" <<endl;
    cout << "||A: Add a skyscraper to the data structure              ||" <<endl;
    cout << "||R: Remove skyscraper from hash table                   ||" <<endl;
    cout << "||Q: Quit                                                ||" <<endl;
    cout << "|*|=====================================================|*|" <<endl;
    cout<<endl;

}
void menu_hash(HASH*hash)
{
    menu_hash_display();
   
    char choice;
    
    do
    {
        cout << "enter choice: " ;
        cin>>choice;
		cin.ignore(100, '\n');
		cin.clear();
        cout<<endl;
        
        if (toupper(choice)=='A')
        {
            string test, name,city,country;
            int meter,feet,floors;
            double lat,lon;
			int year = 2015;
            
			cout << "enter the name of the skyscraper: ";
			getline(cin, name);
			cout << endl;
            
			cout << "enter the city in which to build the skyscraper ";
			//cin.clear();
			getline(cin, city);
			
			cout << endl;
            
            cout<<"enter the country in which to build the skyscraper: ";
			cin.clear();
			getline(cin, country);
			
            cout << endl;
            
            cout<<"enter the height of the building (meters): ";
            cin.clear();
            cin>>meter;
			cout << endl;
            
            feet=meter*.3048;
            
            cout<<"how many floors should the building have: ";
            cin.clear();
            cin>>floors;
			cout << endl;
          
            cout << "enter latitude: ";
            cin.clear();
            cin>>lat;
			cout << endl;
            
            cout << "enter longitude: ";
            cin.clear();
            cin>> lon;
            cout << endl;
			 
            Scrapper *new_tower = new Scrapper;
            new_tower->setdata(name, feet, meter, country, floors, city,year,lon,lat);
            hash->add(new_tower);
        }
        
        if (toupper(choice)=='S')
        {
            string name;
            cout << "what's the name of the skyscraper you are looking for: ";
            //cin.ignore();
            getline(cin,name);
            cout<<endl;
            
            Scrapper *max=hash->search(name);
            
            if (max == NULL)
            {
                cout << "'skyscraper not found in file'"<< '\n'<<endl;
            }
            else
            {
                cout << "'found' " <<endl;
                cout << max << '\n' << endl;
            }
        }
        if(toupper(choice)=='H')
        {
            string name;
            cout << "what's the name of the skyscraper you are looking for: ";
           // cin.ignore();
            getline(cin,name);
            cout<<endl;
            
            Scrapper *max=hash->search(name);
            
            if (max== NULL)
            {
                cout << "skyscraper not found in file"<< '\n'<<endl;
            }
            else
            {
                double height = 0;
                cout << "Enter your height in feet; ex.(5.11) :";
                cin >> height;
                cin.ignore();
                cout<<endl;
               
                cout << "It would take " << max->getheightft() / height << " of you standing on top of eachother to be as tall as this tower!"<< '\n'<<endl;
            }
        }
        
        if (toupper(choice)=='R')
        {
            bool succes;
            
            string name;
            cout << "enter name of skyscraper you want to remove: " ;
            //cin.ignore();
            getline(cin,name);
            cout<<endl;
            
            succes = hash->remove(name);
            
            if(succes)
                cout << "'removed'" << '\n'<<endl;
            else
                cout << "skyscraper not found in file"<< '\n'<<endl;
            
        }
        
        if(toupper(choice)=='D')
        {
            hash->print();
        }
        
        if (toupper(choice)=='O')
        {
            cout << "overflow" << '\n'<<endl;
            hash->print_overflow();
        }
        
        if(toupper(choice)=='P')
        {
            hash->print_index();
        }
        
        if(toupper(choice) =='T')
        {
            double load = hash->getload();
            double hashsize = hash->return_hashsize();
            double collision = hash->return_collisions();
            
            cout << "total collisions                        :" << hash->return_collisions() <<  '\n'<<endl;
            cout << "load factor %                           :" << 100*(load/hashsize)<< "%"<< '\n'<<endl;
            cout << "amount of full buckets                  :" << hash->return_buc_two() << '\n'<<endl;
            cout << "amount of empty buckets                 :" << hash->empty_buckets()  << '\n' <<endl;
            cout << "average number of nodes per bucket      : " << (collision/load) << '\n'<<endl;
            cout << "amount of objects that where overflowed :" << hash->count() <<'\n'<<endl;
        }
        
        if(toupper(choice)=='M')
        {
            menu_hash_display();
        }
    }while(toupper(choice)!='Q');
    
}


