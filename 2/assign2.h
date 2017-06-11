template<class T>
class SortedBag{

  public:
      SortedBag();
      ~SortedBag();
      void add(const& T item);
      void remove(const& T item);
      bool inBag(const& T item);
      void PrintBag();
  private:
      int size=0;
      bool empty = true;
      SortedBag *next = nullptr;
};
