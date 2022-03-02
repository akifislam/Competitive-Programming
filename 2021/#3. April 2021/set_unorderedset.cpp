//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-06 20:14:35

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
    int count;
    //Set
    set<int> s;
    count = 50;

    for (int i = 0; i < 50; i++)
    {
        s.insert(count);
        count--;
    }

    //Set Print
    cout << "Printing Set" << endl;
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    //Unordered Set
    unordered_set<int> us;

    count = 50;

    for (int i = 0; i < 50; i++)
    {
        us.insert(count);
        count--;
    }

    //Unordered Set Print
    cout << "Printing Unordered Set" << endl;
    for (auto x : us)
    {
        cout << x << " ";
    }
    cout << endl;

    count = 50;
    for (int i = 0; i < 50; i++)
    {
        us.insert(count);
        count--;
    }

    //MultiSet

    multiset<int> ms;

    count = 50;

    for (int i = 0; i < 50; i++)
    {
        ms.insert(count);
        count--;
    }
    count = 50;
    for (int i = 0; i < 50; i++)
    {
        ms.insert(count);
        count--;
    }

    // MultiSet Print
    cout << "Printing Multi Set" << endl;
    for (auto x : ms)
    {
        cout << x << " ";
    }
    cout << endl;

    //Unordered Multiset

    unordered_multiset<int> ums;

    count = 50;

    for (int i = 0; i < 50; i++)
    {
        ums.insert(count);
        count--;
    }
    count = 50;
    for (int i = 0; i < 50; i++)
    {
        ums.insert(count);
        count--;
    }



    // MultiSet Print
    cout << "Printing Unordered Multi Set" << endl;
    for (auto x : ums)
    {
        cout << x << " ";
    }
    cout << endl;

    cout<<ums.count(1)<<endl;
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