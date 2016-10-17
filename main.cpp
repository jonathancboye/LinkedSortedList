//File: main.cpp
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <iomanip>
#include "LinkedSortedList.h"
#include "SortedList.h"
using namespace std;

// Insert new Entry: prompt user for a new value, insert it into the Linked List. 
template<class Elm>
void insertEntry(SortedList<Elm> &l);

//Delete the first element in the linked list.  Display information telling whether or not the deletion is successful
template<class Elm>
void deleteEntry(SortedList<Elm> &l);

//Search for a specific value given via the keyboard in the linked list. Display
//information telling whether or not the search is successful.
template<class Elm>
void searchEntry(SortedList<Elm> &l);

//Clear the list
template<class Elm>
void clearList(SortedList<Elm> &l);


int main(){
  string input;
  int choice;
  LinkedSortedList<int> integerList;
  LinkedSortedList<double> doubleList;
  enum Menu{MAIN_MENU, INTEGER_MENU, DOUBLE_MENU};
 
  Menu menu = MAIN_MENU;

  while(true){
    while(menu == MAIN_MENU){
      cout << "####################" << endl;
      cout << "#    MAIN MENU     #" << endl;
      cout << "####################" << endl;
      cout << "Create a Linked List of type:" << endl;
      cout << "1) Integer" << endl;
      cout << "2) Double" << endl;
      cout << "3) quit " << endl;
      cout << "Select a option: ";
      getline(cin,input);
      choice = atoi(input.c_str());

      switch(choice){
      case 1:
	menu = INTEGER_MENU;
	break;
      case 2:
	menu = DOUBLE_MENU;
	break;
      case 3:
	return EXIT_SUCCESS;
      default:
	cout << "Please enter in a valid choice" << endl;
      }
      cout << endl;
    }

    while(menu == INTEGER_MENU || menu == DOUBLE_MENU){
      string title = (menu == INTEGER_MENU) ? "INTEGER" : "DOUBLE";
      cout << "####################" << endl;
      cout << "#   " << title  << " "
	   << "Menu" <<"  #" << endl;
      cout << "####################" << endl;
      cout << "1) Insert Entry" << endl;
      cout << "2) Delete Entry" << endl;
      cout << "3) Search Entry" << endl;
      cout << "4) Print List" << endl;
      cout << "5) Clear the list" << endl;
      cout << "6) Return to Main Menu" << endl;
      cout << "Select a option: ";

      getline(cin, input);
      choice = atoi(input.c_str());
      
      switch(choice){
      case 1:
	if(title == "INTEGER") 
	  insertEntry(integerList);
	else 
	  insertEntry(doubleList);
	break;
      case 2:
	if(title == "INTEGER")
	  deleteEntry(integerList);	  
	else
	  deleteEntry(doubleList);
	break;
      case 3:
	if(title == "INTEGER")
	  searchEntry(integerList);
	else
	  searchEntry(doubleList);
	break;
      case 4:                     //Print list
	if(title == "INTEGER")
	  integerList.print();
	else
	  doubleList.print();
	break;
      case 5:
	if(title == "INTEGER")   //Clear list
	  integerList.clear();
	else
	  doubleList.clear();
	cout << "List cleared" << endl;
	break;
      case 6:
	menu = MAIN_MENU;
	break;
       default:
	cout << "Please pick a valid choice" << endl;
      } 
      cout << endl;
    }
  }
}

template<class Elm>
void insertEntry(SortedList<Elm> &l){
  Elm value;
  cout << "Enter in a value to be inserted into the list: ";
  cin >> value;
  cin.ignore(1,'\n');
  l.insert(value);
}
    
template<class Elm>
void deleteEntry(SortedList<Elm> &l){
  Elm value;
  if(l.getfirst(value))
    cout << value << " removed successfully";
  else
    cout << "List is empty, nothing to remove";
  cout << endl;
}

template<class Elm>
void searchEntry(SortedList<Elm> &l){
  Elm value;
  cout << "Enter a value to search for in the List: ";
  cin >> value;
  cin.ignore(1,'\n');
  if(l.find(value))
    cout << "Found it!";
  else
    cout << "Could not find it!";
  cout << endl;
}
    

