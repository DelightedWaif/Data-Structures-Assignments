template<class T>
class node;

template<class T>
class node{
  node();
  ~node();
  public:
    node<T>* next = nullptr;
    int count;
    T funStuff;
};
