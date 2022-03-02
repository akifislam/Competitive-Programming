//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-12 21:30:58

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
    ll a, b, c;
    cin >> a >> b >> c;

    if (c == 1)
    {
        for (int i = 0; i < a; i++)
        {
            cout << 1;
        }
        cout << " ";

        for (int i = 0; i < b - 1; i++)
        {
            cout << 1;
        }
        cout << "2" << endl;
        ;
    }

    else
    {
        //X Formation
        ll x;
        ll w = 1;
        x = 0;
        ll temp = c;
        // int temp = c;
        // int w = 1;
        while (temp--)
        {
            x += 1 * w;
            w *= 10;
        }

        // cout<<"Formed X : "<<x<<endl;
        ll p = x * (ll)pow(10, a - c) + 2 * x;
        ll q = x * (ll)pow(10, b - c) + x;
        cout << p << " " << q << endl;
        // cout << "GCD Checker : " << __gcd(p, q) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}