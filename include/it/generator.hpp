#ifndef rangetools_generator_hpp
#define rangetools_generator_hpp


#include "generic.hpp"

namespace rangetools {


namespace def{

template<class L,
  REQUIRES( !has_next<L>()) >
bool next(L) {
  return 1;
}

template<class L,
  REQUIRES( !has_next<L>() ) >
bool done(L) {
  return 0;
}

template<class L,
  REQUIRES( !has_value<L>() ) >
bool value(L) {
  return 0;
}


template<class L,
  REQUIRES( has_next<L>() ) >
auto next(L&l)
-> decltype(l.next()) {
  return l.next();
}

template<class L,
  REQUIRES( has_done<L>() ) >
auto done(L&l)
-> decltype(l.done()) {
  return l.done();
}

template<class L,
  REQUIRES( has_value<L>() ) >
auto value(L&l)
-> decltype(l.value()) {
  return l.value();
}


template<class L, class R,
  REQUIRES( !has_next<L,R>() ) >
auto next(L&l, R)
-> decltype(l.next()) {
  return l.next();
}

template<class L, class R,
  REQUIRES( !has_done<L,R>() ) >
auto done(L&l, R)
-> decltype(l.done() ){
  return l.done();
}

template<class L, class R,
  REQUIRES( !has_value<L,R>() ) >
auto value(L&l, R)
-> decltype(l.value()) {
  return l.value();
}


template<class L, class R,
  REQUIRES( has_next<L,R>() ) >
auto next(L&l, R&r)
-> decltype(l.next(forward<R>(r))) {
  return l.next(forward<R>(r));
}

template<class L, class R,
  REQUIRES( has_done<L,R>() ) >
auto done(L&l, R&r)
-> decltype(l.done(forward<R>(r))) {
  return l.done(forward<R>(r));
}

template<class L, class R,
  REQUIRES( has_value<L,R>() ) >
auto value(L&l, R&r)
-> decltype(l.value(forward<R>(r))) {
  return l.value(forward<R>(r));
}



}





template<class T=void>
struct Gen
{
  T i;

  template<class...X>
  Gen(X...x)
  : i(x...)
  {}

  template<class U>
  auto operator!=(U) { return !def::done(i); }
  operator bool()    { return !def::done(i); }
  auto operator*()   { return def::value(i); }
  auto operator++()  { return def::next(i);  }

  auto next()        { def::next(i);  }
  auto done()        { return def::done(i);  }
  auto value()       { return def::value(i); }

  template<class U>
  auto next(U&u)     { def::next(i,u);  }
  template<class U>
  auto done(U u)     { return def::done(u) || def::done(i,u);  }
  template<class U>
  auto value(U u)    { return def::value(i,u); }

  auto& begin()      { return *this;      }
  auto& end()        { return *this;      }

};


template<class L, class R>
struct GenChain
{
  L l;
  R r;

  template<class U>
  auto operator!=(U) { return !l.done() &&  !r.done(l); }
  operator bool()    { return !l.done() &&  !r.done(l); }
  auto operator*()   { return r.value(l); }
  auto operator++()  { return r.next(l);  }
  auto next()        { return r.next(l);  }
  auto done()        { return r.done(l);  }
  auto value()       { return r.value(l); }
  auto& begin()      { return *this;        }
  auto& end()        { return *this;        }

};


template<>
struct Gen<void>
{};

static constexpr auto gen = Gen<>() ;


template<class R>
constexpr auto operator *( Gen<> G, R r){
  return Gen<R>(r);
}

template<class L,class R,
  REQUIRES( decltype( declval<L>().next() , declval<R>().next() , 1 )(1)  )
>
constexpr auto operator |( L l, R r){
  return GenChain<L,R>{l,r};
}



}


#endif
