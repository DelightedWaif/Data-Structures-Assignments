#include"Map.h"
#include<iostream>
//Node class to hold the left and right pointers and values
template<class K, class V>
class BSTnode{
  public:
    BSTnode() {
      Left = Right = nullptr;
    }
    BSTnode(const K key, const V value){  //constructor initialises key and value
      Key=key;
      Value=value;
    }
    // ~BSTnode(){
    //   Left=nullptr;
    //   Right=nullptr;
    //   delete Left,Right;
    // }
    K Key;
    V Value;
    BSTnode* Left = nullptr;
    BSTnode* Right = nullptr;
};


template<class K, class V>
class BSTMap{
public:


  // pre-condition:   a valid key/value pair
  // post-condition:  pair will be added to the BST, if not already present
  //                  Return true if insert succeeded, else false
  bool insert(const K& key, const V& value);
  bool insert(BSTnode<K,V>*& p, const K& key,const V& value);//inserts at particular node

  // pre-condition:   a valid key
  // post-condition:  if key was present, key/value pair is removed
  //                  Return true if remove succeeded, else false
  bool findnremove(const K& key);
  void remove(BSTnode<K,V>*&);  //removes at particular node
  // pre-condition:   a valid key
  // post-condition:  return the corresponding value for key, else nullptr
  //                  the BST is not changed
  const V* search(const K& key) const;
  const V* search(BSTnode<K,V>* p ,const K& key) const;
  // pre-condition:   a valid BST
  // post-condition:  return whether or not BST contains any items
  //                  the BST is not changed
  bool isEmpty() const;

  // pre-condition:   a valid BST
  // post-condition:  prints contents of BST in sorted order
  //                  the BST is not changed
  void print() const;
  void print(BSTnode<K,V>* p) const;



  BSTnode<K,V>* root = nullptr;
};
//calls the proper insert function starting at root
template<class K, class V>
bool BSTMap<K,V>::insert(const K& key, const V& value){
    return insert(root,key,value);

}
//recursive insert function
template<class K, class V>
bool BSTMap<K,V>::insert(BSTnode<K,V>*& p,const K& key, const V& value){
  if(p == nullptr){
    p =  new BSTnode<K,V>(key,value);//no node at that pointer so create new one
    if(root == nullptr){
      root=p;
    }
    return true;
  }
  else if(key<p->Key){
    return insert(p->Left, key, value);//check if no node left
  }
  else if(key>p->Key){
    return insert(p->Right, key, value);//check if no node right
  }
  return false;
}


template<class K, class V>
const V* BSTMap<K,V>::search(const K& key) const{
  if(root==nullptr){//if empty return nullptr
    return nullptr;
  }
  else{
    return search(root,key);//otherwise call proper search function
  }
}

template<class K, class V>
const V* BSTMap<K,V>::search(BSTnode<K,V>* p,const K& key) const{
  while(p!=nullptr){  //while not null
    if(p->Key == key){
      return &p->Value; //return value if keys are the same
    }
    else if(p->Key < key){
      p=p->Right; //check right if key is greater than current key
    }
    else{
      p=p->Left;//check left if key is less than current key
    }
  }
  return nullptr;
}

template<class K, class V>
bool BSTMap<K,V>::isEmpty() const{
  if(root==nullptr){//if root is null tree is empty
    return true;
  }
  return false;
}

template<class K, class V>
void BSTMap<K,V>::remove(BSTnode<K,V>*& p){
    BSTnode<K,V>* tmp = p;//creates temp node
    if(p!=nullptr){ //if node is not empty
      if(p->Right==nullptr){ // if right is empty
        p=p->Left; //p becomes the left child
      }
      else if(p->Left==nullptr){
        p=p->Right;//if left is empty p becomes right child
      }
      else{
        tmp=p->Left; //set temp to left p
        while(tmp->Right!=nullptr){ //shift temp to right child until there is no node there
          tmp = tmp->Right;
        }
        tmp->Right=p->Right;
        tmp=p;
        p=p->Left;//p becomes left child
      }
      delete tmp;
    }
}


template<class K, class V>
bool BSTMap<K,V>::findnremove(const K& key){
    BSTnode<K,V>* node = root;
    BSTnode<K,V>* prev = nullptr;
      while(node!=nullptr){ //while it is not nuk=ll
        if(node->Key==key)  //  if the keys are the same start delete process
          break;
        prev = node;  //otherwise hold the last value
        if(node->Key<key){ //if node needs to go right shift node to the right
          node = node->Right;
        }
        else{//if node needs to go left shift node to the left
          node=node->Left;
        }

      }
      if(node!=nullptr && node->Key==key){ //if not null and same keys
        if(node == root)  //if its root remove the root
            remove(root);
        else if(prev-> Left == node){ //remove left
            remove(prev->Left);
        }
        else{
            remove(prev->Right);//remove right
        }
        return true;
      }
      else{
        return false;
      }
}

template<class K, class V>
void BSTMap<K,V>::print(BSTnode<K,V>* p) const{
  if(p!=nullptr){//if not null print key and value
    std::cout<<p->Key<<":"<<p->Value<<std::endl;
    print(p->Left);//recursively print left
    print(p->Right);//recursively print right
  }
}

template<class K, class V>
void BSTMap<K,V>::print() const{
  if(root!=nullptr)
    print(root);//print starting at root
}
