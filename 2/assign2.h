#include"Node.h"
template<class T>
class SortedBag;

template<class T>
class SortedBag{

  public:
      SortedBag();
      ~SortedBag();
      void add(const T item);
      void remove(const T item);
      bool inBag(const T item);
      void PrintBag();
      void createNode(const T item);
      node<T>* First=nullptr;
      node<T>* Last=nullptr;
      int size=0;

};

template<class T>
SortedBag<T>::SortedBag(){
}
template<class T>
SortedBag<T>::~SortedBag(){
}
template<class T>
void SortedBag<T>::add(const T item){
    if(size==0){
      createNode(item);
    }
    else if(inBag(item)){
      node<T> *Before=new node<T>;
      node<T> *After=new node<T>;
      Before = First;
      while(Before.funStuff > item and After.funStuff < item){
          After = Before;
          Before = Before->next;
          if(item == Before.funStuff){
            Before.count++;
            return;
          }

      }

    }
    else{
      node<T> *Before=new node<T>;
      node<T> *After=new node<T>;
      node<T> *newNode = new node<T>;
      Before = First;
      while(Before.funStuff > item and After.funStuff < item){
          After = Before;
          Before = Before->next;
          newNode->funStuff = item;
          newNode->next =  Before->next;
          Before->next = newNode;
      }
    }
}

template<class T>
void SortedBag<T>::remove(const T item){
    if(size==0 or !inBag(item)){
      return;
    }
    else{
      node<T> *Before=new node<T>;
      node<T> *After=new node<T>;
      Before = First;
      while(Before.funStuff > item and After.funStuff < item){
        After = Before;
        Before = Before->next;
      }
      if(item == Before.funStuff and Before.count > 0){
        Before.count--;
        return;
      }
      else{
        Before->next = After->next;
        After-> next = nullptr;
      }
      delete Before;
      delete After;
    }

}

template<class T>
bool SortedBag<T>::inBag(const T item){
  node<T> *Before=new node<T>;
  node<T> *After=new node<T>;
  Before = First;
  while(Before->next != nullptr){
    if(Before.funStuff == item){
      return true;
    }
    After = Before;
    Before = Before->next;
  }
  delete Before;
  delete After;
  return false;
}

template<class T>
void SortedBag<T>::PrintBag(){

}

template<class T>
void SortedBag<T>::createNode(const T item){
  node<T> *newNode = new node<T>;
  newNode->funStuff = item;
  size++;
  newNode->next = nullptr;
  First = &newNode;
}
