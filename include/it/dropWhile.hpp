#ifndef RANGETOOLS_DROPWHILE_HPP
#define RANGETOOLS_DROPWHILE_HPP

#include "generator.hpp"

namespace rangetools {

template<class F>
struct DropWhile {
  F f;
  bool dropping=1;

  template<class P>
  bool advance(P&&p){
    while( dropping && p && f(*p) ) ++p;
    dropping = 0;
    return p.done();
  }

  template<class P>
  bool done(P&&p){
    advance(p);
    return p.done();
  }

  template<class P>
  auto value(P&&p){
    return *p;
  }

};

}



#endif
