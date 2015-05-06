#ifndef RANGETOOLS_REPEAT_HPP
#define RANGETOOLS_REPEAT_HPP

#include "generator.hpp"

namespace rangetools {

struct Repeat{
  int i = -1;

  Repeat(int i)
    :i(i)
  {}

  template<class P>
  auto done(P && p){
    if(p.done()){
      (i>0) && --i;
      p = p.begin();  // does not work yet...
    }
    return p.done() && !i;
  }

  template<class P>
  auto next(P && p){
    ++p;
  }

  template<class P>
  auto value(P && p){
    return *p;
  }
};

}



#endif
