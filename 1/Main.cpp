#include<iostream>
#include<fstream>
#include"assign1.h"
using namespace std;

int main(){
  ifstream f; // creates a file object
  f.open("data.dat"); //opens the data.dat file
  int columnSize;
  f >> columnSize;  //reads the first character in the file
  array test[columnSize]; //creates an array of 'array' structs
  for(int i=0; i<columnSize; i++){  //loop to fill the structs with information
    int size;
    f >> size;  //reads the first line of each row

    int* array = new int[size]; //creates a heap allocated array of ints using the appropreate size
    for(int j=0; j < size; j++){ //loop to fill the array with data
      test[i].size=size;
      f >> array[j];  // fills the array with data
    }
    test[i].array1=array; //Tells the pointer to point to the array
    test[i].min = minimum(test[i].array1, test[i].size);  //calculates minimum values
    test[i].max = maximum(test[i].array1, test[i].size);  //calculates maximum values
    test[i].avg = average(test[i].array1, test[i].size);  //calculates averages
  }
  for(int i=0; i<columnSize; i++){  //this loop is solely for printing out the values that are required
    cout<<"Contents:"<<endl;
    for(int j=0; j < test[i].size; j++){
      cout<<test[i].array1[j]<<endl;
    }
    cout<<"size:"<<endl;
    cout<< test[i].size<<endl;
    cout<<"min:"<<endl;
    cout<< test[i].min<<endl;
    cout<<"max:"<<endl;
    cout<< test[i].max<<endl;
    cout<<"average:"<<endl;
    cout<< test[i].avg<<endl;
  }
  for(int i=0; i<columnSize;i++){
    delete [] test[i].array1;   //deletes the heap allocated array
    test[i].array1 = nullptr;   //sets pointer to zero
  }
  f.close();    //closes the file 
  return 0;
}
