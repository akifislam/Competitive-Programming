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

vector<ll> power_of_2;

void solve()
{
    ll x = 1;

    for (ll i = 0; x <= 1e9 + 100; i++)
    {
        power_of_2.pb(x);
        x *= 2;
    }

    ll N;
    cin >> N;
    ll count = 0;

    while (N != 0)
    {
        ll search = N;
        ll y = lower_bound(All(power_of_2), search) - power_of_2.begin();
        if (search != power_of_2[y])
            y--;
        N -= power_of_2[y];
        count++;
    }
    cout << count << endl;
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