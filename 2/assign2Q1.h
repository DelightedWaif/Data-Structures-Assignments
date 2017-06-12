#include"Node.h"
#include<iostream>
template<class T>
class SortedBag;

template<class T>
class SortedBag{

  public:
      SortedBag();  //constructor
      ~SortedBag(); //destructor
      void add(const T item); //adds elements
      void remove(const T item);  //removes elements
      void removeAll(const T item); //removes all of one kind of element
      int sizeOfBag();  //gets size of bag/number of unique elements
      bool isEmpty(); //checks if the bag is empty
      int numOfType(const T item);  //gets the number of one type
      bool inBag(const T item); //checks if a number is in the bag
      void PrintBag();  //prints the bag followed by the count eg element:count
      void sort();  //sorts the bag
      node<T>* First=nullptr; //pointer to the first element
      node<T>* Last=nullptr;  //pointer to the last element
      int size=0; //holds the size of the bag

};
template<class T>
void SortedBag<T>::sort(){  //O(n^2)  Two loops based off of each other
  node<T> *Before=new node<T>;  //node used to loop
  node<T> *After=new node<T>;//node used to loop
  node<T> *temp=new node<T>;//node used to swap the appropreate values

  Before = First;

  while(Before!=nullptr){ //nested while loop to swap values if necessary
    After = Before->next;
    while(After!=nullptr){
        if(After->funStuff<Before->funStuff){
          if(After->count!=Before->count){
            temp->count = After->count;
            After->count = Before-> count;
            Before->count = temp->count;
          }
          temp->funStuff= After->funStuff;
          After->funStuff = Before->funStuff;
          Before->funStuff=temp->funStuff;
        }
        After = After->next;
    }
    Before=Before->next;
  }
}
template<class T>
int SortedBag<T>::numOfType(const T item){  //O(n)  Only one loop, based only on how many elements
  node<T> *Before=new node<T>;
  node<T> *After=new node<T>;
  Before = First;
  while(Before->next!=nullptr){ //loop to check if items match
    if(Before->funStuff==item){
      return Before->count;
    }
    After = Before;
    Before = Before->next;
  }
}

template<class T>
bool SortedBag<T>::isEmpty(){//0(1) Same no matter how many elements
  if(this->size!=0){
    return false;
  }
  return true;  //returns true if empty
}

template<class T>
int SortedBag<T>::sizeOfBag(){//O(1)  Same no matter how many elements
  return size;  //size of bag
}
template<class T>
SortedBag<T>::SortedBag(){//O(1)  Same no matter how many elements
}
template<class T>
SortedBag<T>::~SortedBag(){//O(1) Same no matter how many elements
}

template<class T>
void SortedBag<T>::add(const T item){//O(n^2) Calling the sort function at the end causes this function to go from O(n) to O(n^2)
    node<T> *newNode = new node<T>;
    newNode->funStuff = item;
    newNode->count++;
    newNode->next = nullptr;

    if(First==nullptr){ //adds first element
      First=newNode;
      Last=newNode;
      size++;
    }
    else{
      if(inBag(item)){  //checks if item is already in bag and increments count rather than adding a new node
        node<T> *Before=new node<T>;
        node<T> *After=new node<T>;
        Before = First;
        while(Before->next!=nullptr){
          if(Before->funStuff==item){
            Before->count++;
          }
            After = Before;
            Before = Before->next;

        }
        if(Before->funStuff==item){
          Before->count++;
        }
        delete newNode;
        size++;
      }
      else{ //creates new node at the end
        Last->next=newNode;
        Last = newNode;
      }
        size++;//increases the size

    }
    this->sort(); //sorts the list
}

template<class T>
void SortedBag<T>::remove(const T item){//O(n) Only one loop will cause this function to be based solely on the number of elements
    if(this->size==0 and !inBag(item)){ //checks if there are any values in the bag
      return;
    }
    node<T> *Before=new node<T>;
    node<T> *After=new node<T>;
    Before = First;
    while(Before->next!=nullptr and Before->funStuff!=item){
        After = Before;
        Before = Before->next;
    }
    if(Before->funStuff == item and Before == First){
      First = Before->next;
    }

    if(Before->funStuff==item){ //removes the correct item

        if(Before->count>1){
          Before->count--;
        }
        else{
          After->next = Before->next;

          delete Before;
        }

    }



    size--;
}

template<class T>
bool SortedBag<T>::inBag(const T item){ //O(n)Only one loop will cause this function to be based solely on the number of elements
    if(this->size==0 and !inBag(item)){
  node<T> *Before=new node<T>;
  node<T> *After=new node<T>;
  Before = First;
  while(Before->next != nullptr){ //checks to see if the item is in the bag
    if(Before->next->funStuff == item){
      return true;
    }
    After = Before;
    Before = Before->next;
  }
  if(Before->funStuff==item){ //returns true if it is in the bag
    return true;
  }

  return false;
}

template<class T>
void SortedBag<T>::PrintBag(){  //O(n) Only one loop will cause this function to be based solely on the number of elements
    if(this->size==0 and !inBag(item)){
  node<T> *Before=new node<T>;
  Before = First;
  while(Before->next != nullptr){
      std::cout<< Before->funStuff<< ":"<<Before->count<<std::endl; //prints out the bag
      Before = Before->next;

  }
std::cout<< Before->funStuff<< ":"<<Before->count<<std::endl;
}


template<class T>
void SortedBag<T>::removeAll(const T item){ //O(n) Only one loop will cause this function to be based solely on the number of elements
    if(this->size==0 and !inBag(item)){ //removes all values that are the same as item
  T numRem=0;
  if(this->size==0 and !inBag(item)){
    return;
  }
  node<T> *Before=new node<T>;
  node<T> *After=new node<T>;
  Before = First;
  while(Before->next!=nullptr and Before->funStuff!=item){
      After = Before;
      Before = Before->next;
  }
  if(Before->funStuff == item and Before ==First){
    First = Before->next;
  }
  if(Before->funStuff==item){
        numRem = Before->count;
        After->next = Before->next;
        delete Before;
  }
  size-=numRem;

}
