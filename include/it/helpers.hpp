#ifndef RANGETOOLS_HELPERS_HPP
#define RANGETOOLS_HELPERS_HPP

#include "generator.hpp"

namespace rangetools {

static constexpr auto gen = Gen<>() ;

template<template<class> class W, class F>
auto Wrap(F f) {
  return gen*W<F>{ f };
}

}



#endif
