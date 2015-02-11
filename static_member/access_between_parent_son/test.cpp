#include <iostream>
using namespace std;
 
class Base
{
    public:
        static int data;
        static void setData(int d);
};
 
void Base::setData(int d)
{
    data =d;
}
 
int Base::data =0;
 
class Derive :public Base
{
    public:
        int x;
        static void setData(int d);
};
 
//int Derive::data =3;
//redefine!
 
 
//overload
void Derive::setData(int d)
{
    data=d*10;
    //x=d;
    //can not do this, bcs x is a setData is a static function
}
 
 
 
 
int main()
{
    Base::data=1;
    Derive::data=2;
    cout<<"Base data is "<<Base::data<<endl;
    Base b;
    b.setData(1);
    cout<<"Base data is "<<Base::data<<endl;
    Derive d;
    d.Base::setData(1);
    cout<<"Base data is "<<Base::data<<endl;
    d.setData(1);
    cout<<"Base data is "<<Base::data<<endl;
    return 0;
}
