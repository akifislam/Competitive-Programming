//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-13 10:56:24

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

    //5 ; L =5 R = 8

    //5 1 2 4 3
    // 1 2 3 4 5
    // Each one can maximum make (n-1) pair

    ll n, l, r;
    cin >> n >> l >> r;

    vector<ll> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(All(vec));

    //Process
    ll answer = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << "For " << i + 1 << " :" << endl;

        ll boundary_left = l - vec[i];
        ll boundary_right = r - vec[i];

        // cout << "Left Boundary : " << boundary_left << endl;
        // cout << "Right Boundary : " << boundary_right << endl;

        // Now Seach No. of elements between left boundary to right boundary in greater index of i
        ll count_in_range = (upper_bound(vec.begin() + i + 1, vec.end(), boundary_right) - vec.begin() + i + 1) - (lower_bound(vec.begin() + i + 1, vec.end(), boundary_left) - vec.begin() + i + 1);
        // cout << "Found no of elements : " << count_in_range << endl;
        answer += count_in_range;
        // cout << endl;
    }
    cout << answer << endl;
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