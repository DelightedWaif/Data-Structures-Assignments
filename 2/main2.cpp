#include"Assign2Q2.h"
#include<iostream>
using namespace std;
int main(){
  LLQueue test;
  cout<<"empty"<<test.isEmpty()<<endl;  //should be 1
  test.enqueue(3);  // adding 3
  cout<<"!empty"<<test.isEmpty()<<endl; //should be 0
  test.enqueue(5);  // adding 5
  test.print();   //printing queue
  test.dequeue(); //removing 3
  test.print(); //printing queue
  test.dequeue(); //removing 5
  test.print(); //printing queue (should not print since queue is empty)
  return 0;
}
