//Playing PUBG and Coding -_-
//Silly Mistake

//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-27 20:56:30

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

// ll x, y, n;

// 2 --- 1 + 3
// 3 --- 2 -1
// ll DP(ll q)
// {
//     if (q == 1)
//         return x;
//     else if (q == 2)
//         return y;

//     else if (q == 3)
//     {
//         return (DP(q - 1) - DP(q - 2));
//     }
//     return -1;
// }

void solve()
{
    ll x, y, n;
    cin >> x >> y >> n;

    ll answer = 0LL;
    if (n % 6 == 1)
    {
        answer = x;
    }
    else if (n % 6 == 2)
    {
        answer = y;
    }
    else if (n % 6 == 3)
    {
        answer = y - x;
    }
    if (n % 6 == 4)
    {
        answer = -x;
    }
    else if (n % 6 == 5)
    {
        answer = -y;
    }
    else if (n % 6 == 0)
    {
        answer = (-(y - x));
    }
    ll mod = 1000000007LL;
    // (1000000007)
    // (1000000007)

    answer = answer % mod;

    if (answer < 0LL)
    {
        answer += mod;
    }

    cout << answer << endl;

    // f[1] = x;
    // f[2] = y;
    // f[3] = y - x;
    // f[4] = -x;
    // f[5] = -y;
    // f[0] = x - y;
    // long long nr = f[n % 6] % (1000000007);
    // if (nr < 0)
    //     nr = 1000000007 + nr;
    // cout << nr;
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