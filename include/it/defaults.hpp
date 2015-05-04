#ifndef RANGETOOLS_DEFAULTS_HPP
#define RANGETOOLS_DEFAULTS_HPP

#include "generic.hpp"

namespace rangetools {
namespace def{

template<class L,
  REQUIRES( !has_next<L>()) >
bool next(L) {
  return 1;
}

template<class L,
  REQUIRES( !has_done<L>() ) >
bool done(L) {
  return 0;
}

template<class L,
  REQUIRES( !has_value<L>() ) >
bool value(L) {
  return 0;
}


template<class L,
  REQUIRES( has_next<L>() ) >
auto next(L&l)
-> decltype(l.next()) {
  return l.next();
}

template<class L,
  REQUIRES( has_done<L>() ) >
auto done(L&l)
-> decltype(l.done()) {
  return l.done();
}

template<class L,
  REQUIRES( has_value<L>() ) >
auto value(L&l)
-> decltype(l.value()) {
  return l.value();
}


template<class L, class R,
  REQUIRES( !has_next<L,R>() ) >
auto next(L&l, R&r)
-> void {
  def::next(l);
  def::next(r);
}

template<class L, class R,
  REQUIRES( !has_done<L,R>() ) >
auto done(L&l, R&r)
-> bool {
  return def::done(l) || def::done(r) ;
}

template<class L, class R,
  REQUIRES( !has_value<L,R>() ) >
auto value(L&l, R)
-> decltype( def::value(l)  ) {
  return def::value(l) ;
}


template<class L, class R,
  REQUIRES( has_next<L,R>() ) >
auto next(L&l, R&r)
-> decltype(l.next(r)) {
  return l.next(r);
}

template<class L, class R,
  REQUIRES( has_done<L,R>() ) >
auto done(L&l, R&r)
-> decltype(l.done(r)) {
  return l.done(r);
}

template<class L, class R,
  REQUIRES( has_value<L,R>() ) >
auto value(L&l, R&r)
-> decltype(l.value(r)) {
  return l.value(r);
}



}
}



#endif
