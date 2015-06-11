//
//  main.cpp
//  group ibrahim part
//
//  Created by ibrahim ibrahim on 6/9/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#include <iostream>
#include <string>
#include<fstream>
#include <stdlib.h>
#include <cmath>
#include "scrapper.h"
#include "hash.h"
#include "BinarySearchTree.h"
using namespace std;




void readinfile(HASH*, BinarySearchTree<Scrapper> *tree1Ptr);

void seperatedata(string&, string&, int&, int&, int&, int&, string&, string&, string&);



////////////////////////////////////////////////////////////////////////////////////////////////

// TREE SHIT

// display function to pass to BST traverse functions
void display(Scrapper & anItem)
{
    cout  << anItem << endl;
}

// display2 print indented list
void display2(Scrapper & anItem, int&  num)
{
    for (int x=0; x<num+2; x++)
    {
        cout<<'\t';
    }
    
    cout << num << ":" << anItem << endl;
    
}

// check is used to check if value is found in tree
void check(bool success)
{
    if (success)
        cout << "found." << endl;
    else
        cout << " Entry not in tree." << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////


void menu(HASH*);

void menu_tree(BinarySearchTree<Scrapper> *tree1Ptr);


int main()
{
   
    BinarySearchTree<Scrapper>* tree1Ptr= new BinarySearchTree<Scrapper>;
    HASH* hash = new HASH(10);
   
    readinfile(hash,tree1Ptr);
    
    menu(hash);
    menu_tree(tree1Ptr);
    
    delete tree1Ptr;
    delete hash;
    
    return 0;
}

void readinfile(HASH* hash,BinarySearchTree<Scrapper> *tree1Ptr)
{
    ifstream infile;
    infile.open("tower.txt");
    if(!infile)
    {
        cout << "No such file exists." << endl;
        
    }
    string temp;
    string na;
    int flo = 0;
    int yea = 0;
    int ft = 0;
    int m = 0;
    string cit;
    string coun;
    string coor;
    
    while(!infile.eof())
    {
        getline(infile, temp);
        
        seperatedata(temp, na, flo, yea, ft, m, cit, coun, coor);
        Scrapper data(na, ft, m, coun, flo, cit, yea, coor);
        hash->add(data);
        tree1Ptr->insert(data);
    }
 
    
    infile.close();
    
}

void seperatedata(string& temp, string& na, int& flo, int& yea, int& ft,
                  int& m, string& cit, string& coun, string& coor)
{
    int i = 0;
    string floor;
    
    na = temp.substr(0, temp.find(';')); // na = name
    
    i = i + na.length() + 1;
    cit = temp.substr(i, temp.find(';', i) - i); // cit = city
    
    i = i + cit.length() + 1;
    coun = temp.substr(i, temp.find(';', i) - i); // coun = country
    
    i = i + coun.length() + 1;
    m = atoi(temp.substr(i, temp.find(';', i) - i).c_str()); // height in meters
    
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    ft = atoi(temp.substr(i, temp.find(';', i) - i).c_str()); // height in feet
    
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    flo = atoi(temp.substr(i, temp.find(';', i) - i).c_str()); // # of floors
    
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    yea = atoi(temp.substr(i, temp.find(';', i) - i).c_str()); // years
    
    i = i + temp.substr(i, temp.find(';', i) - i).length() + 1;
    coor = temp.substr(i, temp.length() - i - 1); // coordinates
    
}




/*******
 menu display the menu.
 let the user select from the menu.
 *******/
void menu(HASH*hash)
{
    
    cout << " Hash-Table made COOL"<<endl;
    cout<< "'S' Display content of the hash tabl"<<endl;
    cout<< "'D' Display content of the hash tabl"<<endl;
    cout<< "'P' Print the hash tabl"<<endl;
    cout<< "'T' Show the statistics "<<endl;
    cout<< "'M' Show Menu"<<endl;
    cout<< "'Q' Quit"<<endl;
    char choice;
    
    int userHeight=0;
    
    do
    {
        cout << "enter choice: ";
        cin>>choice;
        
        
        if(toupper(choice)=='S')
        {
            string name;
            cout << "what are you looking for"<<endl;
            cin.ignore();
            getline(cin,name);
            
            Scrapper max=hash->search(name);
            
            if (max.empty())
            {
                cout << "not found"<< endl;
                cin.ignore();
                
            }
            else
            {
                cout << "How tall are you in feet?"<<endl;
                cin >> userHeight;
                cout << "found: ";
                cout << max << endl;
                
                cout <<"It would take " << max.getheightft()/userHeight << " of you stacked from head to feet to be as tall as this tower"<<endl;
            }
        } // end if
        
        if(toupper(choice)=='D')
        {
            hash->print();
        }
        
        if(toupper(choice)=='P')
        {
            hash->print_two();
        }
        
        if(toupper(choice)=='T')
        {
            double load = hash->return_load();
            double hashsize = hash->return_hashsize();
            double collision = hash->return_collisions();
        
            cout << "there are " << hash->return_collisions() << " total collisions"<<endl;
            cout << "load factor %" << 100*(load/hashsize)<<endl;
            cout << "there are " << hash->return_buc_two() << " full buckets "<<endl;
            cout << "there are " << hash->empty_buckets() << " empty buckets " << endl;
            cout << "average number of nudes per bucket " << (collision/load) << endl;
            
            
        }
        
        if(toupper(choice)=='M')
        {
            cout << " Hash-Table made COOL"<<endl;
            cout<< "'S' Display content of the hash tabl"<<endl;
            cout<< "'D' Display content of the hash tabl"<<endl;
            cout<< "'P' Print the hash tabl"<<endl;
            cout<< "'T' Show the statistics "<<endl;
            cout<< "'M' Show Menu"<<endl;
            cout<< "'Q' Quit"<<endl;
        }
        
    }while(toupper(choice) !='Q');
    
}


void menu_tree(BinarySearchTree<Scrapper> *tree1Ptr)
{
    char choice;
    cout << "BST MENU"<< endl;
    cout << "B: print tree by Breadth-First Traversal  " << endl;
    cout << "D: print tree by Depth-First Traversal. (all 3 ways) " << endl;
    cout << "I: print indented list " << endl;
    cout << "S: Search tree by Unique Key " << endl;
    cout << "R: Print range Tree in the Tree " << endl;
    cout << "H: Help " << endl;
    cout << "Q: Quit " << endl;
    
    do
    {
        cout<< "enter choice";
        cin>>choice;
        cin.ignore();
        
        
        if (toupper(choice)=='B' )
        {
            cout << "breadth" << endl;
            tree1Ptr->tree_breadth(display);
        }
        else if (toupper(choice)=='D' )
        {
            cout << "Inorder" << endl;
            tree1Ptr->inOrder(display);
            
            cout << "postOrder" << endl;
            tree1Ptr->postOrder(display);
            
            cout << "preOrder" << endl;
            tree1Ptr->preOrder(display);
        }
        else if (toupper(choice)=='I' )
        {
            cout << "indented" << endl;
            tree1Ptr->print_indented(display2);
        }
        else if (toupper(choice)=='R' )
        {
            int min;
            int max;
            cout << "Choice the range to print" << endl;
            
            cout<< "Enter the minimum number " << endl;
            cin>>min;
            cin.clear();
            Scrapper low;
            low.setheight(min);
            
            cout<< "Enter the maximum number " << endl;
            cin>>max;
            cin.clear();
            Scrapper high;
            high.setheight(max);
            
            tree1Ptr->range(display, low, high);
        }
        else if (toupper(choice)=='H')
        {
            cout << "select a letter to start."<< endl;
            cout << "B: print tree by Breadth-First Traversal  " << endl;
            cout << "D: print tree by Depth-First Traversal. (all 3 ways) " << endl;
            cout << "I: print indented list " << endl;
            cout << "S: Search tree by Secondary Key " << endl;
            cout << "R: Print range Tree in a given Tree " << endl;
            cout << "H: Help to show the menu " << endl;
            cout << "Q: Quit " << endl;
        }
        else if (toupper(choice)=='A')
        {
            cout << "PikaPikaPikachu"<<endl;
        }
        else if (toupper(choice)=='S')
        {
            int height;
            cout << "Search for a height"<< endl;
            cin>> height;
            
            cin.ignore();
            Scrapper search;
            search.setheight(height);
            Scrapper result;
            if(tree1Ptr->getEntry(search, result))
                cout <<result<<endl;
            else
                cout <<"No building found with that height"<<endl;
        }
        
    }while(toupper(choice) !='Q');
    cout << "PEACE OUT" <<endl;
    
    
    
}

