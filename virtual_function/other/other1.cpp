#include <iostream>
using namespace std;
 
class Base
{
 public:
  Base(int d=0)
  {
    data=d;
  }
  void func(int x)
  {
    plus(x);
  }
  virtual void plus(int x)
  {
    data = data+x;
  }
  void print()
  {
    cout<<"data is"<<data<<endl;
  }
 
  int data;
};
 
 
class Derive:public Base
{
 public:
  Derive(int d=0):Base(d)
  {}
  void plus(int x)
  {
    data=data+10*x;
  }
};
 
int main()
{
  Derive *d=new Derive(0);
  Base *b=new Base(0);
  b->func(1);
  d->func(1);
  b->print();
  d->print();
  Base *x=new Derive(0);
  x->func(1);
  x->print();
  return 0;
}
 
/*
 * just remember that all class function is called in the style like 'this->function'
 */
