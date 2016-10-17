//File: LinkedSortedList
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#ifndef LINKEDSORTEDLIST
#define LINKEDSORTEDLIST

template<class Elm>
LinkedSortedList<Elm>::~LinkedSortedList(){
  LinkedNode<Elm> *forward = head;
  while(head != NULL){
    forward = forward -> next;
    delete head;
    head = forward;
  }
}

template<class Elm>
bool LinkedSortedList<Elm>::insert(Elm newvalue){
  if(sizeList == 0){ //CASE: empty list
    head = new LinkedNode<Elm>(newvalue);
    sizeList++;
    return true;
  }
  else if(newvalue < head -> value){ //CASE: new value goes in front
    LinkedNode<Elm> *tmp = new LinkedNode<Elm>(newvalue, head);
    head = tmp;
    sizeList++;
    return true;
  }
  else{
    LinkedNode<Elm> *current = head;
    LinkedNode<Elm> *forward = head -> next;
    while (forward != NULL){ //CASE: new value is greater than first element
      if(newvalue <= forward -> value){
	current -> next = new LinkedNode<Elm>(newvalue, forward);
	sizeList++;
	return true;
      }
      current = forward;
      forward = forward -> next;
    }
    forward = new LinkedNode<Elm>(newvalue); //CASE: new value is the largest element
    current -> next = forward;
    sizeList++;
    return true;
  }

  return false;
}

template<class Elm>
void LinkedSortedList<Elm>::print() const{
  int count = 1;
  cout << "[ ";
  for(LinkedNode<Elm> *it=head;it != NULL;it=it->next){
    if(count++ % 10 == 0){cout << endl;}
    it -> print();
    cout << " ";
  }
  cout << " ] " << endl;
}

template<class Elm>
bool LinkedSortedList<Elm>::getfirst(Elm &returnvalue){
  if(head == NULL){return false;}
  LinkedNode<Elm>* tmp;
  tmp = head;
  head = head -> next;
  sizeList--;
  returnvalue = tmp -> value;
  delete tmp;
  return true;
}

template<class Elm>
bool LinkedSortedList<Elm>::find(Elm searchvalue) const{
  LinkedNode<Elm> *it;
  for(LinkedNode<Elm> *it=head;it != NULL;it=it->next)
    if(it -> value == searchvalue){return true;}
  return false;
}

#endif //LINKEDSORTEDLIST
