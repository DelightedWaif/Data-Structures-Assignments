#include"assign23.h"
#include<iostream>
using namespace std;

int main(){
  QueueStack test;
  // cout<<test.isEmpty()<<endl;
  test.push(4);
  // test.print();
  test.push(5);
  // test.print();
  test.push(2);
  // test.print();
  test.push(1);
  // test.print();
  test.push(3);
  test.print();
  // cout<<test.isEmpty()<<endl;
  test.pop();
  // test.print();
  test.pop();
  test.print();
  // test.pop();
  // test.print();
  // test.pop();
  // test.print();
  // test.pop();
  // test.print();
  // cout<<test.isEmpty()<<endl;
  return 0;
}
