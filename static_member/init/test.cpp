#include <iostream>
 
using namespace std;
 
class A
{
public:
 
  A(int x=0){a=x;}
  int a;
 
  static int sa;
  //static int sa=20;           //wrong!
  static const int sca;
  //static const int sca=30;        //right!
 
  static int sar[];
  //static int sar[]={1,2,3};       //wrong!
  static const int scar[];
//  static const int scar[]={1,2,3,4};  //wrong!
 
  void show()
  {
    cout<<"a is "<<a<<endl
        <<"sa is "<<sa<<endl
        <<"sca is "<<sca<<endl;
 
    cout//<<"ar is "<<ar<<endl
      <<"sar is "<<sar[2]<<endl
      <<"scar is "<<scar[3]<<endl<<endl;
  }
};
 
const int A::sca=30;            //be in or out it is all right! but only once!
int A::sa=20;               //must be out define
//A::sa=40;             //wrong! but in main it is right!
 
int A::sar[]={1,2,3};           //must be out
const int A::scar[]={1,2,3,4};      //must be out
 
int main()
{
//int A::sa=20;             //wrong!
//const int A::sca=30;          //wrong!
  A o(10);
  o.show();
 
  A::sa=40;
  A::sar[2]=200;
  o.show();
  return 0;
}
