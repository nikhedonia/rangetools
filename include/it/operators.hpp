#ifndef RANGETOOLS_OPERATORS_HPP
#define RANGETOOLS_OPERATORS_HPP

#include "generator.hpp"

namespace rangetools {

template<class R,
  REQUIRES(
    !has_begin<R>() &&
    !has_end<R>()
)>
constexpr auto operator *( Gen<> G, R r)
-> decltype(   Gen<R>(r) ) {
  return r;
}

template<class R>
constexpr auto operator *( Gen<> G, R r )
-> decltype( GenRange<R,decltype(r.begin()),decltype(r.end())>(r) ) {
  return r;
}



template<class L,class R>
auto operator |( L l, R r){
  return GenChain<L,R>{ l,r };
}

}

#endif
