#include <bits/stdc++.h>
using namespace std;

int main()
{
  unordered_set<int> s;
  int input; 
  input = 0;

 for (int i = 0; i < 50; i++)
 {
   s.insert(input++);
 }
 

  for (auto it = s.begin(); it!= s.end(); it++)
  {
    cout<<*it<<" ";
  }

  // Policy Based Data Structure
  // O
   
}