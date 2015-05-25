#include "class_test.h"



int main()
{

  Dog d1;
  const Dog d2;
  const Dog d3;
  d1.say();
  d1.showMyId();
  d2.showMyId();
  d1.shout();

  //setDogCount(10);
  showDogCount();


  const Cat c(1,2.0);
  // c is const, so you can't change c.head's value, except for head is mutable;
  // ** what const object means the whole object's content is read-only **
  // so you can only call const function to forbid to change the content's value
  // c.head=0;


  // followin is the same reason, char str[] is an auto var, all str content is read-only
  //const char str[]="you know?";
  //str[0]='c';
  char str1[]="you know?";
  str1[0]='c';

  return 0;
}
