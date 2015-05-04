#include<igloo/igloo_alt.h>
#include<rangetools>

using namespace rangetools;
using namespace igloo;
using namespace std;


Describe(rangeToolsTestcase)
{
  Describe(genericTests){

    struct test{
      template<class T>
      int next(T);
    };

    It(should_detect_callability){
      Assert::That( has_next<test,int>() , Equals(1) );
      Assert::That( has_next<int,int>() , Equals(0) );
    }
  };

  Describe(RangeTest){
    It(should_count_from_0_to_5){
      int i=0;
      for( auto j : gen*Range(5) ){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i==5);
    }

    It(should_be_composable_and_count_from_5_to_9){
      int i=5;
      for( auto j : gen*Range(5) | gen*Range(5,10) ){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i==10);
    }
  };


  Describe(MapTest){
    It(should_count_from_2_to_7){
      int i=2;

      for( auto j : gen*Range(5)
                  | Wrap<Map>([](auto x){ return x+1; })
                  | Wrap<Map>([](auto x){ return x+1; })  ){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i==7);
    }
  };

  Describe(TakeTest){
    It(should_count_odd_from_0_to_10){
      int i=1;

      for( auto j : gen*Range(10)
                  | Wrap<Take>([](auto x){ return x%2; }) ) {
        Assert::That( j == i );
        i+=2;
      }
      Assert::That(i==11);
    }
  };




};

int main(int argc, char const* argv[])
{
  return TestRunner::RunAllTests(argc, argv);
}
