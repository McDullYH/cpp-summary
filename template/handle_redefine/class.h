template <class T1,class T2>
class InterActive
{
 public:
  InterActive(const T1 &a,const T2 &b);
  
  void talk();

 private:
  const T1& ma;
  const T2& mb;
  //tips 1
  //here must be const because of constructor

};

template <class T1,class T2>
InterActive<T1,T2>::InterActive(const T1 &a,const T2 &b):ma(a),mb(b)
{
  //tips 2 
  //here must be InterActive<T1,T2> not InterActive bcs InterActive<T1,T2> is a class name but not InterActive
}


template <class T1,class T2>
void InterActive<T1,T2>::talk()
{
  ma.talk();
  mb.talk();
}
