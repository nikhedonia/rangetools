#ifndef RANGETOOLS_EACH_HPP
#define RANGETOOLS_EACH_HPP

#include "generator.hpp"

namespace rangetools {

template<class F>
struct Each{
  F f;

  template<class P>
  auto value(P && p){ f(*p); return *p; }
};

}



#endif
