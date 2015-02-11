#include <iostream>
using namespace std;
 
class GrandParent
{
    public:
    virtual void print(){cout<<"i am GrandParent"<<endl;}
};
 
class Parent:public GrandParent
{
    public:
    void print(){cout<<"i am Parent"<<endl;}
};
 
class Son:public Parent
{
};
 
 
 
int main()
{
    GrandParent* p=new Son();
    p->print();
    return 0;
}
