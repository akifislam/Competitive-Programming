//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-18 22:13:40

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

void solve()
{
    ll N;
    cin >> N;
    vector<ll> vec;

    ll input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        vec.pb(input);
    }

    sort(All(vec));

    if (N < 3)
    {
        for (auto x : vec)
            cout << x << " ";
        cout << endl;
        return;
    }

    ll dif = 1e9 + 5;
    ll ind = 0;

    for (int i = 1; i < N; i++)
    {
        if ((vec[i] - vec[i - 1]) < dif)
        {
            dif = vec[i] - vec[i - 1];
            ind = i;
        }
    }

    //Print
    for (int i = ind; i < N; i++)
    {
        cout << vec[i] << " ";
    }
    for (int i = 0; i < ind; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
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