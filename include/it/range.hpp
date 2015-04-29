#ifndef RANGETOOLS_RANGE_HPP
#define RANGETOOLS_RANGE_HPP

#include "generic.hpp"
#include "generator.hpp"

namespace rangetools {

struct Range  {
  int i;
  int n;

  Range(int i, int n) : i(i) , n(n) {}
  Range(int n) : i(0) , n(n) {}

  auto next() { ++i; }
  auto done() { return i>=n; }
  auto value(){ return i; }

};

}

#endif
