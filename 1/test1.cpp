#include<iostream>
#include<fstream>
#include"assign1.h"
using namespace std;

int main(){
  ifstream f;
  f.open("data.dat");
  int columnSize;
  f >> columnSize;
  array test[columnSize];
  for(int i=0; i<columnSize; i++){
    int size;
    f >> size;

    int* array = new int[size];
    for(int j=0; j < size; j++){
      test[i].size=size;
      f >> array[j];
    }
    test[i].array1=array;
    test[i].min = minimum(test[i].array1, test[i].size);
    test[i].max = maximum(test[i].array1, test[i].size);
    test[i].avg = average(test[i].array1, test[i].size);
  }
  for(int i=0; i<columnSize; i++){
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
    // delete [] test[i].array1;
    // test[i].array1 = nullptr;
  }
  f.close();
  return 0;
}
