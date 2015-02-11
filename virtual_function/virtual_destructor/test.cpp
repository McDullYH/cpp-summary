#include<iostream>
using namespace std;
 
class Base1{
public:
    Base1(){cout<<"Base1 creat!\n";}
    ~Base1(){cout<<"Base1  destroy!\n";}
};
 
 
class Derive1:public Base1{
public:
    Derive1(){cout<<"Derive1 creat!\n";}
    ~Derive1(){cout<<"Derive1 destroy\n";}
};
 
 
 
class Base2{
public:
    Base2(){cout<<"Base2 creat!\n";}
   virtual ~Base2(){cout<<"Base2  destroy!\n";}
};
 
 
class Derive2:public Base2{
public:
    Derive2(){cout<<"Derive2 creat!\n";}
    ~Derive2(){cout<<"Derive2 destroy\n";}
};
 
 
int main()
{
  Base1 *bp1=new Derive1;
  //delete bp1;           only destroy Base1
  delete (Derive1*)bp1;
 
  Base2 *bp2=new Derive2;
  delete bp2;
 
  Derive1 *dp1=new Derive1;
  delete dp1;
  //delete (Base1*)dp1;    only destroy Base1
 
  Derive2 *dp2=new Derive2;
  //delete (Base1*)dp2;     //it seems strange,it show's that "delete" call ~Base1,and call ~Base1 only
  //delete (Base2*)dp2;         //it is right ,too
  delete dp2;
 
 
 
 
  cout<<sizeof(Base1)<<endl
      <<sizeof(Base2)<<endl;
 
  return 0;
}
