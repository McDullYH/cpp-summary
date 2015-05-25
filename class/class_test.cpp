#include "class_test.h"



int Dog::sCount=0;

Dog::Dog():id(++sCount)
{
  age=0;
}

Dog::Dog(int iid):id(iid)
{
  age=0;
  ++sCount;
}

Dog::~Dog()
{
  sCount--;
}

void Dog::setCount(int count)
{
  sCount=count;
}

int Dog::getCount()
{
  return sCount;
}


void showDogCount()
{
  printf("there are %d dogs\r\n",Dog::getCount());
}

void setDogCount(int count)
{
  Dog::setCount(count);
} 
