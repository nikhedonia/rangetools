#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace itertools{

template<class T>
struct Iter{
  T value;

  const T operator*()const{ return value;}
  const operator T()const{ return value; }
  auto& operator++(){ ++value; return *this; }
  auto operator++(int)const{ return Iter<T>{value+1}; }

  template<class U>
  auto operator+(U s)const{ 
    return Iter<decltype(value+s)>{value+s}; 
  };

};

template<class T>
struct IterR{
  T value;

  const T operator*()const{ return value;}
  const operator T()const{ return value; }
  auto& operator++(){ --value; return *this; }
  auto operator++(int)const{ return IterR<T>{value-1}; }

  template<class U>
  constexpr auto operator+(U s)const{ 
    return IterR<decltype(value-s)>{value-s}; 
  };

};


template<class T,class F>
struct IterMap{
  T it;
  F f;

  decltype(auto) operator*()const{ return f(*it);}

  constexpr operator T()const{ return it; }
  auto& operator++(){ ++it; return *this; }
  auto operator++(int)const{ return IterMap<T,F>{it+1,f}; }

  template<class U>
  constexpr auto operator+(U s)const{ 
    return IterMap<decltype(it+s),F>{it+s,f}; 
  };

  
};

template<class LT,class RT, class F>
auto operator<(IterMap<LT,F> const lhs, IterMap<RT,F> const rhs){
   return lhs.it<rhs.it;
}


template<class LT,class RT, class F>
auto operator!=(IterMap<LT,F> const lhs, IterMap<RT,F> const rhs){
   return lhs.it!=rhs.it;
}


template<class B,class E>
struct Range{

  const B b;
  const E e;

  constexpr auto begin()const{
    return Iter<B>{b};
  }

  constexpr auto end()const{
    return Iter<E>{e};
  }
 
  constexpr auto rbegin()const{
    return IterR<E>{e-1};
  }

  constexpr auto rend()const{
    return IterR<B>{b-1};
  } 

};

template<class R,class F>
struct MappedRange{
  R r;
  F f;

  auto begin(){
    return IterMap<decltype(r.begin()),F>{r.begin(),f};
  }

  auto end(){
    return IterMap<decltype(r.end()),F>{r.end(),f};
  }

  auto rbegin(){
  return IterMap<decltype(r.rbegin()),F>{r.rbegin(),f};
  }

  auto rend(){
    return IterMap<decltype(r.rend()),F>{r.rend(),f};
  }


};

template<class R>
struct Reverse{
  R r;

  constexpr auto begin()
  -> decltype(r.rbegin()){
    return r.rbegin();
  }

  constexpr auto end()
  -> decltype(r.rend()){
    return r.rend();
  }


};


template<class B,class E>
constexpr auto range(B const b, E const e){
  return Range<B,E>{b,e};
} 

template<class E>
constexpr auto range(E const e){
  return Range<E,E>{0,e,1};
} 

template<class R>
constexpr auto reverse(R r){
  return Reverse<R>{r};  
}


template<class R, class F>
constexpr auto map(R r,F f){
  return MappedRange<R,F>{r,f};  
}




  


}


#endif
