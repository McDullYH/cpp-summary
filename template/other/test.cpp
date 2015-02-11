#include <iostream>
using namespace std;
 
 
template <typename T>
class Test2
{
    public:
    Test2(){cout<<"Test2 is constuct!"<<endl;}
    T t;
};
 
 
template <typename T>
class Test
{
    public:
    Test(){cout<<"Test created!"<<endl;}
 
    void func(Test &same)       //默认类型为T！！！
    {
        cout<<"same"<<endl;
    }
    template <typename U>
    void func(Test<U> &diff)
    {
        cout<<"diff"<<endl;
    }
    T t;
 
    Test2<T>* func2(){ return new Test2<T>;}
    //Test2* func2(){ return new Test2;}
    //up is wrong because Test2 is not a type,Test2<int> is a type,T can only be used by Test
};
 
 
int main()
{
    Test<int> i;
    Test<int> i2;
    Test<double> d;
 
    i.func(i);
    i.func(i2);
    i.func(d);
 
    i.func2();
    return 0;
}


//Object<int> 和 Object<double>是2种完全不同的类型
