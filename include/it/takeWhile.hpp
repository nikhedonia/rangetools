#ifndef RANGETOOLS_TAKEWHILE_HPP
#define RANGETOOLS_TAKEWHILE_HPP

#include "generator.hpp"

namespace rangetools {

template<class F>
struct TakeWhile {
  F f;

  template<class P>
  bool done(P&&p){
    return p.done() || !f(*p);
  }

  template<class P>
  auto value(P&&p){
    return *p;
  }

};

}



#endif
