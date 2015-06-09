// Team 2
#include <iostream>

using namespace std;
void menu()
{
    cout <<"Menu"<<endl
        <<"H - Hash" <<endl
        <<"B - BST" <<endl
        <<"Q - Quit"<<endl;
}
void menuBST()
{
    cout <<"BST Menu:"<<endl
        <<"1 - Display sorted by Primary Key(name)"<<endl
        <<"2 - Display sorted by Secondary Key(height)"<<endl
        <<"R - Remove object"<<endl
        <<"S - Search"<<endl
        <<"Q - Quit"<<endl;
}
void menuHash()
{
    cout <<"Hash Menu:"<<endl
    <<"D - Displays all items"<<endl
    <<"P - Prints an indented list of the hash table"<<endl
    <<"R - Remove object"<<endl
    <<"S - Search"<<endl
    <<"Q - Quit"<<endl;
}
/*
void print(hash * hash1)
{
    int hashSize = hash1->getHashSize();
 
    for(int i=0; i < hashSize; i++)
    {
        cout <<hash1[i] // if this is a linked list will have to write another loop to access
    }
 
}
*/
int main()
{
    char choice;
    menu();
    
    // bst object bst1; // sorted by primary key
    // bst object bst2; // sorted by secondary key
    // hash object hash1;
    // hash object * hashPtr = hash1;
    // skyscraper ss1;
    do
    {
        cin >> choice;
        if (toupper(choice) == 'H')
        {
            menuHash();
            do
            {
                cin>>choice;
                if (toupper(choice) == 'D')
                {
                    //hash1.display(); // could write a function in main to display all the shit
                    // display(hash1);
                
                }
                else if (toupper(choice) == 'P')
                {
                    //print(hash1); // will write a function in main to print all the shit
                
                }
                else if (toupper(choice) == 'R')
                {
                    //hash1.remove(x) // x could be a hash key or a string to be ocnverted into a hash
                                      // by another hash member function
                }
                else if (toupper(choice) == 'S')
                {
                    //hash1.search(x) // once again x could be string or int
                }
    
            }while(toupper(choice) != 'Q');
        
        }// end Hash menu
        
        
        else if(toupper(choice) == 'B')
        {
            menuBST();
            do
            {
                cin >>choice;
                if (choice == '1')
                {
                    // bst1.display() // Should only display Names per line
                }
                else if (choice == '2')
                {
                    // bst2.display()
                }
                else if (toupper(choice) == 'R')
                {
                    // bst1.remove(x);
                }
                else if (toupper(choice) == 'S')
                {
                    
                    // ss1= bst1.search(x); // return obj
                    // cout<<ss1;
                    
                    // bst2.search(x);
                }
            }while(toupper(choice) != 'Q');
        } // end BST Menu
            
    }while (toupper(choice) != 'Q');

    


    return 0;
}
