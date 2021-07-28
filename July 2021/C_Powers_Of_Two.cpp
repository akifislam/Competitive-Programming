//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-24 20:30:56

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
vector<ll> power_of_2;
void solve()
{
    ll x = 1;

    for (ll i = 0; x <= 1e9 + 100; i++)
    {
        power_of_2.pb(x);
        x *= 2;
    }
    // cout << power_of_2 << endl;
    ll N, K;
    cin >> N >> K;
    ll SAVE_N = N;
    vector<ll> ans;
    ll count = 0;
    while (K--)
    {
        ll search = N - K;
        ll y = lower_bound(All(power_of_2), search) - power_of_2.begin();
        if (search != power_of_2[y])
            y--;
        ans.pb(power_of_2[y]);
        count += power_of_2[y];
        N -= power_of_2[y];
    }
    if (count == SAVE_N)
    {
        cout << "YES" << endl;
        sort(All(ans));
        for (auto xx : ans)
        {
            cout << xx << " ";
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
}

int32_t main()
{
    clock_t tStart = clock();

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
    // fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    cout<<(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}