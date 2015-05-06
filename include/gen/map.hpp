#ifndef RANGETOOLS_MAP_HPP
#define RANGETOOLS_MAP_HPP

#include "generator.hpp"

namespace rangetools {

template<class F>
struct Map{
  F f;

  template<class P>
  auto value(P && p){ return f(*p); }
};

}



#endif
