//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-03-08 13:06:53

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
  os << '{';
  for (const auto &x : v)
    os << gap << x;
  return os << '}';
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
  return os << '(' << p.first << gap << p.second << ')';
}

#define ll long long
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve()
{
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test = 1;
  cin >> test;
  while (test--)
  {
    solve();
  }
  return 0;
}