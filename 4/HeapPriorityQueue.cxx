#include"PriorityQueue.hxx"
#include"HeapPriorityQueue.hxx"
#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream f;
  f.open("tickets.txt");
  string numb[5];
  string ticket[5];
  int num[5];
  HeapPriorityQueue<int,string> queue;
  for(int i=0; i<5;i++){  //reads from file and stores them in arrays
    getline(f,numb[i], ' ');
    getline(f,ticket[i],'\n');
    num[i]=stoi(numb[i]);
  }
  for(int i=0; i<5; i++){
    queue.enqueue(num[i], ticket[i]); //tests enqueue
    queue.print();  //prints queue
  }
  for(int i=0; i<5;i++){
    cout<<"Value from dequeue:"<<queue.dequeue()<<endl; //tests dequeue
    queue.print();  //prints queue
  }
  return 0;
}


// Adds the key/value pair to the internal heap
template<class K, class V>
void HeapPriorityQueue<K,V>::enqueue(const K& key, const V& value) {
    PQEntry newthing= PQEntry(key,value); //creates new entry
    heap.push_back(newthing); //adds entry to heap
    trickleUp(heap.size()-1); //sorts heap
}

// Removes the best key from the heap and returns associated value
template<class K, class V>
V HeapPriorityQueue<K,V>::dequeue() {
  V thingy = heap[heap.size()-1].value; //stores last value
  heap.pop_back();  //dequeues the value
  return thingy;  //returns stored value
}

// Test for empty
template<class K, class V>
bool HeapPriorityQueue<K,V>::isEmpty() const {
  if(heap.empty()){ //checks if heap is empty
    return true;
  }
  return false;
}

// Prints contents of queue (key/value pairs) using level-order traversal
template<class K, class V>
void HeapPriorityQueue<K,V>::print() const {
  for(int i=0; i<heap.size();i++){
    cout<<"Position: "<<i<<endl<<"Key: "<<heap[i].key<<"\t"<<"Value: "<<heap[i].value<<endl;  //prints queue
  }
}

// Auxiliary methods to re-heapify the heap
template<class K, class V>
void HeapPriorityQueue<K,V>::trickleUp(int idx){
  int parent = (idx-1)/2; //sets parent loation
  if(idx >= 0 and heap[idx].key > heap[parent].key){
    PQEntry temp = PQEntry(heap[idx].key, heap[idx].value); //creates temp entry
    heap[idx]=heap[parent]; //swaps the parent and child
    heap[parent] = temp;
    trickleUp(parent); //recursively repeats process
  }
}
template<class K, class V>
void HeapPriorityQueue<K,V>::trickleDown(int idx){
  int Lchild = 2*idx+1;
  int Rchild = 2*idx+2;//initializes children locations
  if(idx>=0 and heap[idx].key < heap[Lchild].key){
    PQEntry temp = PQEntry(heap[idx].key, heap[idx].value);
    heap[idx]=heap[Lchild];
    heap[Lchild] = temp;  //swaps left
    trickleDown(Lchild);//recursively repeats process  left
  }
  if(idx>=0 and heap[idx].key < heap[Rchild].key){
    PQEntry temp = PQEntry(heap[idx].key, heap[idx].value);
    heap[idx]=heap[Rchild];
    heap[Rchild] = temp;//swaps right
    trickleDown(Rchild);//recursively repeats process right
  }
}
