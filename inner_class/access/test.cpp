//C++'s inner class can not use outer class's member,but static member

#include <iostream>
using namespace std;


class Object
{
 public:
  class Test
  {
   public:
    void TFunc()
    {
      mData=100;
      sData=10;
    }
  };
  Test t;
  void OFunc()
  {
    t.TFunc();
  }
 private:
  int mData;
  static int sData;
};


int main()
{
  return 0;
}
