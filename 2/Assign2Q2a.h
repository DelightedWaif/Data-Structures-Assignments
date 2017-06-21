#include<iostream>
//Pure virtual abstract base class representing a minimal queue
class Queue
{
public:
// c'tor and d'tor
Queue() { }
virtual ~Queue() {
  first = nullptr;
  last = nullptr;
  next = nullptr;
  delete next;
  delete last;
  delete first;
 }
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
    LLQueue* first = nullptr;
    LLQueue* last = nullptr;
    LLQueue* next = nullptr;
    int value;
};

void LLQueue::enqueue(int e){
  LLQueue* newLLQueue = new LLQueue;
  newLLQueue->value = e;
  if(first==nullptr){
    first = newLLQueue;
    last = newLLQueue->next;
  }
  else{
    last->next = newLLQueue;

  }
  last = newLLQueue;
}

int  LLQueue::dequeue(){
    LLQueue* newLLQueue = new LLQueue;

    int i = first->value;

    newLLQueue = first;

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

  LLQueue* Before = new LLQueue;
  LLQueue* After = new LLQueue;
  Before = first;
   while(Before->next!=nullptr){
     std::cout<< Before->value<<std::endl;
     After = Before;
     Before = Before->next;
   }
   if(Before->next==nullptr){
     std::cout<<Before->value<<std::endl;
   }

}
