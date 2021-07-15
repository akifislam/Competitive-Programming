//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-10 21:01:00

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
    ll x1, y1;
    ll x2, y2;
    ll o1, o2;

    cin >> x1 >> y1 >> x2 >> y2 >> o1 >> o2;

    ll X = abs(x1 - x2);
    ll Y = abs(y1 - y2);

    if (X == 0 && Y == 0)
    {
        cout << 0 << endl;
    }

    else if (X != 0 && Y != 0)
    {
        cout << X + Y << endl;
    }
    else
    {
        // cout << "H" << endl;
        if (X == 0)
        {
            ll lower = min(y1, y2);
            ll higher = max(y1, y2);
            if (o2 > lower && o2 < higher && o1 == x1)
                cout << X + Y + 2 << endl;
            else
                cout << X + Y << endl;
        }

        else
        {
            ll lower = min(x1, x2); //1
            ll higher = max(x1, x2); //3
            if (o1 > lower && o1 < higher && o2 == y1)
                cout << X + Y + 2 << endl;
            else
                cout << X + Y << endl;
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
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}