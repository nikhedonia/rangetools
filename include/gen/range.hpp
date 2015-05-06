#ifndef RANGETOOLS_RANGE_HPP
#define RANGETOOLS_RANGE_HPP

#include "generic.hpp"
#include "generator.hpp"
#include <iostream>
using namespace std;
namespace rangetools {

struct Range  {
  int i;
  int n;

  Range(int i, int n) : i(i) , n(n) {}
  Range(int n=-1) : i(0) , n(n) {}

  auto next() { ++i; }
  auto done() { return (i>=n)&&(n>=0); }
  auto value(){ return i; }

};

}

#endif
