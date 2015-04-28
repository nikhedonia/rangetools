#include<igloo/igloo_alt.h>
#include<itertools>
#include<type_traits>
#include<tuple>
#include<vector>
#include<typeinfo>
#include<chrono>
#include<exception>

using namespace igloo;
using namespace itertools;







Describe(functionalTestcase)
{
  It(should_have_iterable_ranges){
    
    auto j=1;
    for(auto i : range(1,10) ){
      Assert::That(i,Equals(j++));
    }

    j=9;
    for(auto i : reverse(range(1,10)) ){
       Assert::That(i,Equals(j--));
    }
 
    j=1;
    for(auto i : itertools::map(range(1,10),[](auto i){ return i*2;}) ){
       Assert::That(i,Equals(j*2));++j;
    }

    j=0;
    for(auto i: repeat(5,42)){
      Assert::That(i==42);
      ++j;
    }
    Assert::That(5==j);

  };
  
};

int main(int argc, char const* argv[])
{
  return TestRunner::RunAllTests(argc, argv);
}
