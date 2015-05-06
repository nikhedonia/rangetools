#include<igloo/igloo_alt.h>
#include<rangetools>
#include<vector>

using namespace rangetools;
using namespace igloo;


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
      Assert::That(i, Equals(10));
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
      Assert::That(i, Equals(7));
    }
  };

  Describe(EachTest){
    It(should_count_from_1_to_6){
      int i=1;
      int k=0;
      for( auto j : gen*Range(5)
                  | Wrap<Each>([&](auto x){ Assert::That( x == k++ ); })
                  | Wrap<Map>([](auto x){ return x+1; })){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(k, Equals(5));
      Assert::That(i, Equals(6));
    }
  };

  Describe(TakeTest){
    It(should_skip_even_numbers_between_0_to_10){
      int i=1;

      for( auto j : gen*Range(10)
                  | Wrap<Take>([](auto x){ return x%2; }) ) {
        Assert::That( j == i );
        i+=2;
      }
      Assert::That(i, Equals(11) );
    }
  };


  Describe(TakeWhileTest){
    It(should_be_done_after_10){
      int i=0;

      for( auto j : gen*Range()
                  | Wrap<TakeWhile>([](auto x){ return x<10; }) ) {
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i, Equals(10) );
    }
  };

  Describe(DropWhileTest){
    It(should_count_from_5_to_10){
      int i=5;

      for( auto j : gen*Range(10)
                  | Wrap<DropWhile>([](auto x){ return x<5; }) ) {
        Assert::That( j, Equals(i) );
        ++i;
      }
      Assert::That(i, Equals(10) );
    }
  };

  Describe(ContainerTest){
    It(should_count_from_1_to_5){
      int i=1;
      vector<int> V={1,2,3,4,5};

      for( auto j : gen*V
                  | Wrap<Map>([](auto x){ return x; }))  {
        Assert::That( j, Equals(i) );
        ++i;
      }
      Assert::That(i==6);
    }
  };

  //fail
  //Todo: make generators restartable
  Describe(RepeatTest){
    int j=0;
    It(should_count_twice_to_3){
      for(auto i : gen*Range(3)
                 | gen*Repeat(2) ){
        Assert::That(i, Equals(j%3) );
        ++j;
      }
      Assert::That(j, Equals(6) );
    }
  };
};

int main(int argc, char const* argv[])
{
  return TestRunner::RunAllTests(argc, argv);
}
