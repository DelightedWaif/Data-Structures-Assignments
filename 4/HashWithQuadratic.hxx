#ifndef __HASH_WITH_QUADRATIC_
#define __HASH_WITH_QUADRATIC_

#include "HashTable.hxx"

/**
 * This class uses open-addressing, specifically quadratic probing to
 * resolve collisions.
 */

template<class K, class V>
class HashWithQuadratic : public HashTable<K,V>
{
  public:
    HashWithQuadratic<K,V>(std::function<int(K)> hc)
    : hashcode(hc), size(0)
     {
        for (int i=0; i<capacity; i++)
          data[i]=nullptr;  //sets array values to null
      }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      if(size==capacity){ //if full dont add
        return false;
      }
      int check = hashcode(key)%capacity; //get key from hashcode
      for(int i=1; data[check]!= nullptr; i++){ //check for empty spot
        examined++;
        check = (check + (i*i-i)/2)%capacity;
      }

      examined++;
      data[check] = new HTEntry(key, value);  //add to empty spot
      size++;
      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int check = hashcode(key)%capacity;//get key from hashcode
      for(int i=0; data[check]!=nullptr; i++){//search hashtable for key
        examined++;
        if(data[check]->key==key){
          return &data[check]->value; //return the arrporpeate value
        }
        check = (check + (i*i-i)/2)%capacity;
      }
      return nullptr;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      return size/capacity; //gets load factor
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return examined;  //gets keys examined
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {

      for(int i=0; i<capacity; i++){
        if(data[i]!= nullptr)
          cout<<"data["<<" Key:"<<data[i]->key<<", Value:"<<data[i]->value<<"]"<<endl;  //prints all of the values in the hashtable
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

    // An array of type 'HTEntry' pointers (nullptr indicates that the
    // position is empty)
    HTEntry* data[capacity];
    int size;
    int examined;
};

#endif
