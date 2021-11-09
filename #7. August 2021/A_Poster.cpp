//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-08-11 20:10:12

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

void solve()
{
    ll n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    ll dist_to_left = k;
    ll dist_to_right = n - k;

    if (dist_to_left <= dist_to_right)
    {
        while (k != 1)
        {
            k--;
            cout << "LEFT" << endl;
        }
    }
    else
    {
        while (k != n)
        {
            k++;
            cout << "RIGHT" << endl;
        }
    }

    if (k == 1)
    {
        cout << "PRINT " << str[0] << endl;

        for (int i = 1; i < n; i++)
        {
            cout << "RIGHT" << endl;
            cout << "PRINT " << str[i] << endl;
        }
    }

    else
    {
        cout << "PRINT " << str[n - 1] << endl;

        for (int i = n - 2; i >= 0; i--)
        {
            cout << "LEFT" << endl;
            cout << "PRINT " << str[i] << endl;
        }
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