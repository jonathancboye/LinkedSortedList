//File: LinkedSortedList.h
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#ifndef LINKEDSORTEDLIST_H
#define LINKEDSORTEDLIST_H

#include "LinkedNode.h"
#include "SortedList.h"
#include <iostream>
using namespace std;

template <class Elm>
class LinkedSortedList : public SortedList<Elm>{
 public:
 
  //Default Constructor
 LinkedSortedList(): head(NULL), sizeList(0){}
 
  //Destructor
  ~LinkedSortedList();

  void clear(){this -> ~LinkedSortedList(); sizeList = 0;}

  // Insert a value into the list.  Return true if successful, false
  // if failure.
  virtual bool insert(Elm newvalue);

  // Print out the entire list to cout.  Print an appropriate message
  // if the list is empty.  Note:  the "const" keyword indicates that
  // this function cannot change the contents of the list.
  virtual void print() const;

  // Return the number of items in the list
  virtual int size() const{return sizeList;}

  // Get AND DELETE the first element of the list, placing it into the
  // return variable "value".  If the list is empty, return false, otherwise
  // return true.
  virtual bool getfirst(Elm &returnvalue);
  
  // Check to see if "value" is in the list.  If it is found in the list,
  // return true, otherwise return false.  Like print(), this function is
  // declared with the "const" keyword, and so cannot change the contents
  // of the list.
  virtual bool find(Elm searchvalue) const;

 private:
  
  LinkedNode<Elm>* head;
  int sizeList; //size of the list
};

#include "LinkedSortedList.cpp"  

#endif //LINKEDSORTEDLIST_H
