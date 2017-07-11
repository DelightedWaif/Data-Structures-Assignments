#include"Map.h"
#include"BSTMap.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
  /*****Testing individual methods***

  BSTMap<string, int> test;
  // cout<<test.isEmpty()<<endl;
  cout<<test.insert("Jeremy", 17)<<endl;

  cout<<test.insert("Tim", 19)<<endl;
  // cout<<test.isEmpty()<<endl;
  // test.print();
  // cout<<test.isEmpty()<<endl;
  test.print();
  cout<<test.insert("John", 31)<<endl;
  test.print();
  cout<<test.findnremove("Tim")<<endl;
  // cout<<test.isEmpty()<<endl;
  test.print();
  cout<<*test.search("John")<<endl;

  // cout<<*test.search("Jeremy")<<endl;
  */
  //Proper part of main
  ifstream f;
  f.open("Q1.dat");
  string stringFile[10];
  string intFile[10];
  int intfile[10];
  for(int i=0; i<10;i++){ //for loop sets up arrays for easy use
    getline(f,stringFile[i],' '); //reads strings from
    getline(f,intFile[i],'\n');//reads ints from file
    intfile[i] = stoi(intFile[i]);//converts string to ints
  }

  BSTMap<string,int> stringKey;//creates maps
  BSTMap<int,string> intKey;
  for(int i=0; i<10;i++){ //for loop to insert values to the maps
    stringKey.insert(stringFile[i], intfile[i]);
    intKey.insert(intfile[i],stringFile[i]);
  }
  stringKey.print();//prints map
  intKey.print();//prints map
if(stringKey.search("file")==nullptr){//searches for value not in map
  cout<<"null"<<endl;//should print null
}
if(intKey.search(19248)==nullptr){//searches for value not in map
  cout<<"null"<<endl;//should print null
}

  cout<<"searching Coffee "<<*stringKey.search("Coffee")<<endl;//searching for value in map should print
  cout<<"Searching 1234567 "<<*intKey.search(1234567)<<endl;
  cout<<"searching Coffee in a search for 1234567 "<<*intKey.search(*stringKey.search("Coffee"))<<endl;//should print coffee
  cout<<"Deleting 1234567 "<<intKey.findnremove(1234567)<<endl ;//removing 1234567
  intKey.print();//removed 1234567  print
  cout<<"Deleting Coffee "<<stringKey.findnremove("Coffee")<<endl; //removing Coffee
  stringKey.print();//prints removed value
  f.close();
  return 0;
}
