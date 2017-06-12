#include<iostream>
#include"Assign2Q2.h"

// Pure virtual abstract base class representing a minimal stack
class Stack
{
public:
// c'tor and d'tor
Stack() { }
virtual ~Stack() { }
// pre-condition: given an integer 'e'
// post-condition: the stack will contain 'e' at the top of the data structure
virtual void push(int e) = 0;
// pre-condition: stack must not be empty
// post-condition: the integer at the top of the data structure is returned,
//and also removed from the structure
virtual int pop() = 0;
virtual bool isEmpty() const = 0;
virtual void print() const = 0;
};

class QueueStack: public Stack{
  public:
    // pre-condition: given an integer 'e'
    // post-condition: the stack will contain 'e' at the top of the data structure
      void push(int e);
    // pre-condition: stack must not be empty
    // post-condition: the integer at the top of the data structure is returned,
    //and also removed from the structure
      int pop();
      bool isEmpty() const;
      void print() const;
      LLQueue top;
      LLQueue bottom;
};

void QueueStack::push(int e){

  bottom.enqueue(e);
  bottom.first = top.last;
  top.first = bottom.last;
}
int QueueStack::pop(){
  bottom.first = top.last;
  top.first = bottom.last;
  top.dequeue();
}
bool QueueStack::isEmpty() const{
  if(bottom.isEmpty() and top.isEmpty()){
    return true;
  }
  return false;
}
void QueueStack::print() const{
  if(bottom.first==nullptr){
  std::cout<< top.first<<std::endl;
    top.print();
  }
  else
    bottom.print();
}
