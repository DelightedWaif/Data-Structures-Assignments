#ifndef __HASH_WITH_CHAINING_
#define __HASH_WITH_CHAINING_

#include <vector>
#include "HashTable.hxx"

/**
 * This class uses separate chaining as described in class, but instead
 * of using linked lists, it uses vectors.
 * The idea and complexity is the same, but you're probably more accustomed
 * to using vectors vs. linked lists.
 */

template<class K, class V>
class HashWithChaining : public HashTable<K,V>
{
  public:
    // c'tor (initializes hashcode lambda function and size)
    HashWithChaining(std::function<int(K)> hc) : hashcode(hc), size(0){
    }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      if(capacity==size){
        return false;
      }
      int check = hashcode(key)%capacity;
      examined++;
      if(data[check].empty()){
        size++;
      }
      data[check].push_back(HTEntry(key,value));
      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int check = hashcode(key)%capacity;
      for(int i=0; i<check; i++){
        examined++;
        if(key==data[check][i].key){
          return &data[check][i].value;
        }
      }
      return nullptr;
    }
    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      return size/capacity;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return examined;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      for(auto i=0; i<capacity;i++){
        if(!data[i].empty()){
          for(auto j=0; j<data[i].size();j++){
            cout<<"data["<<" Key:"<<data[i][j].key<<", Value:"<<data[i][j].value<<"]"<<endl;
          }
        }
      }
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;

    // Contains key/value pairs for the hashtable
    struct HTEntry {
      K key;
      V value;

      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };

    // A bucket array of vectors (each vector contains type 'HTEntry')
    vector<HTEntry> data[capacity];
    int size;
    int examined=0;
};

#endif
