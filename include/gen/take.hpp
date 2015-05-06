#ifndef RANGETOOLS_TAKE_HPP
#define RANGETOOLS_TAKE_HPP

#include "generator.hpp"

namespace rangetools {

template<class F>
struct Take {
  F f;

  template<class P>
  bool advance(P&&p){
    while( p && !f(*p) )  ++p;
    return p.done();
  }

  template<class P>
  bool done(P&&p){
    advance(p);
    return p.done();
  }

  template<class P>
  auto next(P&&p){
    ++p;
    advance(p);
  }

  template<class P>
  auto value(P&&p){
    return *p;
  }

};

}



#endif
