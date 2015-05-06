#ifndef RANGETOOLS_HELPERS_HPP
#define RANGETOOLS_HELPERS_HPP

#include "generator.hpp"

namespace rangetools {

static constexpr auto gen = Gen<>() ;

template<template<class> class W, class F>
auto Wrap(F f) {
  return gen*W<F>{ f };
}

static auto each = [](auto F){
  return Wrap<Each>(F);
};

static auto map = [](auto F){
  return Wrap<Map>(F);
};

static auto take = [](auto...X){
  return Wrap<Take>(X...);
};

static auto takeWhile = [](auto...X){
  return Wrap<TakeWhile>(X...);
};

static auto dropWhile = [](auto...X){
  return Wrap<DropWhile>(X...);
};

static auto range = [](auto...X){
  return gen*Range(X...);
};


}

#endif
