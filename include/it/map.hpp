#ifndef RANGETOOLS_MAP_HPP
#define RANGETOOLS_MAP_HPP

#include "generator.hpp"
#include <functional>

namespace rangetools {

template<class F>
struct Map{
  F f;


  template<class P>
  auto value(P && p){ return f(*p); }
};

template<template<class> class W, class F>
auto Wrap(F f) {
  return gen*W<F>{ f };
}

}



#endif
