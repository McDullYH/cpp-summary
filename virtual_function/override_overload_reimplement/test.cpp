#include <iostream>
using namespace std;
 
 
class Object
{
public:
    void function1(int m,int n,int x)
    {
        cout<<"Object function1(int m,int n,int x)"<<endl;
    }
    void function2(int m,int n,int x)
    {
        cout<<"Object function2(int m,int n,int x)"<<endl;
    }
};
 
class Base:public Object
{
public:
    virtual void function1()
    {
        cout<<"Base function1()"<<endl;
    }
    virtual void function1(int n)
    {
        cout<<"Base function1(int n)"<<endl;
    }
    void function1(int m,int n)
    {
        cout<<"Base function1(int m,int n)"<<endl;
    }
};
 
class Derive:public Base
{
public:
    //using Base::function1;
    void function1()
    {
        cout<<"Derive function1()"<<endl;
    }
};
 
int main()
{
    Base *bd=new Derive();
    bd->function1();
    bd->function1(1);
    bd->function1(1,2);
    //bd->function1(1,2,3);
    bd->function2(1,2,3);
 
    cout<<endl;
    Derive d;
    d.function1();
    //d.function1(1);           //if you want is goes add using Base::function1 in class Derive;
    d.function2(1,2,3);
 
 
/*
for point and reference   such as Base *bd
if(findName)
    if(matchArgs)
        if(virtual)
            if(findNameInDerive && matchArgsInDerive)
                useDerive;
            else if(!findNameInDerive && matchArgsInDerive)
                useBase;
        else if(!virtual)
            useBase
    else if(!matchArgs)
        g++Error
else if(!findName)
    findInThis'sParents         (do this in Object* , bd's parents)
*/
 
 
    return 0;  
}
 
 
/*
for object              //such as d
if(findName)
    if(matchArgs)
            use
    else if(!matchArgs)         //"using Base::function;"  is a method for you to implement less
        g++Error            //special function that different from its Base,
else if(!findName)          //or you will implement all again,
    findInThis'sParents         (do this in Base d's parents)
 
*/
