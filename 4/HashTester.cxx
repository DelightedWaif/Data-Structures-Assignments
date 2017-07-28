#include "HashWithChaining.hxx"
#include "HashWithQuadratic.hxx"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int ac, char* av[])
{
  // Key is an integer for student ID
  // Value is a string representing the students' entire name

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 13579
  // FIXME
  std::function<int(int)> concatEven = [](int a) {
    string name = to_string(a);   //converts to string
    for(int i=1; i<name.length() and name.length()!=5; i++){//eliminates oddn values
        name.erase(i,1);
    }
    return stoi(name);  //converts to int
  };

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 2468
  // FIXME
  std::function<int(int)> concatOdd = [](int a) {
    string name = to_string(a); //converts to string
    for(int i = 0; i < name.length() and name.length()!=4; i++){
        name.erase(i,1);    //erases even values
      }
    // cout<<stoi(name)<<endl;
    return stoi(name);  //converts to int
  };

  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
  ifstream f;
  f.open("students.txt");
  string value[101];
  string tempkey[101];  //sets up reading from .txt file
  int key[101];
  for(int i=0; i<100;i++){  //reads from file and stores it in arrays
    getline(f, tempkey[i],' ');
    getline(f, value[i],'\n');
    cout<<i<<"   "<<tempkey[i]<<endl;
    key[i] = stoi(tempkey[i]);
  }

  for(int i =0; i<100;i++){ //inserts values in hash tables
    h1.insert(key[i],value[i]);
    h2.insert(key[i],value[i]);
    h3.insert(key[i],value[i]);
    h4.insert(key[i],value[i]);
  }

  cout<<"Finding Tia1:"<<*h1.find(201103221)<<endl; //tests find
  cout<<"Finding Tia2:"<<*h2.find(201103221)<<endl;
  cout<<"Finding Tia3:"<<*h3.find(201103221)<<endl;
  cout<<"Finding Tia4:"<<*h4.find(201103221)<<endl;
  cout<<"Printing h1:"<<endl;
  h1.print(); //tests print
  cout<<"Printing h2:"<<endl;
  h2.print();//tests print
  cout<<"Printing h3:"<<endl;
  h3.print();//test print
  cout<<"Printing h4:"<<endl;
  h4.print();
  cout<<"keys examined h1: ";
  cout<<h1.totalKeysExamined()<<endl; //keys examined should be around 100
  cout<<"keys examined h2: ";
  cout<<h2.totalKeysExamined()<<endl;//keys examined sould be around 150
  cout<<"keys examined h3: ";
  cout<<h3.totalKeysExamined()<<endl;//keys examined should be around 100
  cout<<"keys examined h4: ";
  cout<<h4.totalKeysExamined()<<endl;//keys examined sould be around 150



}
