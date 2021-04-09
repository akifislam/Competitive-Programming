//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-09 17:54:55

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
    int n, c0 = 0, c1 = 0, c2 = 0, ave, ans = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 3 == 0)
            c0++;
        else if (arr[i] % 3 == 1)
            c1++;
        else if (arr[i] % 3 == 2)
            c2++;
    }

    ave = (c0 + c1 + c2) / 3;
    if (c0 > ave)
    {
        int c0excess = c0 - ave;
        ans += c0excess;
        c1 += c0excess;
    }
    else
    {
        int c0less = ave - c0;
        ans += c0less;
        c2 -= c0less;
    }
    if (c1 > ave)
    {
        int c1excess = c1 - ave;
        ans += c1excess;
        c2 += c1excess;
    }
    else
    {
        int c1less = ave - c1;
        ans += c1less;
        c0 -= c1less;
    }
    if (c2 > ave)
    {
        int c2excess = c2 - ave;
        ans += c2excess;
        c0 += c2excess;
    }
    else
    {
        int c2less = ave - c2;
        ans += c2less;
        c1 -= c2less;
    }
    cout << ans << endl;
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