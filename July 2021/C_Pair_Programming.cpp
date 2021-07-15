//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-10 21:59:44

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
    ll k, n, m;
    cin >> k >> n >> m;

    vector<ll> A(n);
    vector<ll> B(m);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    vector<ll> ans;

    for (int i = 0; i < max(n, m); i++)
    {
        if (i < A.size() && i < B.size())
        {
            ll mini = min(A[i], B[i]);
            ll maxi = max(A[i], B[i]);
            ans.pb(mini);
            ans.pb(maxi);
        }
        else
        {
            if (i < A.size())
                ans.pb(A[i]);
            else
                ans.pb(B[i]);
        }
    }
    // cout << ans << endl;

    ll cur_pages = k;
    bool isPossible = true;

    for (int i = 0; i < n + m; i++)
    {
        if (ans[i] == 0)
            cur_pages++;

        else if (ans[i] > cur_pages)
        {
            isPossible = false;
            break;
        }
    }

    if (isPossible)
    {
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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