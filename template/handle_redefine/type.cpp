#include <iostream>
using namespace std;

#include "type.h"
#include "function.h"

void A::talk() const
{
  cout<<"i am class A"<<endl;
  add(1,2);
}

void B::talk() const
{
  cout<<"i am class B"<<endl;
}
