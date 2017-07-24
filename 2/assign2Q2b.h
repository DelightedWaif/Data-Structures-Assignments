#include<iostream>
#include"Assign2Q2a.h"

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

void QueueStack::push(int e){  //O(1) only perfoms one operation not dependant on number of elements

  bottom.enqueue(e);

}
int QueueStack::pop(){
  while(bottom.first->next!=nullptr){//O(n) changes based on how many elements in bottom
    top.enqueue(bottom.dequeue());
  }
  int i= bottom.dequeue();
  LLQueue temp; //Switches the names to avoid seg fault
  temp = top;
  top = bottom;
  bottom = temp;
  return i; //returns popped value
}
bool QueueStack::isEmpty() const{ //O(1) not dependant on elements
  if(bottom.isEmpty() and top.isEmpty()){
    return true;
  }
  return false;
}
void QueueStack::print() const{ //O(n) changes based on number of elements

    bottom.print();
  }
