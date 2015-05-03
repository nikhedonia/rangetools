#ifndef RANGETOOLS_GENERIC_HPP
#define RANGETOOLS_GENERIC_HPP

#include <iostream>
#include <type_traits>

namespace rangetools {

using std::declval;
using std::forward;
using std::move;
using std::result_of;
using std::decay_t;

#define REQUIRES(...) typename std::enable_if<(__VA_ARGS__), int>::type = 0


#define CREATE_CALL_CHECKER(PREFIX, MEM )\
template<class F,class...X>\
constexpr auto PREFIX##MEM##_impl (int)\
-> decltype( declval<F>(). MEM ( declval<X>()... ) , bool() )\
{ return 1; }\
\
template<class F,class...args>\
constexpr auto PREFIX##MEM##_impl(...)\
-> bool\
{ return 0; }\
\
template<class F,class...X>\
constexpr auto PREFIX##MEM ()\
-> decltype( PREFIX##MEM##_impl<F,X...>(0) )\
{ return PREFIX##MEM##_impl<F,X...>(0); }


CREATE_CALL_CHECKER(has_,next)
CREATE_CALL_CHECKER(has_,done)
CREATE_CALL_CHECKER(has_,value)



}


#endif
