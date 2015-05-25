#include <stdio.h>


class
__attribute__((visibility("default")))
// if not set to default, other program link to this so won't see Dog
Dog
{
 public:
  Dog();
  Dog(int id);
  virtual ~Dog();
  void say()
  {
    printf("I'm saying\r\n");
  }


  // non-const can call const function and non-const function, but non-const function has higher priority
  void showMyId()
  {
    printf("My id is %d \r\n",id);
  }

  // const obj can only call const function
  // so just implement the const version for less work
  // this 2 funcion is overload relationship
  void showMyId() const 
  {
    printf("const function, My id is %d \r\n",id);
  }

  // const function will nerver change the member's value, throught it can change the member's value whose type is "mutable"
  // but if you do so, why don't you think about your design
  void showMyAge() const
  {
    printf("My age is %d \r\n",age);
  }

  void increaceMyAge()
  {
    age++;
  }

  // const function actually use a const *this, such as : const Dog *this
  void shout() 
  {
    printf("I'm shouting\r\n");

    // what "this" is defaultly decleared  as   X* const this
    // if in const object such as const Dog d, "this" is decleared as const X* const this
    // this = new Dog(100);
    // this = NULL;
  }

  static void setCount(int count);
  static int getCount();

 private:
  const int id;
  int age;

  static int sCount;
};

__attribute__((visibility("default")))
void showDogCount();

// other program link to this so won't see setDogCount but showDogCount  
void setDogCount(int );


struct Cat
{
  Cat(int he,double ha)
  {
    head=he;
    hand=ha;
  }
  int head;
  double hand;
};
