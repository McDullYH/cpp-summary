#include <iostream>
using namespace std;

#include "type1.h"
#include "function.h"

void C::talk() const
{
  cout<<"i am class C"<<endl;
  add(1,2);
}

void D::talk() const
{
  cout<<"i am class D"<<endl;
}
