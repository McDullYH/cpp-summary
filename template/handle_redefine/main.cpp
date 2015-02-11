#include <iostream>
using namespace std;

#define OPEN_LOG
#include "log.h"


#include "class.h"

#include "type.h"
#include "type1.h"
// libtemplate.so and libtemplate1.so all has defination of add(int,int), but g++ will handle this conflict
// so what you need to do is just put all your template declaration and defination in a .h file
#include "function.h"


int main()
{
  double dob=add(1,2);

  int i1 = add(2,3.0);

  int i2 = add(4.0,3.0);

  LOGX(dob);
  LOGX(i1);
  LOGX(i2);

  A a;
  B b;

  InterActive<A,B> ia(a,b);
  ia.talk();

  C c;
  D d;
  InterActive<C,D> ia1(c,d);
  ia1.talk();

  return 0;
}

