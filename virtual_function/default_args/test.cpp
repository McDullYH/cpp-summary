#include <iostream>
 
using namespace std;
 
class Base
{
  public:
  virtual void function(int n=1)=0;
  virtual void function2(int n=2)=0;
 
  void function3(int n=3)
  {
    cout<<"n="<<n<<endl;
  }
 
  virtual void function4(int n=4)
  {
    cout<<"n="<<n<<endl;
  }
};
 
class Derive:public Base
{
  public:
  void function(int n)
  {
    cout<<"n="<<n<<endl;
  }
 
  void function2(int n=20)
  {
    cout<<"n="<<n<<endl;
  }
 
  void function3(int n=3)
  {
    cout<<"n="<<n*10<<endl;
  }
 
  virtual void function4(int n=4)
  {
    cout<<"n="<<n*10<<endl;
  }
};
 
void function(int a,int b,int c=30)
{
  cout<<"a="<<a<<endl
    <<"b="<<b<<endl
    <<"c="<<c<<endl;
}
void function(int a,int b)
{
  cout<<"a="<<a<<endl
    <<"b="<<b<<endl;
}
 
int main()
{
  Base *bd=new Derive();
  bd->function();    //attention!
  bd->function2();
  bd->function3();
  bd->function4();
  bd->Base::function4();
 
  cout<<endl;
 
  Derive *dd=new Derive();
  //dd->function();
  //wrong!
  dd->function2();   //attention!
  dd->function3();
  dd->function4();
  dd->Base::function4();
 
  //in Derive function1 and function2 is reimplement,but 3,4 is override (not overload)
  //function(1,2);
  //c++ don't know call which function,
  //so don't define two fuction like this or even like this
  function(1,2,3);
  return 0;
}
