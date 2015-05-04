#ifndef RANGETOOLS_OPERATORS_HPP
#define RANGETOOLS_OPERATORS_HPP

#include "generator.hpp"

namespace rangetools {

template<class R>
constexpr auto operator *( Gen<> G, R r){
  return Gen<R>(r);
}

template<class L,class R>
auto operator |( L l, R r){
  return GenChain<L,R>{ l,r };
}

}

#endif
