# RangeTools
[c++14] functional library for iterators, ranges and generators

# Description:
RangeTools is a functional template library for flow based programming.
Its main goal is empowering the user to easily write generic and chainable functions for sequencial data-streams.

#Examples:
```c++

for(auto i : range(10) ){
  cout<<i<<endl; // 0...9
};

vector<int> v{1,2,3,4,5,6,7,8,9,10};
auto log = each([](auto x){ cout << "log"<<x << endl }); // print forEach e in stream
for(auto i : gen*v // make a generator from a container
           | log  //1,2,3,4,5,6,7,8,9,10
           | map([](auto x){ return x*2; }) // mult every elem in stream with 2
           | drop([](auto x){ return x%3; }) // filter-out if not divisable
           | log //6,12,18
           | takeWhile([](auto x){ return x<16; }) )
           | log //6,12
{  
  //do sth with i //
}

struct Fib{ // infinite sequence
  int a;
  int b;
  auto done(){ return 0; } // optional // never done
  auto value(){ return b; }
  auto next(){ int c=a+b; a=b; b=c; }  
};

for(auto i : gen*Fib{0,1}
           | log
         //| you know the drill
){

} 

```

# how it works

## generators

a generator is any structure which provides these methods which are repeatly called in that order:
- bool done(auto prev)  : tells if generator is done
- auto value(auto prev) : returns current value
- auto next(auto prev)  : prepares next element / advances iterator

prev is optional and is the previous generator in the chain

### generator model

any object which provides at least one of this functions or begin/end functions can be made to an generator
by using the 'gen*' functor  
If done/value/next is missing or cant accept a generator, a default implementation is used:

### default behaviour:
- done()     : returns always 0
- done(auto) : returns prev.done() || this->done()
- next()     : does nothing
- next(auto) : prev.next() && this->next();
- value(): returns 0;
- value(auto): returns value();

## operator |
combines two generators




