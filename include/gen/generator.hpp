#ifndef RANGETOOL_GENERATOR_HPP
#define RANGETOOL_GENERATOR_HPP

#include "defaults.hpp"

namespace rangetools {

template<class T=void>
struct Gen {
  T i;

  template<class...X>
  Gen(X...x)
  : i(x...)
  {}

  template<class U>
  auto operator!=(U) { return !def::done(i); }
  operator bool()    { return !def::done(i); }
  auto operator*()   { return def::value(i); }
  auto operator++()  { return def::next(i);  }

  auto next()        { return def::next(i);  }
  auto done()        { return def::done(i);  }
  auto value()       { return def::value(i); }

  template<class U>
  auto next(U&u)     { return def::next(i,u);  }
  template<class U>
  auto done(U&u)     { return def::done(i,u);  }
  template<class U>
  auto value(U&u)    { return def::value(i,u); }
  auto begin()      { return *this;      }
  auto end()        { return *this;      }

  //auto operator=(Gen<T> const& G) { for generator restart
  //  return i=G.model); // (lambda default-copy-constructor?)
  //}
  ////private: T model = i


};


template<class L, class R>
struct GenChain {
  L l;
  R r;

  template<class U>
  auto operator!=(U) { return !done(); }
  operator bool()    { return !done(); }
  auto operator*()   { return r.value(l); }
  auto operator++()  { return r.next(l);  }
  auto next()        { return r.next(l);  }
  auto done()        { return r.done(l);  }
  auto value()       { return r.value(l); }
  auto begin()       { return *this;      }
  auto end()         { return *this;      }
};

template<class R, class B, class E>
struct GenRange {
  R r;
  B b;
  E e;

  GenRange(GenRange const& G)
    : r(G.r)  {
    restart();
  }

  GenRange(R r)
    : r(r)  {
    restart();
  }

  template<class U>
  auto operator!=(U) { return !done(); }
  operator bool()    { return !done(); }
  auto operator*()   { return value(); }
  auto operator++()  { return next();  }
  auto next()        { return ++b;     }
  auto done()        { return !(b!=e); }
  auto value()       { return *b;      }
  auto begin()       { return *this;   }
  auto end()         { return *this;   }
  auto restart()     {
    b=r.begin();
    e=r.end();
  }
};



template<>
struct Gen<void>
{};

}


#endif
