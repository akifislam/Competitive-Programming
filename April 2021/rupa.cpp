#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
  os << '{';
  for (const auto &x : v)
    os << " "<< x;

  return os << '}';
}


int main()
{
  //1st STL : Vector

  //(------------0-------vec.end()-1)) ---> vec.end();
  
  vector<int> vec{0,1,2,3,4}; //5 // vec.end() = 0xav901


  int value = 3;
  auto k = upper_bound(vec.begin(), vec.end(), value); //  which has a value not less than val. >=x


  if(k!= vec.end()){
      cout<<k-vec.begin()<<endl;
  }
  else {
    cout<<" Ami nai :) "<<endl;
  }
  
}