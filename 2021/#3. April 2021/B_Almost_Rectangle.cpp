//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-10 20:49:11

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
    int n;
    cin >> n;

    char arr[n][n];

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '*')
            {
                vec.push_back(make_pair(i, j));
            }
        }
    }
    int lastrow = n - 1;
    int firstrow = 0;
    // 2 on Same Row
    if (vec[0].first == vec[1].first)
    {
        if (vec[0].first != firstrow)
        {
            //First Row te Bebostha hobe
            arr[firstrow][vec[1].second] = '*';
            arr[firstrow][vec[0].second] = '*';
        }
        else
        {
            arr[lastrow][vec[1].second] = '*';
            arr[lastrow][vec[0].second] = '*';
        }
    }
    int lastcolumn = n - 1;
    int firstcolumn = 0;

    // 2 on Same Column
    if (vec[0].second == vec[1].second)
    {
        if (vec[0].second != firstcolumn)
        {
            //First Row te Bebostha hobe
            arr[vec[0].first][firstcolumn] = '*';
            arr[vec[1].first][firstcolumn ]= '*';
        }
        else
        {
            arr[vec[0].first][lastcolumn] = '*';
            arr[vec[1].first][lastcolumn] = '*';
        }
    }

    arr[vec[0].first][vec[1].second] = '*';
    arr[vec[1].first][vec[0].second] = '*';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    // cout<<endl;
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