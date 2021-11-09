//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-30 21:38:44

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
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

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
  cerr << ' ' << H;
  dbg_out(T...);
}

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

void solve()
{
  ll N, K;
  cin >> N >> K;

  string str;
  cin >> str;

  ll firstOne = -1, lastOne = -1;

  for (int i = 0; i < N; i++)
  {
    if (str[i] == '1')
    {
      firstOne = i;
      break;
    }
  }

  for (int i = N - 1; i >= 0; i--)
  {
    if (str[i] == '1')
    {
      lastOne = i;
      break;
    }
  }

  ll temp = 0;
  //Filling First K 000s with 1
  for (int i = firstOne - 1; i >= 0 && temp < K; i--)
  {
    str[i] = '1';
    temp++;
  }

  //Filling First K 000s with 1
  temp = 0;

  for (int i = lastOne + 1; i < N && temp < K; i++)
  {
    str[i] = '1';
    temp++;
  }

  if (firstOne == lastOne)
  {
    cout << str << endl;
    return;
  }
  cout << "Now : " << str << endl;

  ll count = 0;
  bool pos = true;

  int i, j, lastin;
  for (i = firstOne; i <= lastOne; i++)
  {
    count = 0;
    lastin = -1;
    
    for (j = i + 1; j <= lastOne; j++)
    {
      if (str[j] == '0')
        count++;
      else
      {
        lastin = j;
        break;
      }
    }
    cout << "Got SubArray from " << i + 1 << " to " << lastin - 1 << endl;
    cout << "Count : " << count << endl;

    if (count >= K * 2)
    {
      temp = 0;
      for (int k = i + 1, l = lastin - 1; k < l && temp < K; k++, l--)
      {
        str[k] = str[l] = '1';
        temp++;
      }
    }
    cout << str << endl;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef AKIF
#endif
  int test = 1;
  // cin>>test;
  while (test--)
  {
    solve();
  }
  return 0;
}