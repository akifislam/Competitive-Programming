//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-07 11:51:43

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

    map<string, int> mp;
    unordered_map<string, int> ump;

    mp.insert({"B", 12});
    mp.insert({"C", 1});
    mp.insert({"E", 11});
    mp.insert({"A", 35});
    mp.insert({"D", 5});

    ump.insert({"B", 12});
    ump.insert({"C", 1});
    ump.insert({"E", 11});
    ump.insert({"A", 35});
    ump.insert({"D", 5});

    //Print Map
    cout << "Printing Map" << endl;
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    //Print Map
    cout << "Printing Unordered Map" << endl;
    for (auto x : ump)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}