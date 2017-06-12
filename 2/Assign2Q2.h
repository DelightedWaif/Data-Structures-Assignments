#include<iostream>
//Pure virtual abstract base class representing a minimal queue
class Queue
{
public:
// c'tor and d'tor
Queue() { }
virtual~Queue() { }
// pre-condition:  given an integer 'e'
// post-condition: the queue will contain 'e' at one end of the data structure
virtual void enqueue(int e) = 0;
// pre-condition:  queue must not be empty
// post-condition: the integer at the other end of the data structure is returned,
// and also removed from the structure
virtual int dequeue() = 0;
virtual bool isEmpty() const = 0;
virtual void print() const = 0;
};

class node{
  public:
    node* next=nullptr;
    int value;
};

class LLQueue : public Queue{

  public:
    // pre-condition:  given an integer 'e'
    // post-condition: the queue will contain 'e' at one end of the data structure
    void enqueue(int e);
    // pre-condition:  queue must not be empty
    // post-condition: the integer at the other end of the data structure is returned,
    // and also removed from the structure
    int dequeue() ;
    bool isEmpty() const ;
    void print() const;
    node* first = nullptr;
    node* last= nullptr;
};

void LLQueue::enqueue(int e){
  node* newNode = new node;
  newNode->value = e;
  if(first==nullptr){
    first = newNode;
    last = newNode->next;
  }
  else{
    last->next = newNode;

  }
  last = newNode;
}

int  LLQueue::dequeue(){
    node* newNode = new node;

    int i = first->value;

    newNode = first;

    first = first->next;

    return i;
}
bool  LLQueue::isEmpty() const {
    if(first == nullptr){
      return true;
    }
    return false;
}

void  LLQueue::print() const{
  if(first == nullptr){
    return;
  }

  node* Before = new node;
  node* After = new node;
  Before = first;
   while(Before->next!=nullptr){
     std::cout<< Before->value<<std::endl;
     After = Before;
     Before= Before->next;
   }
   if(Before->next==nullptr){
     std::cout<<Before->value<<std::endl;
   }

}
