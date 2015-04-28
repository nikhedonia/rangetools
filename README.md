# itertools
[c++11] functional library for iterators, ranges and generators

#Examples:
```c

for(auto i : range(1,10) ){
  cout<<i<<endl; // 1...9
};

vector<int> vec={...};
for(auto i : reverse(vec) ){ ... }

for(auto i: enumerate(vec) ){
  cout<< i.num << i.val << endl;
}

//...

for( auto i: zip(vec1,vec2) ){
  cout<< get<0>(i) << get<1>(i) << endl;
}

//...
auto myRange = map(vec,[](auto i){ return i*2; });
for( auto i : myRange ){...}

```

