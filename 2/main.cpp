#include"assign2.h"
#include<iostream>
using namespace std;
int main(){
  SortedBag<int> test;
  test.add(2);
  cout<<test.First->next<<endl;
  test.add(3);
  cout<<test.First->next<<endl;

  test.add(9);
  cout<<test.First->next<<endl;

  int item =5;
  test.add(item);
   cout<<test.First->next<<endl;
  test.add(6);
 cout<<test.inBag(6)<<endl;
  test.add(6);
 cout<<test.First->next<<endl;

  test.add(7);
 cout<<test.First->next<<endl;
 cout<<test.First->next->funStuff<<endl;
   cout<<test.inBag(6)<<endl;
   cout<<test.First->count<<endl;
   cout<<test.size<<endl;

   cout<<test.First->count<<endl;
   cout<<test.size<<endl;
   cout<<test.First->funStuff<<endl;
  //

  test.PrintBag();

  return 0;
}
